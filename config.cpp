#include "config.hpp"

namespace Airspace
{

Config::Config(/* args */)
{
}

Config::~Config()
{
}

bool Config::init(std::string path, const char **argv, int argc)
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

void Config::cfg_term()
{

}

// ..................................................................... cfg_err
//
void Config::cfg_err(const char **file, int *line, const char **msg)
{
   
}

void Config::cfg_err_print_msg()
{
   
}

// ............................................................... get_value
//
bool Config::cfg_get_value(std::string key, int &value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, std::string &value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, long long &value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, double &value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, bool &value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, const char *&value)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, const char *&value, int index)
{
    bool ok = cfg.lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}





}// namespace Airspace