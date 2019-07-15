/*
** NDR PROJECT, 2019
** Tilemap
** File description:
** main
*/

#include <iostream>
#include <exception>
#include "tilemap.hpp"

int main(void)
{
    try {
        Tilemap tilemap;
        tilemap.run();
    }
    catch(const std::exception& e) {
        std::cout << "An error occured." << std::endl;
        return 84;
    }
    return 0;
}