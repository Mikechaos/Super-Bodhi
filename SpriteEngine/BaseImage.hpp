#ifndef BASE_IMAGE_H
#define BASE_IMAGE_H

#include <string>


class BaseImage : public sf::Image
{
    public :

    //Prend en paramètre les variable nécessaires pour découper l'image en Frame
    BaseImage(unsigned int lineCount, unsigned int frameCount, const std::string &fileName);

    unsigned int getLineCount();
    unsigned int getFrameCount();
    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

    private :

    unsigned int _lineCount;
    unsigned int _frameCount;
    unsigned int _frameHeight;
    unsigned int _frameWidth;

};


#endif
