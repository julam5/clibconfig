#ifndef CONFIGOBJECTS_H
#define CONFIGOBJECTS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h++>



namespace Airspace
{

typedef enum
{

    CFG_TYPE_INVALID = 0,
    CFG_TYPE_INT = 1,
    CFG_TYPE_INT64,
    CFG_TYPE_DOUBLE,
    CFG_TYPE_BOOL,
    CFG_TYPE_STRING,

} cfg_type_e;

typedef struct
{
     std::string key;
    cfg_type_e type;
    void *val;
    const char *desc;
} cfg_entry_t;

class ConfigObject {
    private:
        libconfig::Setting* pSetting;

    public:

        ConfigObject(libconfig::Setting& setting);
        ~ConfigObject();

        void test1();


        bool init(std::string path, const char **argv, int argc);
        void cfg_term();
        void cfg_err(const char **file, int *line, const char **msg);
        void cfg_err_print_msg();
        std::string  cfg_parse_arg(std::string str,  std::string key);
        std::string cfg_lookup_arg(std::string key);
        bool cfg_get_value(std::string key, void *val, cfg_type_e type);
        bool cfg_get_value(cfg_entry_t *entry);
        bool cfg_get_value( std::string key, int &value);
        bool cfg_get_value( std::string key, long long &value);
        bool cfg_get_value( std::string key, double &value);
        bool cfg_get_value( std::string key, bool &value);
        bool cfg_get_value( std::string key, const char *&value);
        bool cfg_get_value( std::string key, const char *&value, int index);
        bool cfg_get_value( std::string key, unsigned int &value);
        bool cfg_get_value( std::string key, float &value);
        bool cfg_get_value( std::string key, std::string &value);


        //get value from array
        bool cfg_get_value( std::string key, int index, int &value);
        bool cfg_get_value( std::string key, int index, long long &value);
        bool cfg_get_value( std::string key, int index, double &value);
        bool cfg_get_value( std::string key, int index, bool &value);
        bool cfg_get_value( std::string key, int index, const char *&value);
        bool cfg_get_value( std::string key, int index, unsigned int &value);
        bool cfg_get_value( std::string key, int index, float &value);
        bool cfg_get_value( std::string key, int index, std::string &value);
        

};// ConfigObject class
}// namespace Airspace

#endif