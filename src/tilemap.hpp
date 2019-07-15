/*
** Ndr PROJECT, 2019
** Tilemap
** File description:
** tilemap
*/

#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <array>
#include <SFML/Graphics.hpp>

#define NB_COL 60
#define NB_ROW 32

#define SIZE_X 32
#define SIZE_Y 32

#define X_MAP_START 0
#define Y_MAP_START 28

#define TILESET_FILE "asset/tile1.png"
#define BACKGROUND_FILE "asset/bg.jpeg"

class Tile {
    public:
        Tile(std::array<unsigned int, 2>, int nb, unsigned int orientation, int warp, bool block, sf::Texture &);
        virtual ~Tile();

        void draw(sf::RenderWindow *);

    private:
        unsigned int nb;
        unsigned int orientation;
        unsigned int warp;
        bool block;
        sf::Sprite *sprite;
};

class Tilemap {
    public:
        Tilemap();
        virtual ~Tilemap();

        void run();
    private:
        void initSprites();
        void initTexture();
        void initBack();
        void drawBack();
        void drawMap();
        int eventHandler();

        std::array<std::array<Tile *, NB_COL>, NB_ROW> tile;
        sf::RenderWindow *window;
        sf::Texture *texture;
        sf::Texture *bg_tex;
        sf::Sprite *bg_spr;
};

#endif /* !TILEMAP_HPP_ */
