#include "BaseImage.hpp"
#include <iostream>

using namespace std;

BaseImage::BaseImage(unsigned int lineCount, unsigned int frameCount,
		     const string &fileName, TransparencyCorner transparency) :
    sf::Image(), _lineCount(lineCount), _frameCount(frameCount), _transparency(transparency)
{
    LoadFromFile(fileName);
    _FrameHeight = this->GetHeight()/lineCount;
    _FrameWidth = this->GetWidth()/frameCount;
    if (_transparency)
        manageTransparency();
}

void BaseImage::manageTransparency()
{
    //Pour la transparence du sprite. On recupere la couleur dans le coin superieur gauche
    switch (_transparency)
    {
        case TOP_LEFT :
            CreateMaskFromColor(this->GetPixel(0,0));
            break;
        case TOP_RIGHT :
            CreateMaskFromColor(this->GetPixel(_FrameWidth,0));
            break;
        case BOT_LEFT :
            CreateMaskFromColor(this->GetPixel(0,_FrameHeight));
            break;
        case BOT_RIGHT :
            CreateMaskFromColor(this->GetPixel(_FrameWidth, _FrameHeight));
            break;
        case NONE :
            break;

    }
}

unsigned int BaseImage::getLineCount()
{
    return _lineCount;
}

unsigned int BaseImage::getFrameCount()
{
    return _frameCount;
}

unsigned int BaseImage::getFrameHeight()
{
    return _FrameHeight;
}

unsigned int BaseImage::getFrameWidth()
{
    return _FrameWidth;
}
