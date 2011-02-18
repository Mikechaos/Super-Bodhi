#ifndef SPRITE_H
#define SPRITE_H

#include "BaseImage.h"
#include "Animated.h"
#include "Anim.h"
#include "Position.h"

class Sprite
{
    BaseImage _spriteImage;
    Animated _charAnim;
    std::vector<Anim> _anim;

public :

    Sprite(std::string spriteParam);

private :
    
    Position findCenter();
};

#endif //SPRITE_H
