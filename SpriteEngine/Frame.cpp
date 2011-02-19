#include "Frame.hpp"

// Par défaut
Frame::Frame(const sf::Color& newColor)
{
    image = NULL;
    color = newColor;
}

// Par copie
Frame::Frame(const Frame& cpy)
{
    image = cpy.image;
    rect = cpy.rect;
    color = cpy.color;
}

// Image et Rect
Frame::Frame(BaseImage* newImage, const sf::Rect<int>& newRect, const sf::Color& newColor)
{
    image = newImage;
    rect = newRect;
    color = newColor;
}

// Image (Le Rect est au dimension de l'image)
Frame::Frame(BaseImage* newImage, const sf::Color& newColor)
{
    image = newImage;
    if (image != NULL)
        rect = sf::Rect<int>(0, 0, image->GetWidth(), image->GetHeight());

    color = newColor;
}

// destructeur
Frame::~Frame()
{

}

