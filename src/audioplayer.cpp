#include "audioplayer.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include <filesystem>

void audioplayer::play_ruqia()
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/ruqia.mp3";
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }

    music.play();
    std::cout << "Ruqia is playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Ruqia stopped.\n";
}

void audioplayer::play_morning_athkar()
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/morning.mp3";
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }

    music.play();
    std::cout << "Morning Azkar is playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Morning Azkar stopped.\n";
}

void audioplayer::play_azan()
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/azan.mp3";
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }

    music.play();
    std::cout << "Azan is playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Aazan stopped.\n";
}

void audioplayer::play_para_29()
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/para29.mp3";
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }
    
    music.play();
    std::cout << "Para 29 is playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Para 29 stopped.\n";
}

void audioplayer::play_para_1()
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/para1.mp3";
    sf::Music music;

    if (!music.openFromFile(path)) {
        std::cerr << "Error loading sound file\n";
        return;
    }
    
    music.play();
    std::cout << "Para 1 is playing. Press ENTER to stop...\n";

    // Wait for user to press Enter
    std::string dummy;
    std::getline(std::cin, dummy);

    music.stop();
    std::cout << "Para 1 stopped.\n";
}
