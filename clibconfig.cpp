#include "clibconfig.hpp"

namespace Airspace
{

cLibConfig::cLibConfig(/* args */)
{
}

cLibConfig::~cLibConfig()
{
}

bool cLibConfig::init(std::string path)
{
    // Read the file. If there is an error, report it and exit.
    try
    {
        cfg.readFile("sample.cfg");
    }
    catch(const libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while reading file." << std::endl;
        //return(EXIT_FAILURE);
        return false;
    }
    catch(const libconfig::ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                << " - " << pex.getError() << std::endl;
        //return(EXIT_FAILURE);
        return false;
    }
    return true;
}




}// namespace Airspace