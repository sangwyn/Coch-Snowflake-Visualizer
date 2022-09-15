#include "Fractal.h"

Fractal::Fractal(sf::Vector2f pos, int iterations) {
    this->center = pos;
    this->iterations = iterations;

    sprite.setPrimitiveType(sf::LineStrip);
    sf::Vertex v;
    v.color = kUIColor;

    if (iterations == 0) {
        v.position = {pos.x, pos.y - kLineLength};
        sprite.append(v);
        v.position = {pos.x + kLineLength / 2, pos.y};
        sprite.append(v);
        v.position = {pos.x - kLineLength / 2, pos.y};
        sprite.append(v);
        v.position = {pos.x, pos.y - kLineLength};
        sprite.append(v);
//        float height = sqrt(pow(kLineLength, 2) - pow(kLineLength / 2, 2));
//        v.position = {pos.x, pos.y - height * 2 / 3};
//        sprite.append(v);
//        v.position = {pos.x + kLineLength / 2, pos.y + height / 3};
//        sprite.append(v);
//        v.position = {pos.x - kLineLength / 2, pos.y + height / 3};
//        sprite.append(v);
//        v.position = {pos.x, pos.y - height * 2 / 3};
//        sprite.append(v);
    }
}

Fractal Fractal::Iterate() {
    Fractal f(center, iterations + 1);
//    f.sprite.clear();
    int i = 0;
    sf::Vertex v;
    v.color = kUIColor;
    while (i < sprite.getVertexCount() - 1) {
        sf::Vector2f edge((sf::Vector2f)sprite[i + 1].position - (sf::Vector2f)sprite[i].position);
        sf::Vector2f normal((float)edge.y / 3.0, (float)-edge.x / 3.0);
        sf::Vector2f edge_center(((float)sprite[i].position.x + (float)sprite[i + 1].position.x) / 2,
                                 ((float)sprite[i].position.y + (float)sprite[i + 1].position.y) / 2);

        f.sprite.append(sprite[i]);

        v.position = {(sf::Vector2f)sprite[i].position + sf::Vector2f {edge.x / 3, edge.y / 3}};
        f.sprite.append(v);

        v.position = edge_center + normal;
        f.sprite.append(v);

        v.position = {(sf::Vector2f)sprite[i].position + sf::Vector2f {2 * edge.x / 3, 2 * edge.y / 3}};
        f.sprite.append(v);

        f.sprite.append(sprite[i + 1]);

        ++i;
    }
    return f;
}

void Fractal::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
}