// Copyright 2020 Matt Zagame
/** FibLFSR.cpp
 * FibLFSR is a 16-bit linear feedback shift register
 * Matt Zagame 9/19/2020
 */
#include "FibLFSR.h"
#define TAP_BIT1 13
#define TAP_BIT2 12
#define TAP_BIT3 10

/** constructors **/
FibLFSR::FibLFSR() : size(0), reg(nullptr) {}

FibLFSR::FibLFSR(std::string seed) {
    size = seed.length();
    if (size == 16) {
        reg = new int[size];
        int bit = 0;
        int count = 0;
        for (int i = size - 1; i >= 0; i--) {
            bit = (int)seed[count] - ASCII_OFFSET;
            if (bit == 0 || bit == 1) {
                reg[i] = bit;
                count++;
            }
            else {
                reg = nullptr;
                size = 0;
                throw std::invalid_argument("Incorrect seed, seed must be"
                " in binary form");
            }
        }
    }
    else {
        reg = nullptr;
        size = 0;
        throw std::invalid_argument("Incorrect seed size, seed must be 16"
        " bits long");
    }
}

FibLFSR::FibLFSR(const FibLFSR& copyLFSR) {
    size = copyLFSR.size;
    if (size > 0) {
        reg = new int[size];
        for (int i = 0; i < size; i++) {
            reg[i] = copyLFSR.reg[i];
        }
    }
    else reg = nullptr;
}

FibLFSR::FibLFSR(FibLFSR&& moveLFSR) noexcept {
    size = moveLFSR.size;
    reg = moveLFSR.reg;
    moveLFSR.reg = nullptr;
    moveLFSR.size = 0;
}

FibLFSR::~FibLFSR() {
    if (reg != nullptr) delete[] reg;
    reg = nullptr;
    size = 0;
}

/** overloaded assignment operators **/
FibLFSR& FibLFSR::operator=(const FibLFSR& rvalue) {
    if (this == &rvalue) return *this;
    if (reg != nullptr) delete[] reg;

    size = rvalue.size;
    if (size > 0) {
        reg = new int[size];
        for (int i = 0; i < size; i++) {
            reg[i] = rvalue.reg[i];
        }
    }
    return *this;
}

FibLFSR& FibLFSR::operator=(FibLFSR&& rvalue) noexcept {
    if (this == &rvalue) return *this;
    if (reg != nullptr) delete[] reg;

    size = rvalue.size;
    reg = rvalue.reg;
    rvalue.reg = nullptr;
    rvalue.size = 0;

    return *this;
}

/** step simulates one step of the LFSR by XORing the leftmost bit
 * through the tap bits and returns the result as the rightmost bit **/
int FibLFSR::step() {
    int rightmostBit = reg[size - 1] ^ reg[TAP_BIT1];
    rightmostBit ^= reg[TAP_BIT2];
    rightmostBit ^= reg[TAP_BIT3];

    // shift each bit to the left except the rightmost bit
    for (int i = size - 1; i >= 1; i--) {
        reg[i] = reg[i - 1];
    }
    reg[0] = rightmostBit;  // assign new rightmost bit

    return rightmostBit;
}

/** generate takes k as a parameter and generates k number of steps
 * in the LFSR and returns a k-bit integer **/
int FibLFSR::generate(int k) {
    int result = 0;
    for (int i = k; i > 0; i--) {
        result *= 2;
        result += step();
    }
    return result;
}

/** overloaded stream insertion operator displays the LFSR bits in order of,
 * from left to right, the highest index bit to the lowest index bit **/
std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr) {
    for (int i = flfsr.size - 1; i >= 0; i--) {
        out << flfsr.reg[i];
    }
    return out;
}
