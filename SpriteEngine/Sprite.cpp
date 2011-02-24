#include <iostream>

#include "Sprite.hpp"

using namespace std;

/*A coder : initialiser les attributs donc :
    -BaseImage (fait par la liste d'initialisation)
    -Anim _anim
    -Animated _charAnim
*/
Sprite::Sprite(string spriteParam) : _spriteImg(spriteParam), _charAnim()
{
    for (size_t i = 0; i < _spriteImg.getLineCount(); ++i)
    {
        _anim.push_back(new Anim(_spriteImg, i));
    }
    _charAnim.setAnim(_anim[0]);
    findCenter();
    setPosition(sf::Vector2f(50, 50));
}

Sprite::~Sprite()
{
    for (size_t i = 0; i < _spriteImg.getLineCount(); ++i)
    {
        delete _anim[i];
    }
}

void Sprite::setPosition(const sf::Vector2f& pos)
{
    _charAnim.SetPosition(pos);
}

void Sprite::drawSprite(sf::RenderWindow* window)
{
    window->Draw(_charAnim);
    cout<<"pos_x"<<_charAnim.GetPosition().x<<"\npos_y"<<_charAnim.GetPosition().y;
}

void Sprite::findCenter()
{
   _charAnim.SetCenter(_spriteImg.getFrameWidth()/2, _spriteImg.getFrameHeight()/2);
}
