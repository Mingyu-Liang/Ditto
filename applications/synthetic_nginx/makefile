CXX ?= g++

CXXFLAGS += -g -masm=intel -lpthread -DACCEPTDISPATCH -DNETWORKEPOLL

server: main.cpp ./connection/tcp_conn.cpp service.cpp config.cpp utils.cpp assembly.cpp
	$(CXX) -o syn_nginx  $^ $(CXXFLAGS)

clean:
	rm  -r syn_nginx
