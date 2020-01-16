#include<chrono>
#include <thread>
#include <iostream>
#include <string>
#include "config.hpp"
#include "configobject.hpp"

int main(int argc, const char *argv[])
{

    Airspace::Config* config  = new Airspace::Config();
    config->init("sample.cfg", argv, argc);

    int int_test;
    long long long_test;
    double double_test;
    bool bool_test;
    unsigned int unsigned_test;
    float float_test;
    const char * char_test;
    std::string string_test;


    config->cfg_get_value("integer_test", int_test);
    config->cfg_get_value("longlong_int_test", long_test);
    config->cfg_get_value("double_float", double_test);
    config->cfg_get_value("bool_test", bool_test);
    config->cfg_get_value("unsigned_integer_test", unsigned_test);
    config->cfg_get_value("float_test", float_test);
    config->cfg_get_value("string_ex_a", char_test);
    config->cfg_get_value("string_ex_b", string_test);
    config->cfg_get_value("string_list_ex", char_test, 2);


    std::vector<std::shared_ptr<Airspace::ConfigObject>> columns;
    config->cfg_get_value("inventory.movies", columns);

    for(int i = 0; i < columns.size(); i++)
    {
        float titleString;
        columns[i]->cfg_get_value("price", titleString);
    }
    
}