#ifndef PRAYERLOGIC_h
#define PRAYERLOGIC_h

#include<iostream>
#include <map>
#include <vector>

class prayerlogic
{
private:
    /* data */
public:
    std::map<std::string,std::string> parse_python_data(const std::vector<std::string> tokens);
};



#endif
