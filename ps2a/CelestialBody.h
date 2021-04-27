#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable {
public:
    //constructors
    CelestialBody();
    CelestialBody(float x_position, float y_position, float x_velocity, 
    float y_velocity, float init_mass, std::string image_filename);

    //accessors and mutators
    float getXPos() const;
    float getYPos() const;
    float getXVel() const;
    float getYVel() const;
    float getMass() const;
    sf::Image getImage() const;
    void setXPos(float xPos);
    void setYPos(float yPos);
    void setXVel(float xVel);
    void setYVel(float yVel);
    void setMass(float mass);
    void setImage(std::string image_filename);

    //update x and y position of planet
    void updatePosition();

private:
    //override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    float xPos, yPos;       //x and y position
    float xVel, yVel;       //x and y velocity
    float mass;             //mass of celestial body
    sf::Image image;        //image data for celestial body
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif