#ifndef ANIMATED_H
#define ANIMATED_H

#include "Anim.hpp"

// Un sprite animé

// Il est composé de :

// Le temps écoulé entre chaque frame
// Un pointeur sur l'animation qu'il doit lire

// Des fonctions de lecture :
// Play, Pause, Stop, Loop
class Animated : public sf::Sprite
{
    public:

    // Par Copie
    Animated(const Animated& Cpy);

    // Par défault
    Animated(bool play = false, bool loop = true, float time = 0.f);

    // Directement avec une Anim
    Animated(Anim* newAnim, bool play = false, bool loop = true, float time = 0.f);

    // Destructeur
    virtual ~Animated();

    // Comme 'SetImage', sauf qu'on lui fournit l'Anim
    void setAnim(Anim* newAnim);

    // Retourne un pointeur sur l'anim
    Anim* getAnim();

    // Passer à l'image numéro X
    void setFrame(int frame);

    // Retourne la Frame courante
    int getCurrentFrame();

    // Fixer le temps entre chaques Frame
    void setFrameTime(float time);

    // Retourne le temps entre chaques Frame
    float getFrameTime();

    // Jouer en boucle ?
    void setLoop(bool loop);

    // Jouer en boucle ?
    bool isLoop();

    // Met en pause la lecture
    void pause();

    // Relance la lecture
    void play(Anim* sprite);

    // Met en pause la lecture, et 'rembobine'
    void stop();

    // Est en pause ?
    bool isPaused();

    // Est stoppé ?
    bool isStoped();

    float getTime();

    void setTime(float time);

    // Fonction à appeler à chaque tour de boucle, prend le temps
    // écoulé depuis le dernier appel à la fonction en paramètre
    void anim(float ElapsedTime);

    private:
    float _time;
    float _elapsedTime;
    bool _paused;
    bool _loop;
    Anim* _anim;
    int _currentFrame;
};

#endif //ANIMATED_H

