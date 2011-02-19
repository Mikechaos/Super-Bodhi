#ifndef FRAME_H
#define FRAME_H

#include <SFML/Graphics.hpp>
#include "BaseImage.hpp"

// Une Frame est composée d'un pointeur sur une image, d'un SubRect et d'une couleur
// La couleur par défaut d'une Frame est le blanc.
class Frame
{
    public:

    // Accès public à l'image, au Rect et à la couleur
    BaseImage* image;

    sf::Rect<int> rect;

    sf::Color color;

    // Par défaut
    Frame(const sf::Color& NewColor = sf::Color::White);

    // Par copie
    Frame(const Frame& Cpy);

    // Image et Rect
    Frame(BaseImage *NewImage, const sf::Rect<int>& NewRect, const sf::Color& NewColor = sf::Color::White);

    // Image (Le Rect est au dimension de l'image)
    Frame(BaseImage *NewImage, const sf::Color& NewColor = sf::Color::White);

    // destructeur
    ~Frame();


};

#endif // FRAME_H

