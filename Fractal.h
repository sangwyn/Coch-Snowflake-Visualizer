#ifndef SNEZHINKA_COCKA_FRACTAL_H
#define SNEZHINKA_COCKA_FRACTAL_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "Globals.h"

class Fractal {
private:
    int iterations = 0;
    sf::VertexArray sprite;
    sf::Vector2f center;
public:
    Fractal(sf::Vector2f pos = {0, 0}, int iterations = 0);
    Fractal Iterate();
    void Draw(sf::RenderWindow &window);
};


#endif
