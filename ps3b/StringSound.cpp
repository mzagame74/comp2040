// Copyright 2020 Matt Zagame
#include "StringSound.h"
#include <cstdlib>
#include <ctime>

/** constructors **/
StringSound::StringSound() : _rb(nullptr), _time(0) {}

StringSound::StringSound(double frequency) {
    if (frequency == 0) {
        throw std::invalid_argument("StringSound constructor: frequency"
        " cannot be zero");
    }
    try {
        _rb = new CircularBuffer(ceil(SAMPLE_RATE / frequency));
    }
    catch (std::invalid_argument err) {
        std::cerr << err.what() << std::endl;
    }
    _time = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    try {
        _rb = new CircularBuffer(init.size());
        for (int i = 0; i < static_cast<int>(init.size()); i++) {
            _rb->enqueue(init[i]);
        }
    }
    catch (std::invalid_argument err) {
        std::cerr << err.what() << std::endl;
    }
    catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
    }
    _time = 0;
}

StringSound::StringSound(const StringSound& copySS) {
    _rb = copySS._rb;
    _time = copySS._time;
}

StringSound::StringSound(StringSound&& moveSS) noexcept {
    _rb = moveSS._rb;
    _time = moveSS._time;
    moveSS._rb = nullptr;
    moveSS._time = 0;
}

StringSound::~StringSound() {
    if (_rb != nullptr) { delete _rb; }
    _rb = nullptr;
    _time = 0;
}

void StringSound::pluck() {
    std::random_device device;
    std::mt19937 mt_rand(device());     // random number generator
    std::uniform_int_distribution<int16_t> distribution(INT16_MIN,
    INT16_MAX);

    _rb->empty();   // reset the ring buffer
    _time = 0;

    // fill ring buffer with random values
    try {
        for (int i = 0; i < _rb->capacity(); i++) {
            _rb->enqueue(distribution(mt_rand));
        }
    }
    catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
    }
}

void StringSound::tic() {
    try {
        int16_t next = DECAY_FACTOR * (_rb->dequeue() + _rb->peek()) / 2;
        _rb->enqueue(next);
    }
    catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
    }
    _time++;
}

sf::Int16 StringSound::sample() {
    sf::Int16 result = 0;
    try {
        result = _rb->peek();
    }
    catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
    }
    return result;
}

int StringSound::time() { return _time; }

StringSound& StringSound::operator=(const StringSound& rightSide) {
    if (this != &rightSide) {
        if (_rb != nullptr) { delete _rb; }
        _rb = rightSide._rb;
        _time = rightSide._time;
    }
    return *this;
}

StringSound& StringSound::operator=(StringSound&& rvalue) noexcept {
    if (this != &rvalue) {
        if (_rb != nullptr) { delete _rb; }
        _rb = rvalue._rb;
        _time = rvalue._time;
        rvalue._rb = nullptr;
        rvalue._time = 0;
    }
    return *this;
}
