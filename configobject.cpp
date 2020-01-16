#include "configobject.hpp"

namespace Airspace
{

ConfigObject::ConfigObject(libconfig::Setting& setting)
{
    pSetting = &setting;
}

ConfigObject::~ConfigObject()
{
}

void ConfigObject::test1()
{
    std::cout << "Type: " << pSetting->getType() << std::endl;

}


bool ConfigObject::init(std::string path, const char **argv, int argc)
{

    return true;
}

void ConfigObject::cfg_term()
{

}

// ..................................................................... cfg_err
//
void ConfigObject::cfg_err(const char **file, int *line, const char **msg)
{
   
}

void ConfigObject::cfg_err_print_msg()
{
   
}

// ............................................................... cfg_parse_arg
//
std::string  ConfigObject::cfg_parse_arg(std::string str,  std::string key)
{
    return "";
}

// .............................................................. cfg_lookup_arg
//
std::string ConfigObject::cfg_lookup_arg(std::string key)
{
    return "";
}


// ............................................................... get_value
//

bool  ConfigObject::cfg_get_value( std::string key, void *val, cfg_type_e type)
{
    bool ok = false;

    switch (type)
    {
    case CFG_TYPE_INT:
        ok = cfg_get_value(key, *(int *)val);
        break;
    case CFG_TYPE_INT64:
        ok = cfg_get_value(key, *(long long *)val);
        break;
    case CFG_TYPE_DOUBLE:
        ok = cfg_get_value(key, *(double *)val);
        break;
    case CFG_TYPE_BOOL:
        ok = cfg_get_value(key, *(bool *)val);
        break;
    case CFG_TYPE_STRING:
        ok = cfg_get_value(key, *(std::string *)val);
        break;
    default:
        break;
    }

    return ok;
}

bool  ConfigObject::cfg_get_value(cfg_entry_t *entry)
{
    if (entry == NULL)
        return false;
    return cfg_get_value(entry->key, entry->val, entry->type);
    
}


bool ConfigObject::cfg_get_value(std::string key, int &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, long long &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, double &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, bool &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, const char *&value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, const char *&value, int index)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, unsigned int &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, float &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, std::string &value)
{
    bool ok = pSetting->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }
    return ok;
}


// .................................................................. get value array
//

bool ConfigObject::cfg_get_value(std::string key, int index, int &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, int index, long long &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, int index, double &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, int index, bool &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}

bool ConfigObject::cfg_get_value(std::string key, int index, const char *&value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, int index, unsigned int &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, int index, float &value)
{
    bool ok = false;
    try{
        value = (*pSetting)[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}


bool ConfigObject::cfg_get_value(std::string key, int index, std::string &value)
{
    bool ok = false;
    try{
        std::string temp = (*pSetting)[index];
        value = temp;
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find value!" << std::endl;
        ok = false;
    }

    return ok;
}


}// namespace Airspace