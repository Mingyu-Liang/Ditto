#include "config.h"

Config::Config(){
    service_port = 9016;
    network_thread_number = 1;
    accept_thread_number = 1;
}

void Config::ParseArg(int argc, char*argv[]){
    int opt;
    const char *str = "p:n:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            service_port = atoi(optarg);
            break;
        }
        case 'n':
        {
            network_thread_number = atoi(optarg);
            break;
        }
        case 'a':
        {
            accept_thread_number = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}