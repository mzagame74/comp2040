/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Matt Zagame
Hours to complete assignment: 5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
NBody simulates celestial bodies in a universe using the information found in nbody/planets.txt. This file contains the number of planets to display and the radius of the universe on the first two lines. Each subsequent line contains a planet's x position, y position, x and y velocities, mass, and image filename. The program uses input redirection from planets.txt to store and display the planets in the universe.


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Overloading the insertion operator in the Universe class allows for input redirection from a file to setup the planets for simulation. Both CelestialBody and Universe are sf::Drawable so that they may be drawn to the window. Each CelestialBody is instantiated as a pointer using the new operator and stored in a vector within the Universe class. The planets are then drawn in a loop in main using the draw function on each CelestialBody in the vector.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
Uses SFML libraries for graphics. Does not use smart pointers.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/