#ifndef PRAYERLOGIC_h
#define PRAYERLOGIC_h

#include<iostream>
#include <map>
#include <vector>

class prayerlogic
{
private:
    std::string run_py_command(const std::vector<std::string> tokens);
    std::map<std::string,std::string> parse_python_data(const std::vector<std::string> tokens);
public:
    void display_data(const std::vector<std::string> tokens);
};



#endif
