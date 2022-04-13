CXX ?= g++

CXXFLAGS += -g -masm=intel -lpthread

server: main.cpp ./connection/tcp_conn.cpp service.cpp config.cpp utils.cpp assembly.cpp
	$(CXX) -o network_skeleton  $^ $(CXXFLAGS)

clean:
	rm  -r network_skeleton
