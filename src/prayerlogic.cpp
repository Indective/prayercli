#include "prayerlogic.h"
#include "audioplayer.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <cstdlib>

using json = nlohmann::json;
namespace fs =  std::filesystem;
audioplayer audio;

std::string prayerlogic::run_py_command(const std::vector<std::string> tokens)
{
    std::string command = "python3 fetchdata.py " + tokens[2] + " " + tokens[3];
    std::array<char, 128> buffer;
    std::string result;

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

    pclose(pipe);

    return result;
}

std::map<std::string, std::string> prayerlogic::parse_python_data(const std::vector<std::string> tokens)
{
    std::string result = run_py_command(tokens);
    json j = json::parse(result);
    std::map<std::string, std::string> prayertimes = {
        {"Fajr",j["Fajr"]},
        {"Dhuhr",j["Dhuhr"]},
        {"Asr",j["Asr"]},
        {"Maghrib",j["Maghrib"]},
        {"Isha",j["Isha"]}
    };
    return prayertimes;
}

void prayerlogic::display_data(const std::vector<std::string> tokens)
{
    std::map<std::string,std::string> prayertimes = parse_python_data(tokens);
    for (auto &i : prayertimes)
    {
        std::cout << i.first << "  -  " << i.second << std::endl;
    }
}

void prayerlogic::random_hadith(const std::vector<Hadith> hadiths)
{
    int random = (rand() % hadiths.size()) + 1;
    auto hadith = hadiths.at(random);
    std::cout << hadith.text << std::endl;
    std::cout << hadith.source << std::endl;
}

void prayerlogic::clearscreen()
{
    #ifdef _WIN32
        if (std::getenv("TERM")) {
            std::cout << "\033[2J\033[H" << std::flush;
        } else {
            system("cls");
        }
    #else
        std::cout << "\033[2J\033[H" << std::flush;
    #endif  
}

void prayerlogic::excute_commands(const std::vector<std::string> tokens, const std::vector<Hadith> hadiths)
{
    if(tokens[1] == "prayertimes") {display_data(tokens);}
    else if(tokens[1] == "hadith") {random_hadith(hadiths);}
    else if(tokens[1] == "cls") {clearscreen();}
    else if(tokens[1] == "exit") {exit(0);}
    else if(tokens[1] == "ruqia") {audio.play_ruqia();}
    else if(tokens[1] == "morning") {audio.play_morning_athkar();}
}
