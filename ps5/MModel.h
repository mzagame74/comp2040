// Copyright 2020 Matt Zagame
#ifndef MMODEL_H  //NOLINT
#define MMODEL_H  //NOLINT

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <utility>
#include <random>

class MModel {
 public:
    /* Create a Markov model of order k from given text (assume that text
    has length at least k). */
    MModel(std::string text, int k);

    // Return the order k of the Markov model.
    int kOrder() const;

    // Return the input text.
    std::string getText() const;

    // Return the Markov Model table map.
    std::map<std::string, std::map<char, int>> getMTable() const;

    /* Return the number of occurrences of kgram in text.
    Throws an exception if kgram is not at least of length k. */
    int freq(std::string kgram) const;

    /* Return the number of times char c follows kgram.
    If order = 0, return the number of times char c occurs.
    Throws an exception if kgram is not at least of length k. */
    int freq(std::string kgram, char c) const;

    /* Return a random character following given kgram.
    Throws an exception if kgram is not at least of length k.
    Throws an exception if no such kgram. */
    char kRand(std::string kgram) const;

    /* Generate a string of length L characters by simulating a trajectory
    through the corresponding Markov chain. The first k characters of the
    newly generated string should be the argument kgram. Assume that L is at
    least k.
    Throws an exception if kgram is not at least of length k. */
    std::string generate(std::string kgram, int L) const;

    /* Overloaded stream insertion operator displays the internal state of
    the Markov model. */
    friend std::ostream& operator<<(std::ostream& out, const MModel&
    mmodel);

 private:
    int _k;             // order of Markov Model
    std::string _text;  // text to analyze

    // map of kgram to map of frequency of next char
    std::map<std::string, std::map<char, int>> _mtable;
};
#endif   //NOLINT
