#ifndef ZIGO_FRAME
#define ZIGO_FRAME

#include <SFML/Graphics.hpp>
#include "ImageFrame.hpp"

// Une Frame est composée d'un pointeur sur une image, d'un SubRect et d'une couleur
// La couleur par défaut d'une Frame est le blanc.
class Frame
{
    public:
    // Par défaut
    Frame(const sf::Color& NewColor = sf::Color::White);

    // Par copie
    Frame(const Frame& Cpy);

    // Image et Rect
    Frame(ImageFrame *NewImage, const sf::Rect<int>& NewRect, const sf::Color& NewColor = sf::Color::White);

    // Image (Le Rect est au dimension de l'image)
    Frame(ImageFrame *NewImage, const sf::Color& NewColor = sf::Color::White);

    // destructeur
    virtual ~Frame();

    // Accès public à l'image, au Rect et à la couleur
    ImageFrame* Image;

    sf::Rect<int> Rect;

    sf::Color Color;
};

#endif // ZIGO_FRAME

