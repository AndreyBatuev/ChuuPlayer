#include "audio.h"

AudioPlayer::AudioPlayer() {
    // Initialize any default settings
    music.setVolume(50.0f);
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