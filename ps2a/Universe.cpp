#include "Universe.h"

//constructors
Universe::Universe() : numOfPlanets(0), radius(0) {}

Universe::Universe(std::string image_filename) {
    if(!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Universe image file not found, exiting.");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    numOfPlanets = 0;
    radius = 0;
}

Universe::Universe(const Universe& copyUniverse) {
    numOfPlanets = copyUniverse.numOfPlanets;
    radius = copyUniverse.radius;
    image = copyUniverse.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

Universe::Universe(Universe&& moveUniverse) noexcept {
    numOfPlanets = moveUniverse.numOfPlanets;
    radius = moveUniverse.radius;
    image = moveUniverse.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    moveUniverse.numOfPlanets = 0;
    moveUniverse.radius = 0;
}

Universe::~Universe() {
    numOfPlanets = 0;
    radius = 0;
}

//accessors and mutators
int Universe::getNumOfPlanets() const { return numOfPlanets; }
float Universe::getRadius() const { return radius; }
sf::Image Universe::getImage() const { return image; }

void Universe::setNumOfPlanets(int n) { numOfPlanets = n; }
void Universe::setRadius(float r) { radius = r; }
void Universe::setImage(std::string image_filename) { 
    if(!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Universe image file not found, exiting.");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

//overloaded assingment operators
Universe& Universe::operator=(Universe& rvalue) {
    if (this == &rvalue) { return *this; }

    numOfPlanets = rvalue.numOfPlanets;
    radius = rvalue.radius;
    image = rvalue.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    return *this;
}

Universe& Universe::operator=(Universe&& rvalue) noexcept {
    if (this == &rvalue) { return *this; }

    numOfPlanets = rvalue.numOfPlanets;
    radius = rvalue.radius;
    image = rvalue.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    rvalue.numOfPlanets = 0;
    rvalue.radius = 0;

    return *this;
}

//overloaded insertion operator for file input through terminal
std::istream& operator>>(std::istream& in, Universe& universe) {
    float fval;
    std::string image;
    sf::Vector2u windowSize = universe.getImage().getSize();

    in >> universe.numOfPlanets;
    in >> universe.radius;

    //get data for each planet
    for (int i = 0; i < universe.numOfPlanets; i++) {
        CelestialBody* planet = new CelestialBody();

        //get xPos
        in >> fval;
        fval = (((fval / 2) / universe.radius) * windowSize.x) + (windowSize.x / 2);
        planet->setXPos(fval);

        //get yPos
        in >> fval;
        fval = (((fval / 2) / universe.radius) * windowSize.y) + (windowSize.y / 2);
        planet->setYPos(fval);

        planet->updatePosition();

        //get velocity, mass and image file
        in >> fval;
        planet->setXVel(fval);
        in >> fval;
        planet->setYVel(fval);
        in >> fval;
        planet->setMass(fval);
        in >> image;
        image = "nbody/" + image;

        try {
            planet->setImage(image);
        }
        catch (std::invalid_argument err) {
            std::cout << err.what() << std::endl;
            exit(-1);
        }
        universe.planets.push_back(planet);
    }
    
    return in;
}

//override virtual draw function
void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}