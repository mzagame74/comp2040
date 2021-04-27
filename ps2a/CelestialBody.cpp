#include "CelestialBody.h"

//constructors
CelestialBody::CelestialBody() : xPos(0), yPos(0), xVel(0), yVel(0), mass(0) {}

CelestialBody::CelestialBody(float x_position, float y_position, float x_velocity, float y_velocity, float init_mass, std::string image_filename) {
    if (!image.loadFromFile(image_filename)) { 
        throw std::invalid_argument("Celestial Body image file not found, exiting."); 
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    xPos = x_position;   yPos = y_position;
    xVel = x_velocity;   yVel = y_velocity;
    mass = init_mass;
}

//accessors and mutators
float CelestialBody::getXPos() const { return xPos; }
float CelestialBody::getYPos() const { return yPos; }
float CelestialBody::getXVel() const { return xVel; }
float CelestialBody::getYVel() const { return yVel; }
float CelestialBody::getMass() const { return mass; }
sf::Image CelestialBody::getImage() const { return image; }

void CelestialBody::setXPos(float x_position) { xPos = x_position; }
void CelestialBody::setYPos(float y_position) { yPos = y_position; }
void CelestialBody::setXVel(float x_velocity) { xVel = x_velocity; }
void CelestialBody::setYVel(float y_velocity) { yVel = y_velocity; }
void CelestialBody::setMass(float mass) { mass = mass; }
void CelestialBody::setImage(std::string image_filename) { 
    if(!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Celestial Body image file not found, exiting.");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

//update x and y position of planet
void CelestialBody::updatePosition() {
    sprite.setPosition(xPos, yPos);
}

//override virtual draw function
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}