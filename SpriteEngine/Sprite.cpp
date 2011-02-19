#include "Sprite.hpp"

using namespace std;

Sprite::Sprite(string spriteParam) : _spriteImg(spriteParam)
{
    //A coder
    findCenter();
}

void Sprite::findCenter()
{
    _charAnim.SetCenter(_spriteImg.getFrameWidth()/2, _spriteImg.getFrameHeight()/2);
}
