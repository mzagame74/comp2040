// Copyright 2020 Matt Zagame
#ifndef UNIVERSE_H
#define UNIVERSE_H
#include "CelestialBody.h"
#include <memory>
#include <vector>
#include <cmath>
#define GRAVITY_CONST 6.67e-11

class Universe : public sf::Drawable {
public:
    // constructors
    Universe();
    Universe(std::string image_filename);
    explicit Universe(const Universe& copyUniverse);
    explicit Universe(Universe&& moveUniverse) noexcept;
    ~Universe();

    // accessors and mutators
    int getNumOfPlanets() const;
    double getRadius() const;
    sf::Image getImage() const;

    void setNumOfPlanets(int n);
    void setRadius(double r);
    void setImage(std::string image_filename);

    /* step moves forward the simulation a single interval of time in
    seconds */
    void step(double seconds);

    // vector of pointers to celestial bodies
    std::vector<std::unique_ptr<CelestialBody>> planets;

    // overloaded assignment operators for Universe setup in main
    Universe& operator=(Universe& rvalue);
    Universe& operator=(Universe&& rvalue) noexcept;

    // overloaded insertion operator for file input through terminal
    friend std::istream& operator>>(std::istream& in, Universe& universe);
    
private:
    // override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    override;

    int numOfPlanets;
    double radius;              // radius of the universe
    sf::Image image;            // universe background
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif
