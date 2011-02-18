#ifndef TILESET_H
#define TILESET_H

#include <map>

#include "BaseImage.h"
#include "Frame.h"

class Tileset
{
    BaseImage _tilesetImg;
    std::map<char, Frame> _tileMap;

public:
    Tileset(std::string tileParam);

};

#endif //TILESET_H
