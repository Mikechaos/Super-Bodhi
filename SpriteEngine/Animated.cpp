#include "Animated.hpp"

// Par Copie
Animated::Animated(const Animated& cpy) : sf::Sprite()

{
    _currentFrame = cpy._currentFrame;
    _time = cpy._time;
    _elapsedTime = cpy._elapsedTime;
    _paused = cpy._paused;
    _anim = cpy._anim;
    _loop = cpy._loop;
}

// Par défault
Animated::Animated(bool play, bool loop, float time) : sf::Sprite()
{
    _anim = NULL;
    _currentFrame = 0;
    _time = time;
    _elapsedTime = time;
    _paused = !play;
    _loop = loop;
}

// Directement avec une Anim
Animated::Animated(Anim* newAnim, bool play, bool loop, float time) : sf::Sprite()
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
Anim* Animated::getAnim()
{
    return _anim;
}

// Passer à l'image numéro X
void Animated::setFrame(int frame)
{
    if ( _anim != NULL)
    {
        if (_anim->size() > 0)
        {
            if ((*_anim)[frame].image != NULL)
                SetImage(*((*_anim)[frame].image));

            SetSubRect((*_anim)[frame].rect);

            SetColor((*_anim)[frame].color);

            _currentFrame = frame;
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
    _paused = true;
}

// Relance la lecture
void Animated::play(Anim *sprite)
{
    _paused = false;
    if (_anim != sprite)
    _anim = sprite;
}

// Met en pause la lecture, et 'rembobine'
void Animated::stop()
{
    setFrame(0);
    _elapsedTime = _time;
    _paused = true;
}

// Est En pause ?
bool Animated::isPaused()
{
    return _paused;
}

// Est Stoppé ?
bool Animated::isStoped()
{
    return (_paused && (_currentFrame == 0) && (_elapsedTime == _time));
}

// Fonction à appeler à chaque tours de boucle, prend le temps
// écoulé depuis le dernier appel à la fonction en paramètre
void Animated::anim(float elapsedTime)
{
    // Si il n'est pas en pause et que l'animation est valide
    if (!_paused && _anim != NULL)
    {
        // on retranche le temps écoulé a notre compteur
        _elapsedTime -= elapsedTime;

        // Si Le temps entre chaque frame est atteint
        if (_elapsedTime <= 0.f)
        {
            // On réinitialise notre compteur
            _elapsedTime = _time;

            // On passe a la frame suivante
            if (_currentFrame + 1 < _anim->size())
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
