#include "commandparsing.h"
#include "prayerlogic.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <vector>

namespace fs = std::filesystem;

int main()
{
    prayerlogic prayer;
    commandparsing parser;

    std::string date , city, command;
    std::string path = fs::current_path().parent_path().string();
    fs::current_path(path);
    path = path + "/src";
    fs::current_path(path);

    std::map<std::string, std::string> commands = {
        {"prayertimes","prints the prayer times for a specified date and city"},
        {"hadith", "prints a random hadith"},
        {"surah", "prints a random surah for you to read"},
        {"sleep" , "plays athkar-alnawm"},
        {"morning","plays athkar-alsabah"},
        {"ruqia", "plays the ruqia-alsharaia"}
    };

    while (true)
    {
        std::cout << std::endl << ">>";
        std::getline(std::cin,command);
        std::vector<std::string> tokens = parser.tokenize(command);
        if(tokens[0] == "prayer")
        {
            prayer.display_data(tokens);
        }
        else
        {
            std::cout << "Invalid command syntax" << std::endl;
        }
    }
    

    return 0;
}