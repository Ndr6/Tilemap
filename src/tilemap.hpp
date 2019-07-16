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
#define Y_MAP_START 0

#define TILESET_FILE "asset/tile1.png"
#define BACKGROUND_FILE "asset/bg.jpeg"
#define SELECTOR_FILE "asset/editor_select.png"

#define FONT_FILE "asset/Fipps-Regular.otf"

class Tile {
    public:
        Tile(std::array<unsigned int, 2>, int nb, unsigned int orientation, int warp, bool block, sf::Texture &);
        virtual ~Tile();

        void draw(sf::RenderWindow *);
        void setId(unsigned int id);
        void setRotation(unsigned int rot);

    private:
        unsigned int nb;
        unsigned int orientation;
        unsigned int warp;
        bool block;
        sf::Sprite *sprite;
};

class Editor {
    public:
        Editor(std::array<std::array<Tile *, NB_COL>, NB_ROW> *tiles, sf::Texture *);
        virtual ~Editor();

        void enable();
        bool get_status();
        void handler(sf::RenderWindow *);
        void moveSelector();

    private:
        bool enabled;
        void disable();

        sf::Texture *selector_tex;
        sf::Sprite *selector_spr;
        std::array<int, 2> selector_pos;
        void updateSelector();

        sf::Font font;
        sf::Text preview_text;
        sf::Sprite *preview_spr;
        void updatePreview();

        unsigned int selected_id;
        unsigned int selected_rotation;
        void setTile();

        void keyboardHandler(sf::Event);

        std::array<std::array<Tile *, NB_COL>, NB_ROW> *tile;
        sf::Texture *texture;
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
        int keyboardHandler(sf::Event);

        std::array<std::array<Tile *, NB_COL>, NB_ROW> tile;
        sf::RenderWindow *window;
        sf::Texture *texture;
        sf::Texture *bg_tex;
        sf::Sprite *bg_spr;

        Editor *editor;
};

#endif /* !TILEMAP_HPP_ */
