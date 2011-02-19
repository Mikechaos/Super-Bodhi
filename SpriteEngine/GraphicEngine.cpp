#include <fstream>

#include "GraphicEngine.hpp"

using namespace std;

GraphicEngine::GraphicEngine(const string& lvlres)
{
    int WINDOW_W = 800;
    int WINDOW_H = 600;
    int PIXEL_DEPTH = 32;
    ifstream res(lvlres.c_str(), ios::in);
    string lineRes;
    sf::RenderWindow Window(sf::VideoMode(WINDOW_W, WINDOW_H, PIXEL_DEPTH), "Test");
    Window.SetFramerateLimit(60);
    Window.UseVerticalSync(true);

    getline(res, lineRes);
    _tileset = new Tileset(lineRes);
    while(getline(res, lineRes))
    {
	_sprites.push_back(Sprite(lineRes));
    }
    Window.Draw(_sprites[0].getCharAnim());
    Window.Display();
}

