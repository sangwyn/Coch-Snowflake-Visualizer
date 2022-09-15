#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Fractal.h"
#include "Button.h"

int main() {
    sf::RenderWindow window({1600, 900}, "Fractal", sf::Style::Close);
    sf::Vector2f center = {(float)window.getSize().x / 2, (float)window.getSize().y / 2};

    sf::Texture left_selected, left_unselected, right_selected, right_unselected;
    left_selected.loadFromFile("Assets/left_selected.png");
    right_selected.loadFromFile("Assets/right_selected.png");
    left_unselected.loadFromFile("Assets/left_unselected.png");
    right_unselected.loadFromFile("Assets/right_unselected.png");
    Button left({1250, 800}, left_selected, left_unselected),
        right({1400, 800}, right_selected, right_unselected);

    int i = 0;
    float height = sqrt(pow(kLineLength, 2) - pow(kLineLength / 2, 2));
    Fractal fractal({center.x, center.y + kLineLength / 3});
    std::vector<Fractal> iterations;
    iterations.push_back(fractal);
    std::cout << i << '\n';
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (left.Selected()) {
                    if (i > 0) {
                        --i;
                        std::cout << i << '\n';
                    }
                } else if (right.Selected() && i < 10) {
                    if (i == iterations.size() - 1)
                        iterations.push_back(iterations[i].Iterate());
                    ++i;
                    std::cout << i << '\n';
                }
            }
        }

        left.SetSelection(left.MouseOver((sf::Vector2f) sf::Mouse::getPosition(window)));
        right.SetSelection(right.MouseOver((sf::Vector2f) sf::Mouse::getPosition(window)));

        window.clear(kBackgroundColor);

        left.Draw(window);
        right.Draw(window);
        iterations[i].Draw(window);

        window.display();
    }

    return 0;
}
