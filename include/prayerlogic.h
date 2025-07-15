#ifndef PRAYERLOGIC_h
#define PRAYERLOGIC_h

#include<iostream>
#include <map>
#include <vector>
#include <string>

struct Hadith
{
    std::string text;
    std::string source;
};

class prayerlogic
{
private:
    std::string run_py_command(const std::vector<std::string> tokens);
    std::map<std::string,std::string> parse_python_data(const std::vector<std::string> tokens);
public:
    void display_data(const std::vector<std::string> tokens);
    void random_hadith(const std::vector<Hadith> hadiths);
};



#endif
