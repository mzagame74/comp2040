/** Matt Zagame
 * FibLFSR class implementation
 * 9/13/2020
 */
#include "FibLFSR.h"
#define ASCII_OFFSET 48

/** FibLFSR constructors **/
FibLFSR::FibLFSR(std::string seed) {
    size = seed.length();
    if (size == 16) {
        reg = new int[size];
        int count = 0;
        for (int i = size - 1; i >= 0; i--) {
            reg[i] = (int)seed[count] - ASCII_OFFSET;
            count++;
        }
    }
    else {
        reg = nullptr;
        size = 0;
        //No try-catch block for BOOST tests
        throw std::invalid_argument(
            "Incorrect seed size, seed must be 16 bits");
    }
}

FibLFSR::FibLFSR(FibLFSR& copyLFSR) {
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

/** FibLFSR overloaded assignment operators **/
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
    int rightmostBit = reg[15] ^ reg[13];
    rightmostBit ^= reg[12];
    rightmostBit ^= reg[10];

    //shift each bit to the left except the rightmost bit
    for (int i = size - 1; i >= 1; i--) {
        reg[i] = reg[i - 1];
    }
    reg[0] = rightmostBit;  //assign new rightmost bit

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

/** overloaded stream insertion operator displays the LFSR bits from 
 * left to right the highest index bit to the lowest index bit **/
std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr) {
    for (int i = flfsr.size - 1; i >= 0; i--) {
        out << flfsr.reg[i];
    }
    return out;
}