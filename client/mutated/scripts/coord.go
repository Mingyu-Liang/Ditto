package main

import (
	"bufio"
	"errors"
	"flag"
	"fmt"
	"io"
	"net"
	"os"
	"sort"
	"strconv"
)

func checkError(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
		os.Exit(1)
	}
}

type cfg struct {
	samples    uint
	reqsPerSec uint
	conns      uint

	timePad     uint
	mode        string
	dist        string
	host        string
	serviceTime uint
}

func divCfg(c *cfg, cnt uint) []*cfg {
	split := &cfg{c.samples / cnt, c.reqsPerSec / cnt, c.conns / cnt,
		      c.timePad, c.mode, c.dist, c.host, c.serviceTime}

	cfgs := make([]*cfg, cnt)

	for i := range cfgs {
		cfgs[i] = new(cfg)
		*cfgs[i] = *split

		if i < int(c.samples%cnt) {
			cfgs[i].samples += 1
		}

		if i < int(c.reqsPerSec%cnt) {
			cfgs[i].reqsPerSec += 1
		}

		if i < int(c.conns%cnt) {
			cfgs[i].conns += 1
		}
	}

	return cfgs
}

type result struct {
	offeredReqsPerSec  uint
	measuredReqsPerSec float64
	samples            []int
}

func NewResult(sampleCount uint) *result {
	r := new(result)
	r.samples = make([]int, sampleCount)
	return r
}

func (r *result) mean() float64 {
	accum := int64(0)
	for _, val := range r.samples {
		accum += int64(val)
	}

	return float64(accum) / float64(len(r.samples))
}

func (r *result) percentile(frac float64) int {
	if !sort.IntsAreSorted(r.samples) {
		sort.Ints(r.samples)
	}

	idx := int(frac * float64(len(r.samples)-1))
	return r.samples[idx]
}

func (r *result) accum(a *result) {
	r.offeredReqsPerSec += a.offeredReqsPerSec
	r.measuredReqsPerSec += a.measuredReqsPerSec
	r.samples = append(r.samples, a.samples...)
}

func (r *result) display() {
	fmt.Printf("%d %f %d %f %d %d %d %d\n",
		r.offeredReqsPerSec, r.measuredReqsPerSec,
		r.percentile(0.0), r.mean(),
		r.percentile(0.99), r.percentile(0.999),
		r.percentile(0.9999), r.percentile(1.0))
}

func measureOne(c *cfg, host string, cmd string) (*result, error) {
	conn, err := net.Dial("tcp", host)
	if err != nil {
		return nil, err
	}
	defer conn.Close()

	arg := fmt.Sprintf("spawn %s -r -e -w %d -c %d -s %d -m %s -d %s -n %d %s %d %d\n",
		cmd, c.timePad, c.timePad, c.samples, c.mode,
		c.dist, c.conns, c.host, c.serviceTime, c.reqsPerSec)

	if _, err = io.WriteString(conn, arg); err != nil {
		return nil, err
	}

	ans := NewResult(c.samples)
	scanner := bufio.NewScanner(conn)

	ans.offeredReqsPerSec = c.reqsPerSec
	firstLine := scanner.Scan()
	if firstLine == true {
		v, err := strconv.ParseFloat(scanner.Text(), 64)
		if err != nil {
			return nil, err
		}
		ans.measuredReqsPerSec = v
	}

	i := uint(0)
	for scanner.Scan() {
		v, err := strconv.ParseInt(scanner.Text(), 10, 32)
		if err != nil {
			return nil, err
		}

		ans.samples[i] = int(v)
		i += 1

		if i >= c.samples {
			break
		}
	}

	if err = scanner.Err(); err != nil {
		return nil, err
	}

	if i != c.samples {
		return nil, errors.New("Not enough samples")
	}

	return ans, nil
}

func measure(c *cfg, host string, cmd string, cnt uint) *result {
	r := NewResult(0)
	cResult := make(chan *result)
	dCfg := divCfg(c, cnt)

	for _, v := range dCfg {
		go func(v *cfg) {
			part, err := measureOne(v, host, cmd)
			checkError(err)
			cResult <- part
		}(v)
	}

	for i := uint(0); i < cnt; i++ {
		part := <-cResult
		r.accum(part)
	}

	return r
}

func warmup(c *cfg, host string, cmd string) error {
	wc := &cfg{100, 100, 1, 3, "round_robin", "exp", c.host, 1}

	_, err := measureOne(wc, host, cmd)
	return err
}

func doExperiment(c *cfg, host string, cmd string, cnt uint, steps uint) {
	maxReqsPerSec := c.reqsPerSec

	err := warmup(c, host, cmd)
	checkError(err)

	for i := uint(1); i <= steps; i++ {
		c.reqsPerSec = (maxReqsPerSec * i) / steps
		r := measure(c, host, cmd, cnt)
		r.display()
	}
}

func usage() {
	fmt.Fprintf(os.Stderr, "usage: coord [options] <measure_ip:port> "+
		"<service_us> <generator_ip> <generator_path>"+
		"<generator_count> <max_req_rate> <steps>\n")
	flag.PrintDefaults()
	os.Exit(2)
}

func main() {
	baseCfg := cfg{}

	flag.Usage = usage

	flag.UintVar(&baseCfg.samples, "s", 10000, "Samples")
	flag.UintVar(&baseCfg.conns, "n", 120, "Number of connections")
	flag.UintVar(&baseCfg.timePad, "w", 2, "Warm up and cool down padding time")
	flag.StringVar(&baseCfg.mode, "m", "round_robin", "Connection mode")
	flag.StringVar(&baseCfg.dist, "d", "exp", "Service time distribution")
	flag.Parse()

	baseCfg.host = flag.Arg(0)
	if baseCfg.host == "" {
		fmt.Println("Missing <measure_ip:port>")
		usage()
	}

	v, err := strconv.ParseUint(flag.Arg(1), 10, 32)
	if err != nil {
		fmt.Println("Invalid <service_us> argument")
		usage()
	}
	baseCfg.serviceTime = uint(v)

	generatorHost := flag.Arg(2)
	if generatorHost == "" {
		fmt.Println("Missing <generator_ip>")
		usage()
	}

	generatorPath := flag.Arg(3)
	if generatorPath == "" {
		fmt.Println("missing <generator_path>")
		usage()
	}

	generatorCount, err := strconv.ParseUint(flag.Arg(4), 10, 32)
	if err != nil || generatorCount == 0 {
		fmt.Println("Invalid <generator_count> argument")
		usage()
	}

	v, err = strconv.ParseUint(flag.Arg(5), 10, 32)
	if err != nil {
		fmt.Println("Invalid <max_req_rate> argument")
		usage()
	}
	baseCfg.reqsPerSec = uint(v)

	steps, err := strconv.ParseUint(flag.Arg(6), 10, 32)
	if err != nil {
		fmt.Println("Invalid <steps> argument")
		usage()
	}

	doExperiment(&baseCfg, generatorHost, generatorPath,
		uint(generatorCount), uint(steps))
}

