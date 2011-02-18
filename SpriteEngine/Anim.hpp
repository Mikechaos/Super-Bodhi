#ifndef ZIGO_ANIM
#define ZIGO_ANIM

#include <vector>

#include "Frame.hpp"
#include "ImageFrame.hpp"

// La classe animation n'est qu'un 'vector' de Frame
class Anim
{
    public:

    // par défaut
    Anim();

    Anim(ImageFrame &image, unsigned int line);

    // destructeur
    virtual ~Anim();

    // Par copie
    Anim(const Anim& cpy);

    // Ajouter un Frame
    void pushFrame(const Frame& newFrame);

    // Nombre de Frame(s)
    size_t size() const;

    // Accès a la frame numéro N
    Frame& operator [] (size_t n);

    //Découpe automatiquement une ligne d'une image en Frame
    void cutSprite(ImageFrame &image, unsigned int line);

    // Plus tard, nous pourrons ajouter différentes fonctions liées au fait qu'une 'Anim' est une ressource
    // Par exemple : LoadFromFile, SaveToFile etc...

    private:
    std::vector< Frame > _frame;

};
#endif
