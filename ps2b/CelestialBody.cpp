// Copyright 2020 Matt Zagame
#include "CelestialBody.h"

// constructors
CelestialBody::CelestialBody() : xPos(0), yPos(0), xVel(0), yVel(0),
mass(0) {}

CelestialBody::CelestialBody(double x_position, double y_position, double
x_velocity, double y_velocity, double init_mass,
std::string image_filename) {
    if (!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Celestial Body image file not found,"
        " exiting"); 
    }
    imageFilename = image_filename;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    xPos = x_position;   yPos = y_position;
    xVel = x_velocity;   yVel = y_velocity;
    mass = init_mass;
}

// accessors and mutators
double CelestialBody::getXPos() const { return xPos; }
double CelestialBody::getYPos() const { return yPos; }
double CelestialBody::getXVel() const { return xVel; }
double CelestialBody::getYVel() const { return yVel; }
double CelestialBody::getMass() const { return mass; }
sf::Image CelestialBody::getImage() const { return image; }
std::string CelestialBody::getImageFilename() const {
    return imageFilename;
}

void CelestialBody::setXPos(double x_position) { xPos = x_position; }
void CelestialBody::setYPos(double y_position) { yPos = y_position; }
void CelestialBody::setXVel(double x_velocity) { xVel = x_velocity; }
void CelestialBody::setYVel(double y_velocity) { yVel = y_velocity; }
void CelestialBody::setMass(double _mass) { mass = _mass; }

void CelestialBody::setImage(std::string image_filename) { 
    if(!image.loadFromFile("nbody/" + image_filename)) {
        throw std::invalid_argument("Celestial Body image file not found");
    }
    imageFilename = image_filename;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

// update x and y position of planet given the scale of the universe
void CelestialBody::updatePosition(double scale, sf::Vector2u windowSize) {
    int x, y;
    x = ((xPos / 2) / scale * windowSize.x) + (windowSize.x / 2);
    y = ((yPos / 2) / scale * windowSize.y) + (windowSize.y / 2);
    sprite.setPosition(x, y);
}

// override virtual draw function
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)
const {
    target.draw(sprite, states);
}
