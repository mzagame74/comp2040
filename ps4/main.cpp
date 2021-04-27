// Copyright 2020 Matt Zagame
#include "ED.h"
#include <SFML/System.hpp>

int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cerr << "usage: ./ED < example10.txt" << std::endl;
        exit(-1);
    }
    ED ed;
    std::cin >> ed;
    sf::Clock clock;
    sf::Time t;

    std::cout << "Edit distance = " << ed.optDistance() << std::endl;
    std::cout << ed.alignment() << std::endl;

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds" <<
    std::endl;

    return 0;
}
