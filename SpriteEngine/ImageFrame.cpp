#include "ImageFrame.hpp"
#include <iostream>

using namespace std;

ImageFrame::ImageFrame(unsigned int nbLine, unsigned int nbSprite, const string &fileName) : sf::Image(), m_nbLine(nbLine), m_nbSprite(nbSprite)
{
    LoadFromFile(fileName);
    m_FrameHeight = this->GetHeight()/nbLine;
    m_FrameWidth = this->GetWidth()/nbSprite;
/*    cout << "image Width and Height (" << this->GetWidth() << ", " << this->GetHeight() << endl;*/
}

unsigned int ImageFrame::getNbLine()
{
    return m_nbLine;
}

unsigned int ImageFrame::getNbSprite()
{
    return m_nbSprite;
}

unsigned int ImageFrame::getFrameHeight()
{
    return m_FrameHeight;
}

unsigned int ImageFrame::getFrameWidth()
{
    return m_FrameWidth;
}
