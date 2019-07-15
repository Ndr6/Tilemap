/*
** Ndr PROJECT, 2019
** Tilemap
** File description:
** tile
*/

#include "tilemap.hpp"

Tile::Tile(std::array<unsigned int, 2> pos, int nb, unsigned int orientation, int warp, bool block, sf::Texture &texture)
: nb(nb), orientation(orientation), warp(warp), block(block)
{
    std::array<unsigned int, 2> pixel_pos = {X_MAP_START + pos[0] * SIZE_X, Y_MAP_START + pos[1] * SIZE_Y};

    this->sprite = new sf::Sprite;

    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(((nb - 1) % 10) * SIZE_X, ((nb - 1) / 10) * SIZE_Y, SIZE_X, SIZE_Y));

    this->sprite->setPosition(sf::Vector2f(pixel_pos[0], pixel_pos[1]));

    this->sprite->setOrigin(sf::Vector2f(16, 16));
    this->sprite->setRotation(90 * orientation);
}

Tile::~Tile()
{
    delete(this->sprite);
}

void Tile::draw(sf::RenderWindow *window)
{
    window->draw(*this->sprite);
}