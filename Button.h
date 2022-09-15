#ifndef SNEZHINKA_COCKA_BUTTON_H
#define SNEZHINKA_COCKA_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
private:
    std::string type;
    sf::Font font;
    sf::RectangleShape rect;
    sf::Text text_inside;
    bool is_selected = false;
    bool text_selected = false;
    sf::Vector2f pos;
    sf::Texture selected, unselected;
    sf::Sprite sprite;
public:
    Button(sf::Vector2f pos, sf::Font font, sf::String text);
    Button(sf::Vector2f pos, sf::Texture &selected, sf::Texture &unselected);
    bool MouseOver(sf::Vector2f mouse_pos);
    void SetSelection(bool select);
    bool Selected();
    void Draw(sf::RenderWindow &window);
    float GetWidth();
    float GetHeight();
    void SetTextSelection(bool select);
    sf::Vector2f GetPos();
    void SetPos(sf::Vector2f pos);
};

#endif
