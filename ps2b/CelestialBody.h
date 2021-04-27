// Copyright 2020 Matt Zagame
#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
public:
    // constructors
    CelestialBody();
    CelestialBody(double x_position, double y_position, double x_velocity,
    double y_velocity, double init_mass, std::string image_filename);

    // accessors and mutators
    double getXPos() const;
    double getYPos() const;
    double getXVel() const;
    double getYVel() const;
    double getMass() const;
    sf::Image getImage() const;
    std::string getImageFilename() const;

    void setXPos(double x_position);
    void setYPos(double y_position);
    void setXVel(double x_velocity);
    void setYVel(double y_velocity);
    void setMass(double _mass);
    void setImage(std::string image_filename);

    // update x and y position of planet given the scale of the universe
    void updatePosition(double scale, sf::Vector2u windowSize);

private:
    // override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    override;

    double xPos, yPos;      // x and y position
    double xVel, yVel;      // x and y velocity
    double mass;
    std::string imageFilename;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif
