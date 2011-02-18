#include "Sprite.hpp"

using namespace std;

Sprite::Sprite(string spriteParam)
{
    //A coder
    findCenter();
}

Sprite::findCenter()
{
    _charAnim.SetCenter(_spriteImage.getFrameWidth()/2, _spriteImage.getFrameHeight()/2)
}
