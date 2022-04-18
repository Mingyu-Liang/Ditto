#ifndef CONFIG_H
#define CONFIG_H

#include "service.h"

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void ParseArg(int argc, char*argv[]);

    int service_port;
    int network_thread_number;
    int accept_thread_number;
};

#endif