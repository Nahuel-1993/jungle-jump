#include <SFML/Graphics.hpp>
#include "Personaje.h"

int main()
{
    ///INICIALIZACIÓN DE LA VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUNGLE JUMP"); ///Es el tamaño del juego, primero ancho y después alto
    window.setFramerateLimit(60); ///Le indicamos que se actualiza solamente a 60 por segundo(velocidad de movimiento de Alan)

    Personaje alan;

     /*sf::Sprite personaje; ///El sprite es un pedazo de la imagen o textura -Personaje es un objeto de la clase sprite
     sf::Texture personaje_text;
     float velocity = 3; ///Seleccionamos la velocidad con la que queremos que se mueva nuestro personaje
    */



    ///GAME LOOP (UPDATE DEL JUEGO)
    while (window.isOpen())
    {
        ///ReadInput -> Actualiza los estados de los perifericos de entrada
        ///Leer la cola de mensaje (poll event)
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        ///En SFML la coordenada (0,0) Es la esquina superior izquierda

        ///Update - Actualiza los estados del juego

;        alan.update();

        /// Se limpia la pantalla
        window.clear();

        alan.draw(window);

        ///Draw - Dibuja el personaje por la pantalla
        ///window.draw(alan);

        ///Display - Flip
        window.display();




    }

    ///LIBERACION DEL JUEGO
    return 0;
}
