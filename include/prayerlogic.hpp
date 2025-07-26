#pragma once

#include<iostream>
#include <map>
#include <vector>
#include <string>

struct Hadith
{
    std::string text;
    std::string source;
};

namespace prayerlogic
{
    void display_data(const std::vector<std::string> tokens);
    void random_hadith(const std::vector<Hadith> hadiths);
    void clearscreen();
    void excute_commands(const std::vector<std::string>& tokens,const std::vector<Hadith> hadiths);
};


