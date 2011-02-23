#include <iostream>
#include <fstream>

#include "GraphicEngine.hpp"

using namespace std;

/*
A coder :   Fonction pour lire fichier .res
            Fonction pour lire fichier .map

    Fonction .res
        Construit une string pour loader le tileset
        Construit un vector de string pour loader les sprites
*/
GraphicEngine::GraphicEngine(const string& resFile, const string& mapFile)
{
    ifstream res(resFile.c_str(), ios::in);
    ifstream map(mapFile.c_str(), ios::in);
    string lineRes;
    _window = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, PIXEL_DEPTH), "Test");
    _window->SetFramerateLimit(60);
    _window->UseVerticalSync(true);

    getline(res, lineRes);
    _tileset = new Tileset(lineRes);
    while(getline(res, lineRes))
    {
	_sprites.push_back(Sprite(lineRes));
    }
    _window->Draw(_sprites[0].getCharAnim());
    _window->Display();
}

GraphicEngine::~GraphicEngine()
{
    cout<<"destructor"<<endl;
    delete _tileset;
    delete _window;
}

void GraphicEngine::updateGraphics()
{
        _window->Clear();
        _window->Draw(_sprites[0].getCharAnim());
        _window->Display();
}
