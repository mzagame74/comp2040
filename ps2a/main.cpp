#include "Universe.h"

int main(int argc, char* argv[]) {
    if (argc != 1) {
        std::cerr << "Incorrect usage. Usage: ./NBody < filename.txt" << std::endl;
        exit(-1);
    }

    Universe universe;
    try {
        universe = Universe("nbody/starfield.jpg");
    }
    catch (std::invalid_argument err) {
        std::cout << err.what() << std::endl;
        exit(-1);
    }
    sf::Vector2u windowSize = universe.getImage().getSize();
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "The Solar System!");

    //get universe data from file input
    std::cin >> universe;

    //SFML display loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
        }
        window.clear();
        window.draw(universe);
        for (int i = 0; i < universe.getNumOfPlanets(); i++) {
            window.draw(*universe.planets[i]);
        }
        window.display();
    }

    return 0;
}