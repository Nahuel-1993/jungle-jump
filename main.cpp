#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Banana.h"
#include "Maracuya.h"
#include "Camu.h"
#include "Bacaba.h"
#include "RespawnFruta.h"
#include "Gameplay.h"
#include <iostream>
#include "rlutil.h" ///Librería para mejoreas del menú

int main()
{
    std::srand((unsigned)std::time(0));
/*
    int op;
    rlutil::setBackgroundColor(rlutil::GREEN); ///CAMBIAMOS EL COLOR DE FONDO DE LA CONSOLA

    do{
            rlutil::cls(); ///Limpia la pantalla cada vez que se elije una opción
            rlutil::locate(45,9); ///Ubicamos el texto en el medio de la pantalla
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,10);
            std::cout<<"    JUGAR " << std::endl;
            rlutil::locate(45,11);
            std::cout<<"    ESTADISTICA " << std::endl;
            rlutil::locate(45,12);
            std::cout<<"    CREDITOS " << std::endl;
            rlutil::locate(45,13);
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,14);
            std::cout<<"    SALIR " << std::endl;
            rlutil::locate(45,15);
            std::cout<<"------------------------------"<<std::endl;
            rlutil::locate(45,16);
            std::cout << (char)158 << std::endl;
            std::cin >> op;
            //std::system("pause");
            //std::system("cls");
    } while (op != 0);
*/

    ///Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jungle Jump");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("pixel.ttf"); //Carga la fuente para visualizar el puntaje

    /// Configuro texto
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("bite.wav"); //Cargamos un efecto de sonido para la colision

    sf::Sound sound; //Es el canal por donde vamos a reproducir el audio
    sound.setBuffer(buffer);


    Personaje alan;

    /// Crea frutas y las pone en un vector
    std::vector<Fruta*> frutas = {new Banana(), new Maracuya(), new Bacaba(), new Camu()};

    /// Selecciona una fruta al azar para el primer respawn
    int indiceFrutaActual = std::rand() % frutas.size();
    Fruta* frutaActual = frutas[indiceFrutaActual];
    frutaActual->respawn();

    /// Crea el reloj para controlar el tiempo de respawn
    sf::Clock relojRespawn;

    bool enRespawn = false;

    int puntos = 0;

    ///Creamos el fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("FONDO.png");

    image.setTexture(tex);


    ///Game Loop (update del juego) *Se subdivide internamente*

    gameplay(window, alan, frutas, frutaActual, indiceFrutaActual, relojRespawn, enRespawn, puntos, sound, text, image);

    /// Liberacion del juego (Con SFML no hace falta)

    return 0;
}
