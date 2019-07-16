/*
** EPITECH PROJECT, 2019
** Tilemap
** File description:
** editor
*/

#include <iostream>
#include "tilemap.hpp"

inline int mod(int a, int b) {int ret = a%b; return ret>=0? ret: ret+b;}

Editor::Editor(std::array<std::array<Tile *, NB_COL>, NB_ROW> *tile, sf::Texture *texture)
    : enabled(false), selected_id(1), selected_rotation(0), tile(tile),texture(texture)
{
    this->selector_pos[0] = 0;
    this->selector_pos[1] = 0;

    this->selector_tex = new sf::Texture;
    if (!this->selector_tex->loadFromFile(SELECTOR_FILE))
        throw std::runtime_error("Error loading selector image");

    this->selector_spr = new sf::Sprite;
    this->selector_spr->setTexture(*this->selector_tex);
    this->selector_spr->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->selector_spr->setPosition(sf::Vector2f(SIZE_X * this->selector_pos[0], SIZE_Y * this->selector_pos[1]));

    this->preview_spr = new sf::Sprite;
    this->preview_spr->setTexture(*this->texture);
    this->preview_spr->setTextureRect(sf::IntRect((this->selected_id % 10) * SIZE_X, (this->selected_id / 10) * SIZE_Y, SIZE_X, SIZE_Y));
    this->preview_spr->setOrigin(16, 16);
    this->preview_spr->setPosition(sf::Vector2f(450 + 16, 1040 + 16));

    if (!this->font.loadFromFile(FONT_FILE))
        throw std::runtime_error("Error loading font");
    this->preview_text.setFont(this->font);
    this->preview_text.setString("Selected tile (): ");
    this->preview_text.setCharacterSize(32);
    this->preview_text.setPosition(16, 1040);

}

Editor::~Editor()
{
    delete(this->selector_spr);
    delete(this->selector_tex);
}

void Editor::handler(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            return this->disable();
        }
        else if (event.type == sf::Event::KeyPressed)
            return this->keyboardHandler(event);
    }
    window->draw(*this->selector_spr);
    window->draw(*this->preview_spr);
    window->draw(this->preview_text);
}

void Editor::keyboardHandler(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Up)
        this->selector_pos[1] = mod((this->selector_pos[1] - 1),NB_ROW);
    if (event.key.code == sf::Keyboard::Down)
        this->selector_pos[1] = mod((this->selector_pos[1] + 1), NB_ROW);
    if (event.key.code == sf::Keyboard::Left)
        this->selector_pos[0] = mod((this->selector_pos[0] - 1), NB_COL);
    if (event.key.code == sf::Keyboard::Right)
        this->selector_pos[0] = mod((this->selector_pos[0] + 1), NB_COL);
    if (event.key.code == sf::Keyboard::PageUp) {
        this->selected_id++;
        this->updatePreview();
    }
    if (event.key.code == sf::Keyboard::PageDown) {
        this->selected_id--;
        this->updatePreview();
    }
    if (event.key.code == sf::Keyboard::Num1) {
        this->selected_rotation = mod(this->selected_rotation - 1, 4);
        this->updatePreview();
    }
    if (event.key.code == sf::Keyboard::Num2) {
        this->selected_rotation = mod(this->selected_rotation + 1, 4);
        this->updatePreview();
    }
    if (event.key.code == sf::Keyboard::Space)
        this->setTile();
    this->updateSelector();
}

void Editor::updatePreview()
{
    this->preview_spr->setTextureRect(sf::IntRect((this->selected_id % 10) * SIZE_X, (this->selected_id / 10) * SIZE_Y, SIZE_X, SIZE_Y));
    this->preview_spr->setRotation(90 * this->selected_rotation);
}

void Editor::setTile()
{
    this->tile->at(selector_pos[1]).at(selector_pos[0])->setId(this->selected_id);
    this->tile->at(selector_pos[1]).at(selector_pos[0])->setRotation(this->selected_rotation);
}

void Editor::updateSelector()
{
    this->selector_spr->setPosition(sf::Vector2f(SIZE_X * this->selector_pos[0], SIZE_Y * this->selector_pos[1]));
}

void Editor::enable()
{
    std::cout << "Enabling editor." << std::endl;
    this->enabled = true;
}

void Editor::disable()
{
    std::cout << "Disabling editor." << std::endl;
    this->enabled = false;
}

bool Editor::get_status()
{
    return this->enabled;
}