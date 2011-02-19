#include "Tileset.hpp"

using namespace std;

Tileset::Tileset(string& tileParam) : _tilesetImg(tileParam)
{
}

Tileset::Tileset(const Tileset& cpy) : _tilesetImg(cpy._tilesetImg)
{
    _tileMap = cpy._tileMap;
}
