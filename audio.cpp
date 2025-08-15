#include "audio.h"

AudioPlayer::AudioPlayer() {
    music.setVolume(50.0f);
}
sf::SoundSource::Status AudioPlayer::getStatus() {
    return music.getStatus();
}
bool AudioPlayer::load(const std::string& filename) {
    if (!music.openFromFile(filename)) {
        return false;
    }
    return true;
}
float AudioPlayer::getPositionPercent() {
    if (music.getDuration() == sf::Time::Zero) {
        return 0.0f;
    }
    return (music.getPlayingOffset().asSeconds() / music.getDuration().asSeconds()) * 100.0f;
}

void AudioPlayer::setPositionPercent(float percent) {
    percent = std::max(0.0f, std::min(100.0f, percent));

    if (music.getDuration() != sf::Time::Zero) {
        sf::Time newTime = sf::seconds((percent / 100.0f) * music.getDuration().asSeconds());
        music.setPlayingOffset(newTime);
    }
}
void AudioPlayer::play() {
    music.play();
}

void AudioPlayer::pause() {
    music.pause();
}

void AudioPlayer::stop() {
    music.stop();
}

void AudioPlayer::setVolume(float volume) {
    music.setVolume(volume);
}
