#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

#include "Tileset.hpp"
#include "Sprite.hpp"

/*A verifier : Pourquoi le sprite ne s'affiche pas dans la fenetre de test*/

class GraphicEngine
{
    static const int WINDOW_W = 800;
    static const int WINDOW_H = 600;
    static const int PIXEL_DEPTH = 32;

    Tileset* _tileset;
    std::vector<Sprite> _sprites;
    sf::RenderWindow* _window;

    public :

    GraphicEngine(const std::string& resFile, const std::string& mapFile);
    ~GraphicEngine();

    sf::RenderWindow* getWindow() const {return _window;}
    void updateGraphics();

};

#endif //GRAPHIC_ENGINE_H
