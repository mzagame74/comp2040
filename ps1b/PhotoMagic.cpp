// Copyright 2020 Matt Zagame
/** PhotoMagic.cpp
 * encrypts or decrypts images using a 16-bit linear feedback shift register
 * given an input filename, output filename, and a 16-bit binary seed
 * Matt Zagame 9/19/2020
 */
#include "FibLFSR.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// transforms image using FibLFSR
void transform(sf::Image& img, FibLFSR* flfsr);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << 
            " <input file> <output file> <16 bit binary seed>" << std::endl;
        return -1;
    }
    
    FibLFSR flfsr;
    try {
        flfsr = FibLFSR(argv[3]);
    }
    catch (std::invalid_argument err) {
        std::cout << err.what() << std::endl;
        return -1;
    }

    sf::Image image;
    if (!image.loadFromFile(argv[1])) { return -1; }

    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted/"
    "Decrypted");

    sf::Texture texture1;
    texture1.loadFromImage(image);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);

    transform(image, &flfsr);     // transform the image file

    sf::Texture texture2;
    texture2.loadFromImage(image);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window1.close(); }
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window2.close(); }
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    if (!image.saveToFile(argv[2])) { return -1; }

    return 0;
}

/** transform alters an image's pixel data using a 16-bit LFSR **/
void transform(sf::Image& img, FibLFSR* flfsr) {
    sf::Vector2u size = img.getSize();
    sf::Color p;        // pixel

    for (int x = 0; x < (int)size.x; x++) {
        for (int y = 0; y < (int)size.y; y++) {
            p = img.getPixel(x, y);
            p.r ^= flfsr->generate(8);
            p.g ^= flfsr->generate(8);
            p.b ^= flfsr->generate(8);
            img.setPixel(x, y, p);
        }
    }
}
