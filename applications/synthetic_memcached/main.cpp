#include "./config.h"

int main(int argc, char *argv[])
{
    Config config;
    config.ParseArg(argc, argv);

    Service service;
    service.Init(config.service_port, config.network_thread_number, config.accept_thread_number);

    service.EventListen();
    service.EventLoop();

    return 0;
}