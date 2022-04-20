
default:	build

clean:
	rm -rf Makefile objs

.PHONY:	default clean

build:
	$(MAKE) -f objs/Makefile

install:
	$(MAKE) -f objs/Makefile install

modules:
	$(MAKE) -f objs/Makefile modules

upgrade:
	/filer-01/ml2585/Ditto/applications/nginx-1.20.1/build/sbin/nginx -t

	kill -USR2 `cat /filer-01/ml2585/Ditto/applications/nginx-1.20.1/build/logs/nginx.pid`
	sleep 1
	test -f /filer-01/ml2585/Ditto/applications/nginx-1.20.1/build/logs/nginx.pid.oldbin

	kill -QUIT `cat /filer-01/ml2585/Ditto/applications/nginx-1.20.1/build/logs/nginx.pid.oldbin`

.PHONY:	build install modules upgrade
