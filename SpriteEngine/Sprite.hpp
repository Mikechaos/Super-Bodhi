#ifndef SPRITE_H
#define SPRITE_H

#include "BaseImage.hpp"
#include "Animated.hpp"
#include "Anim.hpp"
#include "Position.hpp"

class Sprite
{
    BaseImage _spriteImg;
    Animated _charAnim;
    std::vector<Anim> _anim;

public :

    Sprite(std::string spriteParam);

    Animated getCharAnim() const {return _charAnim;}

private :

    void findCenter();
};

#endif //SPRITE_H
