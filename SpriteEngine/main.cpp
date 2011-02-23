#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

using namespace std;

int main()
{
    const string niveauRes = "niveau1.res";
    const string niveauMap = "niveau1.map";
    Game game(niveauRes, niveauMap);
    game.mainLoop();
    return EXIT_SUCCESS;
}
