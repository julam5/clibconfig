#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <memory>
#include <libconfig.h++>
#include <vector>

#include "configobject.hpp"

namespace Airspace
{
/*
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
*/
class Config {
    private:
        libconfig::Config cfg;
        //libconfig::Config* pcfg;

        //const libconfig::Setting* setting1;

    public:
        Config();
        ~Config();

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
/*
        //get value from array from int index
        bool cfg_get_value( std::string key, int index, int &value);
        bool cfg_get_value( std::string key, int index, long long &value);
        bool cfg_get_value( std::string key, int index, double &value);
        bool cfg_get_value( std::string key, int index, bool &value);
        bool cfg_get_value( std::string key, int index, const char *&value);
        bool cfg_get_value( std::string key, int index, unsigned int &value);
        bool cfg_get_value( std::string key, int index, float &value);
        bool cfg_get_value( std::string key, int index, std::string &value);

        //get value from array name index
        bool cfg_get_value( std::string key, std::string index, int &value);
        bool cfg_get_value( std::string key, std::string index, long long &value);
        bool cfg_get_value( std::string key, std::string index, double &value);
        bool cfg_get_value( std::string key, std::string index, bool &value);
        bool cfg_get_value( std::string key, std::string index, const char *&value);
        bool cfg_get_value( std::string key, std::string index, unsigned int &value);
        bool cfg_get_value( std::string key, std::string index, float &value);
        bool cfg_get_value( std::string key, std::string index, std::string &value);
*/
        bool cfg_get_value( std::string key, std::vector<std::shared_ptr<ConfigObject>> &childSetting);
/*
        void determine_setting(std::string key);
        void test(std::string key);
        void test1();

        void createConfigObject(std::string key);
*/

};// Config class
}// namespace Airspace

#endif