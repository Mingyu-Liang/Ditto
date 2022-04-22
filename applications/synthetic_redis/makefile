CXX ?= g++

CXXFLAGS += -g -masm=intel -lpthread -DNETWORKEPOLL

server: main.cpp ./connection/tcp_conn.cpp service.cpp config.cpp utils.cpp assembly.cpp
	$(CXX) -o syn_redis  $^ $(CXXFLAGS)

clean:
	rm  -r syn_redis
