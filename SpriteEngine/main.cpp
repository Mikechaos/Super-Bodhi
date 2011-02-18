#include "Frame.hpp"
#include "Anim.hpp"
#include "Animated.hpp"
#include "ImageFrame.hpp"
#include <iostream>
#include <cmath>

using namespace std;

enum Directions {SPR_DOWN, SPR_RIGHT, SPR_UP, SPR_LEFT, NB_DIRECTIONS};

void updateGraphics(sf::RenderWindow &Window, Animated &myCharacter);
void moveCharacter(const sf::RenderWindow &Window, Animated &myCharacter, Anim* anim);
void mainLoop(sf::RenderWindow &Window, Animated &myCharacter, Anim* anim);

int main()
{

    //Constantes initialistion de la fenetre
    const int WINDOW_W = 800;
    const int WINDOW_H = 600;
    const int PIXEL_DEPTH = 32;

    //Constantes pour separer l'image en sprites
    const int SPRITE_LINES = 4;
    const int SPRITES_PER_LINE = 8;
    const string LOAD_IMAGE = "zelda_sprite.png";

    const float FRAME_RATE = .095f;

    sf::RenderWindow Window(sf::VideoMode(WINDOW_W, WINDOW_H, PIXEL_DEPTH), "Test");
    Window.SetFramerateLimit(60);
    Window.UseVerticalSync(true);

    /* On utilise la classe ImageFrame pour directement avoir le nombre de ligne
    de sprite et le nombre de sprite par ligne*/
    ImageFrame CharacterAnim(SPRITE_LINES, SPRITES_PER_LINE, LOAD_IMAGE);

    //Constante pour avoir les coordonnees du centre du sprite
    const int IMAGE_CENTER_X = CharacterAnim.getFrameWidth()/2;
    const int IMAGE_CENTER_Y = CharacterAnim.getFrameHeight()/2;

    //Constante pour la position de depart du perso
    const int STARTING_POS_X = 400;
    const int STARTING_POS_Y = 300;

    //Pour la transparence du sprite. On recupere la couleur dans le coin superieur gauche
    CharacterAnim.CreateMaskFromColor(CharacterAnim.GetPixel(0,0));

    //Va contenir les 4 animations possibles : haut, bas, gauche, droite
    Anim anim[4];

    /* La fonction cutSprite prend en argument un ImageFrame et la ligne qu'on
    veut découper. Elle sépare ensuite chaque sprite en Frame
    Equivalent a le faire avec le constructeur de la classe Anim*/

    /*On initialise le tableau en y mettant chaque direction*/
    for (int i = 0; i < NB_DIRECTIONS; ++i)
        anim[i].cutSprite(CharacterAnim, i);

    // On crée un sprite anime avec par defaut l'animation 'GoUp', en pause, mode Loop On, Et 0.1 seconde entre chaque frame
    Animated myCharacter(&anim[SPR_UP], false, true, FRAME_RATE);

    myCharacter.SetCenter(IMAGE_CENTER_X, IMAGE_CENTER_Y);
    myCharacter.SetPosition(STARTING_POS_X, STARTING_POS_Y);

    // La boucle habituelle
    mainLoop(Window, myCharacter, anim);

    return EXIT_SUCCESS;
}

void updateGraphics(sf::RenderWindow &Window, Animated &MyCharacter)
{
    // On appelle la fonction d'animation a chaque tours en donnant le temps ecoule
    MyCharacter.anim(Window.GetFrameTime());

    Window.Clear();
    // Et on dessine
    Window.Draw(MyCharacter);

    Window.Display();
}

void moveCharacter(const sf::RenderWindow &Window, Animated &myCharacter, Anim* anim)
{
    const float speed = 100.0f;
    if (Window.GetInput().IsKeyDown(sf::Key::Up))
    {
        myCharacter.Play(&anim[SPR_UP]);
        myCharacter.Move(0, -speed*Window.GetFrameTime());
    }

    else if (Window.GetInput().IsKeyDown(sf::Key::Down))
    {
        myCharacter.Play(&anim[SPR_DOWN]);
        myCharacter.Move(0, speed*Window.GetFrameTime());
    }

    else if (Window.GetInput().IsKeyDown(sf::Key::Left))
    {
        myCharacter.Play(&anim[SPR_LEFT]);
        myCharacter.Move(-speed*Window.GetFrameTime(), 0);
    }

    else if (Window.GetInput().IsKeyDown(sf::Key::Right))
    {
        myCharacter.Play(&anim[SPR_RIGHT]);
        myCharacter.Move(speed*Window.GetFrameTime(), 0);
    }

}

void mainLoop(sf::RenderWindow &Window, Animated &myCharacter, Anim* anim)
{
    bool isRunning = true;
    while (isRunning)
    {
        sf::Event Event;
        while (Window.GetEvent(Event))
        {
            //std::cout << "Event.Key -> " << Event.Type << std::endl;
            switch (Event.Type)
            {
                case sf::Event::Closed :
                    isRunning = false;
                    break;

                case sf::Event::KeyReleased :
                    switch (Event.Key.Code)
                    {
                        case sf::Key::Escape :
                            isRunning = false;
                            break;
                        default :
                            if (!Window.GetInput().IsKeyDown(sf::Key::Up) && !Window.GetInput().IsKeyDown(sf::Key::Down) &&
                                !Window.GetInput().IsKeyDown(sf::Key::Right) && !Window.GetInput().IsKeyDown(sf::Key::Left))
                            {
                                // Si le perso arrette de se déplacer, on Stop l'animation
                                if (!myCharacter.IsStoped())
                                    myCharacter.Stop();
                            }
                            break;
                    }
                    default :
                        break;
            }
        }
        // On teste les déplacements et on update le tout
        moveCharacter(Window, myCharacter, anim);
        updateGraphics(Window, myCharacter);
    }

}
