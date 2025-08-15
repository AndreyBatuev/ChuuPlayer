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
    sf::SoundSource::Status getStatus();
    float getPositionPercent();
    void setPositionPercent(float percent);
private:
    sf::Music music;
};
