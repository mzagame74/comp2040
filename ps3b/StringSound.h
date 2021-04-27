// Copyright 2020 Matt Zagame
#ifndef STRINGSOUND_H   //NOLINT
#define STRINGSOUND_H   //NOLINT

#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <SFML/Audio/SoundBuffer.hpp>
#include "CircularBuffer.h"

#define SAMPLE_RATE 44100  // Hz
#define DECAY_FACTOR 0.996

class StringSound {
 public:
    // default constructor
    StringSound();

    /* create a guitar string sound of the given frequency using a sampling
    rate of 44,100 */
    explicit StringSound(double frequency);

    /* create a guitar string with size and initial values given by the
    vector */
    explicit StringSound(std::vector<sf::Int16> init);

    StringSound(const StringSound& copySS);
    StringSound(StringSound&& moveSS) noexcept;
    ~StringSound();

    /* pluck the guitar string by replacing the buffer with random values,
    representing white noise */
    void pluck();
    void tic();            // advance the simulation one step
    sf::Int16 sample();    // return the current sample
    int time();            // return the number of times tic has been called

    StringSound& operator=(const StringSound& rightSide);
    StringSound& operator=(StringSound&& rvalue) noexcept;

 private:
    CircularBuffer* _rb;   // ring buffer
    int _time;
};
#endif  //NOLINT
