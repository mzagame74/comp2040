// Copyright 2020 Matt Zagame
// SFML program that draws a sprite that can be controlled

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(
      (sf::VideoMode::getDesktopMode().width / 2),
      (sf::VideoMode::getDesktopMode().height / 2)), "PS0");
    window.setFramerateLimit(60);

    // space background
    sf::Texture space_texture;
    if (!space_texture.loadFromFile("space.jpg"))
        return -1;
    sf::Sprite background(space_texture);

    // alien sprite
    sf::Texture alien_texture;
    if (!alien_texture.loadFromFile("sprite.png"))
        return -1;
    sf::Sprite sprite(alien_texture);
    sprite.setScale(0.5, 0.5);

    // initial position of alien
    int xPos = window.getSize().x / 2;
    int yPos = window.getSize().y / 2;
    sprite.setPosition(xPos, yPos);

    // laser beam sprite
    sf::Texture laser_texture;
    if (!laser_texture.loadFromFile("laserbeam.png"))
        return -1;
    sf::Sprite laser_beam(laser_texture);
    laser_beam.setScale(0.25, 0.25);

    // game vars
    bool isIdle = true;
    bool firingLaser = false;
    sf::Clock clock;
    sf::Time time;

    while (window.isOpen())
    {
        // process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // idle loop
        if (isIdle) {
            if (time.asSeconds() < 2) {
                sprite.move(-2, 0);
            }
            else if (time.asSeconds() > 2 && time.asSeconds() < 4) {
                sprite.move(2, 0);
            }
            else if (time.asSeconds() > 4) {
              time = clock.restart();
            }
            time = clock.getElapsedTime();
        }

        // keyboard inputs
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          sprite.move(0, -2);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          sprite.move(-2, 0);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          sprite.move(0, 2);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          sprite.move(2, 0);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          sprite.move(-2, 0);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          sprite.move(2, 0);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          sprite.move(0, -2);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          sprite.move(0, 2);
          isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
          isIdle = false;
          firingLaser = true;
          laser_beam.setPosition(sprite.getPosition().x +
          (sprite.getLocalBounds().width / 8), sprite.getPosition().y);
        }

        if (firingLaser) {
          laser_beam.move(0, -10);
        }

        window.clear();
        window.draw(background);
        window.draw(laser_beam);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
