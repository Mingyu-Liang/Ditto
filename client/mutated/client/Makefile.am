AM_CPPFLAGS = -D_REENTRANT
LDADD = -lpthread

bin_PROGRAMS = mutated_synthetic mutated_memcache load_memcache test1

mutated_synthetic_SOURCES = \
    mutated_synthetic.cc \
	accum.hh accum.cc \
	client.hh client.cc \
	generator.hh \
	gen_synthetic.hh gen_synthetic.cc \
	gen_memcache.hh gen_memcache.cc \
	opts.hh opts_synthetic.cc opts_memcache.cc \
	socket_buf.hh socket_buf.cc \
	util.hh

mutated_memcache_SOURCES = \
    mutated_memcache.cc \
	accum.hh accum.cc \
	client.hh client.cc \
	generator.hh \
	gen_synthetic.hh gen_synthetic.cc \
	gen_memcache.hh gen_memcache.cc \
	opts.hh opts_synthetic.cc opts_memcache.cc \
	socket_buf.hh socket_buf.cc \
	util.hh

# We don't compile the following files:
#   socket_vec.hh socket_vec.cc
# as they provide an older, conflicting implementation of the Sock class. We
# leave present though as it's still useful code.

load_memcache_SOURCES = \
    load_memcache.hh load_memcache.cc \
	socket_buf.hh socket_buf.cc \
	util.hh

test1_SOURCES = test1.cc
