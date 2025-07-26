#include "audioplayer.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <filesystem>

void audioplayer::play_audio(const std::vector<std::string> tokens)
{
    std::string path = std::filesystem::current_path().string() + "/Sounds/" + tokens.at(1) + ".mp3";
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
