#include<chrono>
#include <thread>
#include <iostream>
#include <string>
#include "config.hpp"

int main(int argc, const char *argv[])
{

    Airspace::Config* config  = new Airspace::Config();
    config->init("sample.cfg", argv, argc);

    

}