#ifndef BASE_IMAGE_H
#define BASE_IMAGE_H

#include <string>
#include <SFML/Graphics.hpp>

enum TransparencyCorner {NONE, TOP_LEFT, TOP_RIGHT, BOT_LEFT, BOT_RIGHT};

class BaseImage : public sf::Image
{
    unsigned int _lineCount;
    unsigned int _frameCount;
    unsigned int _frameHeight;
    unsigned int _frameWidth;
    TransparencyCorner _transparency;

    public :

    //Prend en paramètre les variable nécessaires pour découper l'image en Frame
    BaseImage(const std::string &fileName, unsigned int lineCount, unsigned int frameCount);
    BaseImage(const BaseImage& cpy);
    BaseImage(std::string& lvlres);

    unsigned int getLineCount();
    unsigned int getFrameCount();
    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

    private :

    void manageTransparency(TransparencyCorner transparency);

};


#endif
