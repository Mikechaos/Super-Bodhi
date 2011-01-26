#include "Anim.hpp"
#include <iostream>

using namespace std;
// Par défaut
Anim::Anim()
{

}

Anim::Anim(ImageFrame &image, unsigned int line)
{
    cutSprite(image, line);
}

// déstructeur
Anim::~Anim()
{

}

// Par copie
Anim::Anim(const Anim& Cpy)
{
    myFrame = Cpy.myFrame;
}

// Ajouter une frame
void Anim::PushFrame(const Frame& NewFrame)
{
    myFrame.push_back(NewFrame);
}

// Nombre de frame(s)
size_t Anim::Size() const
{
    return myFrame.size();
}

// Accès a la frame numéro N
Frame& Anim::operator [] (size_t N)
{
    return myFrame[N];
}

//Découpe automatiquement une ligne d'une image en Frame
void Anim::cutSprite(ImageFrame &image, unsigned int line)
{
    unsigned int bottomCoord = image.getFrameHeight()*(line+1),
    TopCoord = image.getFrameHeight()*line,
    spriteWidth = image.getFrameWidth();
/*    cout << image.getFrameWidth() << endl << image.getFrameHeight() << endl << image.getNbSprite() << endl;*/

    for (size_t i = 0; i < image.getNbSprite(); ++i)
        PushFrame(Frame(&image, sf::Rect<int>(i*spriteWidth, TopCoord, (i+1)*spriteWidth, bottomCoord)));
}
