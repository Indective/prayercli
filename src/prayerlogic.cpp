#include "prayerlogic.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <random>

using json = nlohmann::json;
namespace fs =  std::filesystem;

namespace
{
    std::string run_py_command(const std::vector<std::string> tokens)
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

}

namespace
{
    std::map<std::string, std::string> parse_python_data(const std::vector<std::string> tokens)
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

}


void prayerlogic::display_data(const std::vector<std::string> tokens)
{
    std::map<std::string,std::string> prayertimes = parse_python_data(tokens);
    for (auto &i : prayertimes)
    {
        std::cout << i.first << "  -  " << i.second << std::endl;
    }
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

void prayerlogic::random_hadith(const std::vector<Hadith> hadiths)
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, hadiths.size());
    int rand = distrib(gen);
    Hadith hadith = hadiths.at(rand);
    std::cout << hadith.text << std::endl;
    std::cout << hadith.source << std::endl;
}   

void prayerlogic::play_audio(const std::vector<std::string> tokens)
{
    std::string path;
    if (tokens.at(1) == "para")
    {
        path = std::filesystem::current_path().string() + "/Sounds/" + tokens.at(1) + tokens.at(2) +  ".mp3";
    }
    else
    {
        path = std::filesystem::current_path().string() + "/Sounds/" + tokens.at(1) + ".mp3";
    }
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }
    
    music.play();
    std::cout << "Audio playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Audio stopped.\n";

}

void prayerlogic::excute_commands(const std::vector<std::string>& tokens, const std::vector<Hadith> hadiths)
{
    if(tokens[1] == "prayertimes") {display_data(tokens);}
    else if(tokens[1] == "hadith") {random_hadith(hadiths);}
    else if(tokens[1] == "cls") {clearscreen();}
    else if(tokens[1] == "exit") {exit(0);}
    else if(tokens[1] == "ruqia") {play_audio(tokens);}
    else if(tokens[1] == "morning") {play_audio(tokens);}
    else if(tokens[1] == "azan") {play_audio(tokens);}
    else if(tokens[1] == "para")
    {
        if(tokens[2] == "29"){play_audio(tokens);}
        else if(tokens[2] == "1") {play_audio(tokens);}
    }
}




