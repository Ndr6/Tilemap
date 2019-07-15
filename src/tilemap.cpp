/*
** Ndr PROJECT, 2019
** Tilemap
** File description:
** tilemap
*/

#include <unistd.h>
#include <iostream>
#include "tilemap.hpp"

Tilemap::Tilemap()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Tilemap");
    if (this->window == nullptr)
        throw std::runtime_error("Error opening window");
    this->window->setFramerateLimit(30);
    this->initTexture();
    this->initSprites();
}

Tilemap::~Tilemap()
{
    this->window->close();
}

void Tilemap::run()
{
    while (this->window->isOpen()) {
        this->window->clear(sf::Color::Black);
        sf::Sprite spr;
        spr.setTexture(*(this->texture));
        this->window->draw(spr);
        this->drawMap();
        if (this->eventHandler() == 1)
            return;
    }
}

void Tilemap::drawMap()
{
    for (unsigned int y = 0; y < NB_ROW; y++) {
        for (unsigned int x = 0; x < NB_COL; x++) {
            std::cout << "Drawing [" << y << ", " << x << "]" << std::endl;
            tile[y][x]->draw(this->window);
        }
    }
}

int Tilemap::eventHandler()
{
    sf::Event event;

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            std::cout << "Closing window" << std::endl;
            return 1;
        }
    }
    return 0;
}

void Tilemap::initTexture()
{
    this->texture = new sf::Texture;
    if (!texture->loadFromFile(TILESET_FILE))
        throw std::runtime_error("Error opening tileset");
}

void Tilemap::initSprites()
{
    for (unsigned int y = 0; y < NB_ROW; y++) {
        for (unsigned int x = 0; x < NB_COL; x++) {
            tile[y][x] = new Tile(std::array<unsigned int, 2>{x, y}, 1, 0, false, *this->texture);
        }
    }
}