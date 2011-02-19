#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

#include "Tileset.hpp"
#include "Sprite.hpp"

class GraphicEngine
{

    Tileset* _tileset;
    std::vector<Sprite> _sprites;
    sf::RenderWindow _window;

    public :
    GraphicEngine(const std::string& lvlRes);

};

#endif //GRAPHIC_ENGINE_H
