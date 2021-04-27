#ifndef UNIVERSE_H
#define UNIVERSE_H
#include "CelestialBody.h"
#include <vector>

class Universe : public sf::Drawable {
public:
    //constructors
    Universe();
    Universe(std::string image_filename);
    explicit Universe(const Universe& copyUniverse);
    explicit Universe(Universe&& moveUniverse) noexcept;
    ~Universe();

    //accessors and mutators
    int getNumOfPlanets() const;
    float getRadius() const;
    sf::Image getImage() const;
    void setNumOfPlanets(int n);
    void setRadius(float r);
    void setImage(std::string image_filename);

    //overloaded assignment operators for Universe setup in main
    Universe& operator=(Universe& rvalue);
    Universe& operator=(Universe&& rvalue) noexcept;

    //vector of pointers to celestial bodies
    std::vector<CelestialBody*> planets;

    //overloaded insertion operator for file input through terminal
    friend std::istream& operator>>(std::istream& in, Universe& universe);
    
private:
    //override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int numOfPlanets;
    float radius;               //radius of universe
    sf::Image image;            //image data for universe
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif