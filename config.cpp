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
        pcfg = &cfg;
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

// ............................................................... cfg_parse_arg
//
std::string  Config::cfg_parse_arg(std::string str,  std::string key)
{
    return "";
}

// .............................................................. cfg_lookup_arg
//
std::string Config::cfg_lookup_arg(std::string key)
{
    return "";
}


// ............................................................... get_value
//

bool  Config::cfg_get_value( std::string key, void *val, cfg_type_e type)
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

bool  Config::cfg_get_value(cfg_entry_t *entry)
{

    if (entry == NULL)
        return false;
    return cfg_get_value(entry->key, entry->val, entry->type);
    
}


bool Config::cfg_get_value(std::string key, int &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find int value for [" << key << "]" << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, long long &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find long long value for [" << key << "]" << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, double &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find double value for [" << key << "]" << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, bool &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find bool value for [" << key << "]" << std::endl;
    }
    return ok;
}

bool Config::cfg_get_value(std::string key, const char *&value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find const char* value for [" << key << "]" << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, const char *&value, int index)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
        ok = true;
        std::cout << value << std::endl;
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cout << "Cannot find const char* value with index for [" << key << "]" << std::endl;
        ok = false;
    }

    return ok;
}


bool Config::cfg_get_value(std::string key, unsigned int &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find unsigned int value for [" << key << "]" << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, float &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find float value for [" << key << "]" << std::endl;
    }
    return ok;
}


bool Config::cfg_get_value(std::string key, std::string &value)
{
    bool ok = pcfg->lookupValue(key, value);
    if (ok)
    {
        std::cout << value << std::endl;
    }else{
        std::cout << "Cannot find string value for [" << key << "]" << std::endl;
    }
    return ok;
}


/*
// .................................................................. get value array from int index
//

bool Config::cfg_get_value(std::string key, int index, int &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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


bool Config::cfg_get_value(std::string key, int index, long long &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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

bool Config::cfg_get_value(std::string key, int index, double &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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

bool Config::cfg_get_value(std::string key, int index, bool &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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

bool Config::cfg_get_value(std::string key, int index, const char *&value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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


bool Config::cfg_get_value(std::string key, int index, unsigned int &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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


bool Config::cfg_get_value(std::string key, int index, float &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index];
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


bool Config::cfg_get_value(std::string key, int index, std::string &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        std::string temp = setting[index];
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

// .................................................................. get value array from name index
//

bool Config::cfg_get_value(std::string key, std::string index, int &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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


bool Config::cfg_get_value(std::string key, std::string index, long long &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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

bool Config::cfg_get_value(std::string key, std::string index, double &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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

bool Config::cfg_get_value(std::string key, std::string index, bool &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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

bool Config::cfg_get_value(std::string key, std::string index, const char *&value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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


bool Config::cfg_get_value(std::string key, std::string index, unsigned int &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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


bool Config::cfg_get_value(std::string key, std::string index, float &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        value = setting[index.c_str()];
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


bool Config::cfg_get_value(std::string key, std::string index, std::string &value)
{
    bool ok = false;
    try{
        libconfig::Setting& setting = pcfg->lookup(key);
        std::string temp = setting[index.c_str()];
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
*/
// .................................................................. misc
//

bool Config::cfg_get_value(std::string key, std::vector<std::shared_ptr<ConfigObject>> &childSetting)
{
    bool ok = false;

    libconfig::Setting& settings = pcfg->lookup(key);
    int count = settings.getLength();

    for(int i = 0; i < count; ++i)
    {
        libconfig::Setting& setting = settings[i];
        std::shared_ptr<ConfigObject> test = std::make_shared<ConfigObject>(setting);

        childSetting.push_back(test);
    }

    return ok;
}
/*
void Config::determine_setting(std::string key)
{
    const libconfig::Setting& setting = pcfg->lookup(key);
    std::cout << "Type: " << setting.getType() << std::endl;
}


void Config::test(std::string key)
{
    const libconfig::Setting& setting = pcfg->lookup(key);
    setting1 = &setting;
    std::cout << "Type: " << setting1->getType() << std::endl;
    std::string temp = (*setting1)[0];
    std::cout << "Value: " << temp << std::endl;

}

void Config::test1()
{
    std::string temp = (*setting1)[0];
    std::cout << "Value1: " << temp << std::endl;

}

void Config::createConfigObject(std::string key)
{
    libconfig::Setting& setting = pcfg->lookup(key);
    ConfigObject test = ConfigObject(setting);
    test.test1();
    //std::string temp2;
    //test.cfg_get_value(key, 0, temp2);
}
*/
}// namespace Airspace