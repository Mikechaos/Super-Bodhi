#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Tileset.h"
#include "Sprite.h"

class GraphicEngine
{
    Tileset _tileSet
    std::vector<Sprite> _sprites
    sf::RenderWindow _window

    public :
    GraphicEngine(fstream levelRes);

};

#endif //GRAPHIC_ENGINE_H
