#include "Fractal.h"

Fractal::Fractal(sf::Vector2f pos, int iterations) {
    this->center = pos;
    this->iterations = iterations;

    sprite.setPrimitiveType(sf::LineStrip);
    sf::Vertex v;
    v.color = kUIColor;

    float height = sqrt(pow(kLineLength, 2) - pow(kLineLength, 2) / 4);
    v.position = {pos.x, pos.y - height * 2 / 3};
    sprite.append(v);
    v.position = {pos.x + kLineLength / 2, pos.y + height / 3};
    sprite.append(v);
    v.position = {pos.x - kLineLength / 2, pos.y + height / 3};
    sprite.append(v);
    v.position = {pos.x, pos.y - height * 2 / 3};
    sprite.append(v);
}

Fractal Fractal::Iterate() {
    Fractal f(center, iterations + 1);
    f.sprite.clear();
    int i = 0;
    sf::Vertex v;
    v.color = kUIColor;
    while (i < sprite.getVertexCount() - 1) {
        sf::Vector2f edge(sprite[i + 1].position - sprite[i].position);
        sf::Vector2f normal(edge.y / 3, -edge.x / 3);
        sf::Vector2f edge_center((sprite[i].position.x + sprite[i + 1].position.x) / 2,
                                 (sprite[i].position.y + sprite[i + 1].position.y) / 2);

        f.sprite.append(sprite[i]);

        v.position = {sprite[i].position + sf::Vector2f {edge.x / 3, edge.y / 3}};
        f.sprite.append(v);

        v.position = edge_center + normal;
        f.sprite.append(v);

        v.position = {sprite[i].position + sf::Vector2f {2 * edge.x / 3, 2 * edge.y / 3}};
        f.sprite.append(v);

        f.sprite.append(sprite[i + 1]);

        ++i;
    }
    return f;
}

void Fractal::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
}