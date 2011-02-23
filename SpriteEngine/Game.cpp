#include "Game.hpp"

using namespace std;

Game::Game(const string& resFile, const string& mapFile)
{
    _graphicEngine = new GraphicEngine(resFile, mapFile);
}

void Game::mainLoop()
{
    while (true)
    {
        _graphicEngine->updateGraphics();
    }
}
