// Copyright 2020 Matt Zagame
#ifndef ED_H    //NOLINT
#define ED_H    //NOLINT

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ED {
 public:
    ED();

    // construct an Edit Distance object with two strings
    ED(std::string x, std::string y);

    // returns the penalty for aligning chars a and b
    static int penalty(char a, char b);

    // returns the minimum of three integers or a if they are all the same
    static int min(int a, int b, int c);

    // populates the matrix and returns the optimal distance from [0][0]
    int optDistance();

    /* trace the matrix and return a string of the alignment which can be 
    displayed */
    std::string alignment();

    // operator overloads
    friend std::istream& operator>>(std::istream& in, ED& ed);

 private:
    int _M;       // length of string x
    int _N;       // length of string y
    std::string _x, _y;

    // matrix used to measure optimal sequence alignment
    std::vector<std::vector<int>> _opt;
};
#endif  //NOLINT
