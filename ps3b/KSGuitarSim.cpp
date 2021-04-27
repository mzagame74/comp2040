// Copyright 2020 Matt Zagame
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "StringSound.h"

/* takes a string sound and returns a vector sample stream of 16 bit ints */
std::vector<sf::Int16> makeSamples(StringSound* gs);

/* initializes a vector of sound buffers from a vector of samples */
void setupSoundBuffers(const std::vector<std::vector<sf::Int16>>& samples,
 std::vector<sf::SoundBuffer>* soundBuffers);

/* initializes a vector of sounds from a vector of sound buffers */
void setupSounds(const std::vector<sf::SoundBuffer>& soundBuffers,
 std::vector<sf::Sound>* sounds);

int main(int argc, char* argv[]) {
    // SFML window setup vars
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    if (!image.loadFromFile("piano.png")) {
        throw std::runtime_error("sf::Image: could not load piano.png");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    sf::RenderWindow window(sf::VideoMode(image.getSize().x,
    image.getSize().y), "KS Guitar Sim");

    // guitar sim vars
    // keys used to play guitar string sounds
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    std::vector<std::vector<sf::Int16>> samples;
    std::vector<sf::SoundBuffer> soundBuffers;
    std::vector<sf::Sound> sounds;
    StringSound gs;
    double freq;    // frequency for string sounds

    // create samples from string sounds for each key
    for (int i = 0; i < static_cast<int>(keys.length()); i++) {
        freq = 440 * pow(2, (static_cast<double>(i) - 24) / 12);
        try {
            gs = StringSound(freq);
        }
        catch (std::invalid_argument err) {
            std::cerr << err.what() << std::endl;
        }
        samples.push_back(makeSamples(&gs));
    }

    setupSoundBuffers(samples, &soundBuffers);
    setupSounds(soundBuffers, &sounds);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // check key pressed
            if (event.type == sf::Event::TextEntered) {
                char key = static_cast<char>(event.text.unicode);
                for (int i = 0; i < static_cast<int>(keys.length()); i++) {
                    if (key == keys[i]) {
                        sounds[i].play();   // play the sound sample
                                            // equivalent to the key pressed
                    }
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

std::vector<sf::Int16> makeSamples(StringSound* gs) {
    std::vector<sf::Int16> sampleStream;
    gs->pluck();
    int duration = 8;   // seconds
    for (int i = 0; i < SAMPLE_RATE * duration; i++) {
        gs->tic();
        sampleStream.push_back(gs->sample());
    }
    return sampleStream;
}

void setupSoundBuffers(const std::vector<std::vector<sf::Int16>>& samples,
 std::vector<sf::SoundBuffer>* soundBuffers) {
    sf::SoundBuffer buffer;
    for (int i = 0; i < static_cast<int>(samples.size()); i++) {
        if (!buffer.loadFromSamples(&(samples[i])[0], samples[i].size(), 2,
        SAMPLE_RATE)) {
            throw std::runtime_error("setupSoundBuffers(): could not load"
            " SoundBuffer");
        }
        soundBuffers->push_back(buffer);
    }
}

void setupSounds(const std::vector<sf::SoundBuffer>& soundBuffers,
 std::vector<sf::Sound>* sounds) {
     sf::Sound sound;
     for (int i = 0; i < static_cast<int>(soundBuffers.size()); i++) {
        sound.setBuffer(soundBuffers[i]);
        sounds->push_back(sound);
     }
}
