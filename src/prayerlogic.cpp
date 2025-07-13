#include "prayerlogic.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>


using json = nlohmann::json;
namespace fs =  std::filesystem;

std::string prayerlogic::run_py_command(const std::vector<std::string> tokens)
{
    std::string command = "python3 fetchdata.py " + tokens[1] + " " + tokens[2];
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

