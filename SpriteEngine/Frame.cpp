#include "Frame.hpp"

// Par défaut
Frame::Frame(const sf::Color& newColor)
{
    _image = NULL;
    _color = NewColor;
}

// Par copie
Frame::Frame(const Frame& cpy)
{
    _image = cpy.Image;
    _rect = cpy.Rect;
    _color = cpy.Color;
}

// Image et Rect
Frame::Frame(BaseImage* newImage, const sf::Rect<int>& newRect, const sf::Color& newColor)
{
    _image = newImage;
    _rect = newRect;
    _color = newColor;
}

// Image (Le Rect est au dimension de l'image)
Frame::Frame(BaseImage* newImage, const sf::Color& newColor)
{
    _image = newImage;
    if (image != NULL)
        _rect = sf::Rect<int>(0, 0, image->GetWidth(), image->GetHeight());

    _color = newColor;
}

// destructeur
Frame::~Frame()
{

}

