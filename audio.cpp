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
