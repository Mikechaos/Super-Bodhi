#include "Animated.hpp"

// Par Copie
Animated::Animated(const Animated& cpy) :
sf::Sprite(cpy)
{
    _currentFrame = cpy._currentFrame;
    _time = cpy._time;
    _elapsedTime = cpy._elapsedTime;
    _paused = cpy._paused;
    _anim = cpy._anim;
    _loop = cpy._loop;
}

// Par défault
Animated::Animated(bool play, bool loop, float time)
{
    _anim = NULL;
    _currentFrame = 0;
    _time = time;
    _elapsedTime = time;
    _paused = !play;
    _loop = loop;
}

// Directement avec une Anim
Animated::Animated(Anim* newAnim, bool play, bool loop, float time)
{
    _time = time;
    _elapsedTime = time;
    _paused = !play;
    _loop = loop;
    _anim = newAnim;

    setFrame(0);
}

// Destructeur
Animated::~Animated()
{

}

// Comme 'SetImage', sauf qu'on lui fournit l'Anim
void Animated::setAnim(Anim* newAnim)
{
    _anim = newAnim;

    setFrame(0);
}

// Retourne un pointeur sur l'anim
Anim* Animated::setAnim()
{
    return _anim;
}

// Passer à l'image numéro X
void Animated::setFrame(int frame)
{
    if ( _anim != NULL)
    {
        if (_anim->Size() > 0)
        {
            if ((*_anim)[frame].image != NULL)
                setImage(*((*_anim)[frame].image));

            setSubRect((*_anim)[frame].rect);

            setColor((*_anim)[frame].color);

            _currentframe = frame;
        }
    }
}

//Retourne La frame courante
int Animated::getCurrentFrame()
{
    return _currentFrame;
}

// Fixer le temps entre chaques Frame
void Animated::setFrameTime(float Time)
{
    _time = Time;
}

// retourne le temps entre chaques Frame
float Animated::getFrameTime()
{
    return _time;
}

// Jouer en boucle ?
void Animated::setLoop(bool Loop)
{
    _loop = Loop;
}

// Jouer en boucle ?
bool Animated::isLoop()
{
    return _loop;
}

// Met en pause la lecture
void Animated::pause()
{
    Paused = true;
}

// Relance la lecture
void Animated::play(Anim *sprite)
{
    Paused = false;
    if (_anim != sprite)
    _anim = sprite;
}

// Met en pause la lecture, et 'rembobine'
void Animated::stop()
{
    setFrame(0);
    myElapsedTime = _time;
    Paused = true;
}

// Est En pause ?
bool Animated::isPaused()
{
    return Paused;
}

// Est Stoppé ?
bool Animated::isStoped()
{
    return (Paused && (_currentFrame == 0) && (myElapsedTime == _time));
}

// Fonction à appeler à chaque tours de boucle, prend le temps
// écoulé depuis le dernier appel à la fonction en paramètre
void Animated::anim(float ElapsedTime)
{
    // Si il n'est pas en pause et que l'animation est valide
    if (!Paused && _anim != NULL)
    {
        // on retranche le temps écoulé a notre compteur
        myElapsedTime -= ElapsedTime;

        // Si Le temps entre chaque frame est atteint
        if (myElapsedTime <= 0.f)
        {
            // On réinitialise notre compteur
            myElapsedTime = _time;

            // On passe a la frame suivante
            if (_currentFrame + 1 < _anim->Size())
                _currentFrame++;
            else
            {
                // Ou on a la premiere
                if (_loop)
                    _currentFrame = 0;
                else
                {
                    // Si le mode Loop est désactivé, on stop l'animation
                    stop();
                }
            }

            // On change la frame
            setFrame(_currentFrame);
        }
    }
}

float Animated::getTime()
{
    return _time;
}

void Animated::setTime(float time)
{
    _time = time;
}
