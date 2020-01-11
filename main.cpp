#include<chrono>
#include <thread>
#include <iostream>
#include <string>
#include "clibconfig.hpp"

int main()
{

    Airspace::cLibConfig* config  = new Airspace::cLibConfig();
    config->init("sample.cfg");


}