#ifndef CLIBCONFIG_H
#define CLIBCONFIG_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h++>


namespace Airspace
{
class cLibConfig {
    private:
        libconfig::Config cfg;
    public:
        cLibConfig();
        ~cLibConfig();

        bool init(std::string path);
        

};// cLibConfig class
}// namespace Airspace

#endif