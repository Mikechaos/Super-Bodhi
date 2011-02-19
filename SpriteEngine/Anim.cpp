#include "Anim.hpp"
#include <iostream>

using namespace std;
// Par défaut
Anim::Anim()
{

}

Anim::Anim(BaseImage &image, unsigned int line)
{
    cutSprite(image, line);
}

// déstructeur
Anim::~Anim()
{

}

// Par copie
Anim::Anim(const Anim& cpy)
{
    _frame = cpy._frame;
}

// Ajouter une frame
void Anim::pushFrame(const Frame& newFrame)
{
    _frame.push_back(newFrame);
}

// Nombre de frame(s)
size_t Anim::size() const
{
    return _frame.size();
}

// Accès a la frame n
Frame& Anim::operator [] (size_t n)
{
    return _frame[n];
}

//Découpe automatiquement une ligne d'une image en Frame
void Anim::cutSprite(BaseImage &image, unsigned int line)
{
    unsigned int bottomCoord = image.getFrameHeight()*(line+1),
    topCoord = image.getFrameHeight()*line,
    spriteWidth = image.getFrameWidth();

    for (size_t i = 0; i < image.getFrameCount(); ++i)
        pushFrame(Frame(&image, sf::Rect<int>(i*spriteWidth, topCoord, (i+1)*spriteWidth, bottomCoord)));
}
