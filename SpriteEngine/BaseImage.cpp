#include "BaseImage.hpp"
#include <iostream>
#include <sstream>

using namespace std;

BaseImage::BaseImage(const string &fileName, unsigned int lineCount, unsigned int frameCount) :
    sf::Image(), _lineCount(lineCount), _frameCount(frameCount)
{
    /*LoadFromFile(fileName);
    _frameHeight = this->GetHeight()/lineCount;
    _frameWidth = this->GetWidth()/frameCount;
    if (transparency != NONE)
        manageTransparency(transparency);*/
}

BaseImage::BaseImage(const BaseImage& cpy) : sf::Image()
{
    _lineCount = cpy._lineCount;
    _frameCount = cpy._frameCount;
    _frameHeight = cpy._frameHeight;
    _frameWidth = cpy._frameWidth;
    _transparency = cpy._transparency;
}

/*Grossier, brouillon temporaire*/
BaseImage::BaseImage(string& lvlres) : sf::Image()
{
    int i = 0;
    int j = 0;
    j = lvlres.find(' ');
    LoadFromFile(lvlres.substr(0,j));
    string s = lvlres.substr(0,j);

    i = j+1;
    j = lvlres.find(' ', i);
    istringstream ss(lvlres.substr(i,j));
    ss >> _frameCount;
    s = lvlres.substr(i,j);

    i = j+1;
    j = lvlres.find(' ', i);
    ss.str(lvlres.substr(i,j));
    ss >> _lineCount;
    s = lvlres.substr(i,j);

    i=j+1;
    ss.str(lvlres.substr(i));
    s = lvlres.substr(i,j);
    int transparency;
    ss >> transparency;
    _transparency = static_cast<TransparencyCorner>(transparency);
    if (transparency)
	manageTransparency(_transparency);
	setFrameDimension();
}

void BaseImage::setFrameDimension()
{
    _frameHeight = GetHeight()/_lineCount;
    _frameWidth = GetWidth()/_frameCount;
}

void BaseImage::manageTransparency(TransparencyCorner transparency)
{
    //Pour la transparence du sprite. On recupere la couleur dans le coin superieur gauche
    switch (transparency)
    {
        case TOP_LEFT :
            CreateMaskFromColor(this->GetPixel(0,0));
            break;
        case TOP_RIGHT :
            CreateMaskFromColor(this->GetPixel(_frameWidth,0));
            break;
        case BOT_LEFT :
            CreateMaskFromColor(this->GetPixel(0,_frameHeight));
            break;
        case BOT_RIGHT :
            CreateMaskFromColor(this->GetPixel(_frameWidth, _frameHeight));
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
    return _frameHeight;
}

unsigned int BaseImage::getFrameWidth()
{
    return _frameWidth;
}
