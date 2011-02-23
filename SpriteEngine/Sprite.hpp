#ifndef SPRITE_H
#define SPRITE_H

#include "BaseImage.hpp"
#include "Animated.hpp"
#include "Anim.hpp"
#include "Position.hpp"

/*A coder :
    La fonction pour setter l'animation actuelle (_charAnim)
*/

class Sprite
{
    BaseImage _spriteImg;
    Animated* _charAnim;
    std::vector<Anim*> _anim;

public :

    Sprite(std::string spriteParam);
    ~Sprite();

    Animated getCharAnim() const {return *_charAnim;}

private :

    void findCenter();
};

#endif //SPRITE_H
