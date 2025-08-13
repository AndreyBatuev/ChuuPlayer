#pragma once
#include <SFML/Audio.hpp>
#include <string>

class AudioPlayer {
public:
    AudioPlayer();
    bool load(const std::string& filename);
    void play();
    void pause();
    void stop();
    void setVolume(float volume);
    // Add other controls as needed...

private:
    sf::Music music;
};