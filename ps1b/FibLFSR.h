// Copyright 2020 Matt Zagame
/** FibLFSR.h
 * FibLFSR is a 16-bit linear feedback shift register
 * Matt Zagame 9/19/2020
 */
#include <iostream>
#include <exception>
#include <math.h>
#ifndef FIBLFSR_H
#define FIBLFSR_H
#define ASCII_OFFSET 48

class FibLFSR {
public:
    FibLFSR();
    FibLFSR(std::string seed);  // constructor to create FibLFSR with the
                                // given initial seed and tap
    explicit FibLFSR(const FibLFSR& copyFibLFSR);
    explicit FibLFSR(FibLFSR&& moveFibLFSR) noexcept;
    ~FibLFSR();
    FibLFSR& operator=(const FibLFSR& rvalue);
    FibLFSR& operator=(FibLFSR&& rvalue) noexcept;

    int step();             // simulate one step and return the new bit 
                            // as 0 or 1
    int generate(int k);    // simulate k steps and return k-bit integer

    // displays LFSR
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR&
    flfsr);

private:
    int size;               // size of register
    int* reg;               // register as an array of integers
};

#endif
