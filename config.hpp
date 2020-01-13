#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h++>


namespace Airspace
{
class Config {
    private:
        libconfig::Config cfg;
    public:
        Config();
        ~Config();

        bool init(std::string path, const char **argv, int argc);
        void cfg_term();
        void cfg_err(const char **file, int *line, const char **msg);
        void cfg_err_print_msg();
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
 
    bool cfg_get_value(std::string key, void *val, cfg_type_e type);
    bool cfg_get_value(cfg_entry_t *entry);
    */

};// Config class
}// namespace Airspace

#endif