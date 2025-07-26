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
  