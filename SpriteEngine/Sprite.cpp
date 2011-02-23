#include "Sprite.hpp"

using namespace std;

/*A coder : initialiser les attributs donc :
    -BaseImage (fait par la liste d'initialisation)
    -Anim _anim
    -Animated _charAnim
*/
Sprite::Sprite(string spriteParam) : _spriteImg(spriteParam)
{
    for (size_t i = 0; i < _spriteImg.getLineCount(); ++i)
    {
        _anim.push_back(new Anim(_spriteImg, i));
    }
    _charAnim = new Animated(_anim[0]);
    findCenter();
}

Sprite::~Sprite()
{
    for (size_t i = 0; i < _spriteImg.getLineCount(); ++i)
    {
        delete _anim[i];
    }
}

void Sprite::findCenter()
{
   _charAnim->SetCenter(_spriteImg.getFrameWidth()/2, _spriteImg.getFrameHeight()/2);
}
