// Copyright 2020 Matt Zagame
#include "ED.h"

ED::ED() : _M(0), _N(0) {}

ED::ED(std::string x, std::string y) {
    _x = x; _y = y;
    _M = static_cast<int>(_x.length());
    _N = static_cast<int>(_y.length());

    // initialize vector matrix of ints
    _opt = std::vector<std::vector<int>>(_M+2, std::vector<int>(_N+2, 0));

    // setup base cases
    for (int i = _M; i >= 0; i--) {
        _opt[i][_N+1] = _opt[i+1][_N+1] + 2;
    }
    for (int j = _N; j >= 0; j--) {
        _opt[_M+1][j] = _opt[_M+1][j+1] + 2;
    }
}

int ED::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

int ED::min(int a, int b, int c) {
    if (b < a && b < c)
        return b;
    if (c < a && c < b)
        return c;
    else
        return a;
}

int ED::optDistance() {
    // fill matrix with cost values from bottom right to top left
    for (int i = _M; i >= 0; i--) {
        for (int j = _N; j >= 0; j--) {
            _opt[i][j] = min(_opt[i+1][j+1] + penalty(_x[i], _y[j]),
            _opt[i+1][j] + 2, _opt[i][j+1] + 2);
        }
    }
    return _opt[0][0];
}

std::string ED::alignment() {
    std::string result;     // result is in table form

    if (_M != 0 && _N != 0) {   // make sure neither string is empty
        for (int i = 0; i < _M; i++) {
            for (int j = 0; j < _N; j++) {
                // move diagonal on matrix
                if (_opt[i][j] == _opt[i + 1][j + 1] && _x[i] == _y[j]) {
                    result.push_back(_x[i]);
                    result.append(" ");
                    result.push_back(_y[j]);
                    result.append(" 0\n");
                    i++;
                } else if (_opt[i][j] == _opt[i + 1][j + 1] + 1) {
                    result.push_back(_x[i]);
                    result.append(" ");
                    result.push_back(_y[j]);
                    result.append(" 1\n");
                    i++;
                } else if (_opt[i][j] == _opt[i + 1][j] + 2) {
                    // move down
                    result.push_back(_x[i]);
                    result.append(" — 2\n");
                    i++;
                    j--;
                } else if (_opt[i][j] == _opt[i][j + 1] + 2) {
                    // move right
                    result.append("— ");
                    result.push_back(_y[j]);
                    result.append(" 2\n");
                }
            }
        }
    } else if (_M != 0 && _N == 0) {
        result.append("String y is empty, returning string x: ");
        result.append(_x);
        result.append("\n");
    } else if (_M == 0 && _N != 0) {
        result.append("String x is empty, returning string y: ");
        result.append(_y);
        result.append("\n");
    } else {
        result.append("No two strings provided\n");
    }
    return result;
}

std::istream& operator>>(std::istream& in, ED& ed) {
    std::string x;
    std::string y;

    in >> x;
    in >> y;
    ed = ED(x, y);

    return in;
}
