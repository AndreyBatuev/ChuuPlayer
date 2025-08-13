#include "audio.h"
#include <iostream>

int main() {
    AudioPlayer player;
    
    if (!player.load("song.mp3")) {
        std::cerr << "Failed to load audio file!" << std::endl;
        return 1;
    }

    player.play();
    player.setVolume(100.0f);

    while (true) {

    }

    return 0;
}