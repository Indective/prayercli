#include "commandparsing.h"
#include "prayerlogic.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <vector>
#include <unordered_map>
#include <functional>

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

    std::vector<Hadith> hadiths = {
    {
        "Actions are judged by intentions.",
        "Sahih Bukhari 1"
    },
    {
        "None of you truly believes until he loves for his brother what he loves for himself.",
        "Sahih Bukhari 13"
    },
    {
        "The best of you are those who learn the Qur’an and teach it.",
        "Sahih Bukhari 5027"
    },
    {
        "Whoever believes in Allah and the Last Day, let him speak good or remain silent.",
        "Sahih Bukhari 6136"
    },
    {
        "Make things easy, not difficult. Spread good news, not hate.",
        "Sahih Bukhari 69"
    },
    {
        "Smiling at your brother is charity.",
        "Jami` at-Tirmidhi 1956"
    },
    {
        "Cleanliness is half of faith.",
        "Sahih Muslim 223"
    },
    {
        "He who does not show mercy to others will not be shown mercy.",
        "Sahih Bukhari 6013"
    },
    {
        "The strong is not the one who overcomes people by his strength, but the strong is the one who controls himself while in anger.",
        "Sahih Bukhari 6114"
    },
    {
        "Whoever conceals the faults of a Muslim, Allah will conceal his faults on the Day of Judgment.",
        "Sahih Muslim 2699"
    },
    {
        "Allah does not look at your appearance or wealth but at your hearts and deeds.",
        "Sahih Muslim 2564"
    },
    {
        "The best among you are those who have the best manners and character.",
        "Sahih Bukhari 3559"
    },
    {
        "Feed the hungry, visit the sick, and free the captive.",
        "Sahih Bukhari 5649"
    },
    {
        "None of you should wish for death because of a calamity that has befallen him.",
        "Sahih Bukhari 5671"
    },
    {
        "The one who guides to something good has a reward similar to the one doing it.",
        "Sahih Muslim 1893"
    },
    {
        "The world is a prison for the believer and a paradise for the disbeliever.",
        "Sahih Muslim 2956"
    },
    {
        "Modesty brings nothing except good.",
        "Sahih Bukhari 6117"
    },
    {
        "The most beloved deeds to Allah are those done regularly, even if they are small.",
        "Sahih Bukhari 6464"
    },
    {
        "Exchange gifts, as that will lead to increasing your love to one another.",
        "Al-Adab Al-Mufrad 594"
    },
    {
        "Visit the sick, feed the hungry, and (attend) funerals.",
        "Sahih Bukhari 5659"
    }
};


    while (true)
    {
        std::cout << std::endl << ">> ";
        std::getline(std::cin,command);
        parser.print_error_messages(commands,command);
        std::vector<std::string> tokens = parser.tokenize(command);
    }
    

    return 0;
}
