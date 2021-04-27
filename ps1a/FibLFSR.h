/** Matt Zagame
 * FibLFSR class header
 * 9/13/2020
 */
#ifndef FIBLFSR_H
#define FIBLFSR_H
#include <iostream>
#include <exception>

class FibLFSR {
public:
    FibLFSR(std::string seed);  //constructor to create LFSR with the given
                                //initial seed and tap
    explicit FibLFSR(FibLFSR& copyLFSR);
    explicit FibLFSR(FibLFSR&& moveLFSR) noexcept;
    ~FibLFSR();
    FibLFSR& operator=(const FibLFSR& rvalue);
    FibLFSR& operator=(FibLFSR&& rvalue) noexcept;

    int step();             //simulate one step and return the new bit 
                            //as 0 or 1
    int generate(int k);    //simulate k steps and return k-bit integer

    //displays LFSR
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& flfsr);

private:
    int size;               //size of register
    int* reg;               //register as an array of integers
};

#endif