// Copyright 2020 Matt Zagame
#include "MModel.h"

MModel::MModel(std::string text, int k) {
    _text = text;
    _k = k;

    if (_text.length() < static_cast<unsigned int>(_k)) {
        throw std::invalid_argument("MModel(string text, int k): order k"
        " must be less than or equal to text length.");
    }

    // setup Markov table
    unsigned int pos = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        std::string kgram;
        std::map<char, int> _ftable;    // map of next char to its frequency

        // parse text for kgrams
        for (unsigned int j = i; j < i + _k; j++) {
            // get characters for kgrams
            if (j >= _text.length()) {
                pos = j - _text.length();
            } else {
                pos = j;
            }
            kgram += _text.at(pos);
        }

        // setup next char frequency table
        pos++;
        if (pos >= _text.length()) { pos -= _text.length(); }
        _ftable.insert(std::make_pair(_text.at(pos), 0));

        // insert kgram and frequency table into map
        if (_mtable.count(kgram) == 0) {
            _mtable.insert(std::make_pair(kgram, _ftable));
        }

        // update next char frequency table
        _mtable[kgram][_text.at(pos)]++;
    }
}

int MModel::kOrder() const { return _k; }
std::string MModel::getText() const { return _text; }
std::map<std::string, std::map<char, int>> MModel::getMTable() const {
    return _mtable;
}

int MModel::freq(std::string kgram) const {
    if (kgram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("freq(string kgram): kgram must be of"
        " length greater than or equal to order k.");
    }
    int count = 0;
    for (unsigned int i = 0; i < _text.length(); i++) {
        unsigned int pos = 0;
        std::string kg;
        // parse input text for kgrams
        for (unsigned int j = i; j < i + _k; j++) {
            // get characters for kgrams
            if (j >= _text.length()) {
                pos = j - _text.length();
            } else {
                pos = j;
            }
            kg += _text.at(pos);
        }
        if (kgram == kg) { count++; }
    }
    return count;
}

int MModel::freq(std::string kgram, char c) const {
    if (kgram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("freq(string kgram, char c): kgram must be"
        " of length greater than or equal to order k.");
    }
    return _mtable.at(kgram).at(c);
}

char MModel::kRand(std::string kgram) const {
    if (kgram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("kRand(string kgram): kgram must be of"
        " length greater than or equal to order k.");
    }
    if (_mtable.count(kgram) == 0) {
        throw std::runtime_error("kRand(string kgram): kgram does not"
        " exist.");
    }
    std::string alphabet;   // string of next chars
    for (auto const &var1 : _mtable) {
        if (var1.first == kgram) {
            for (auto const &var2 : var1.second) {
                alphabet += var2.first;
            }
        }
    }
    std::random_device device;
    std::mt19937 mt_rand(device());
    std::uniform_int_distribution<int> distribution(0, alphabet.length()
    - 1);

    return alphabet[distribution(mt_rand)];
}

std::string MModel::generate(std::string kgram, int L) const {
    if (kgram.length() < static_cast<unsigned int>(_k)) {
        throw std::runtime_error("generate(string kgram, int L): kgram must"
        " be of length greater than or equal to order k.");
    }
    std::string generated = kgram;
    // generate new characters based on kgrams
    for (int i = _k; i < L; i++) {
        generated += kRand(generated.substr(i - _k, _k));
    }
    return generated;
}

std::ostream& operator<<(std::ostream& out, const MModel& mmodel) {
    out << "Markov Model\tOrder: " << mmodel._k << std::endl;
    out << "kgram:\tfrequency:\tfrqncy of next char:\tprob of next char:" <<
    std::endl;

    for (auto const &var1 : mmodel._mtable) {
        // var1.first = kgram
        out << var1.first << "\t";
        out << mmodel.freq(var1.first) << "\t\t";
        for (auto const &var2 : var1.second) {
            // var2.first = next char
            // var2.second = data
            out << var2.first << ":" << var2.second << " ";
        }
        out << "\t\t\t";
        for (auto const &var2 : var1.second) {
            out << var2.first << ":" << var2.second << "/" <<
            mmodel.freq(var1.first) << " ";
        }
        out << std::endl;
    }
    return out;
}
