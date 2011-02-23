#ifndef GAME_H
#define GAME_H

#include "GraphicEngine.hpp"

class Game
{
    GraphicEngine* _graphicEngine;

    public :

    Game(const std::string& resFile, const std::string& mapFile);

    void mainLoop();

};

#endif
