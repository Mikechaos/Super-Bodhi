#ifndef IMAGE_FRAME_HPP
#define IMAGE_FRAME_HPP

#include <string>
#include <SFML/Graphics.hpp>

/*Classe permettant de decouper une image en */
class ImageFrame : public sf::Image
{
    public :

    //Prend en paramètre les variable nécessaires pour découper l'image en Frame
    ImageFrame(unsigned int nbLine, unsigned int nbSprite, const std::string &fileName);

    unsigned int getNbLine();
    unsigned int getNbSprite();
    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

    private :

    unsigned int m_nbLine;
    unsigned int m_nbSprite;
    unsigned int m_FrameHeight;
    unsigned int m_FrameWidth;

};


#endif
