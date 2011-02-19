#ifndef TILESET_H
#define TILESET_H

#include <map>

#include "BaseImage.hpp"
#include "Frame.hpp"

class Tileset
{
    BaseImage _tilesetImg;
    std::map<char, Frame> _tileMap;

public:
    Tileset(std::string& tileParam);
    Tileset(const Tileset& cpy);

};

#endif //TILESET_H
