#include "Personaje.h"

Personaje::Personaje(){

    _velocity =4;
    _textura.loadFromFile("alan.png");

    _sprite.setTexture(_textura);
}

void Personaje::update(){

    ///CMD (Comandos) -> Para saber qué se apretó - Se ejecutan los comandos

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ ///Cada vez se aprieta el teclado hacia arriba
            _sprite.move(0, -_velocity); ///X=0, y=-1 Va a parecer que se mueve para arriba
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            _sprite.move(-_velocity,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            _sprite.move(_velocity,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            _sprite.move(0,_velocity);
        }

        ///PARA EVITAR QUE SE VAYA DE LA PANTALLA
        if(_sprite.getPosition().x<0){ ///Si el personaje trata de moverse a un x negativo
            _sprite.setPosition(0, _sprite.getPosition().y); ///Lo pongo en 0 evitando que se transofrme en negativo
        }
        if(_sprite.getPosition().x>700){ ///Para que no se salga de la pantalla por la derecha
            _sprite.setPosition(650, _sprite.getPosition().y);
        }
        ///Así hice yo y funcionó
        if(_sprite.getPosition().y<0){ ///Para que no se vaya por arriba de la pantalla
            _sprite.setPosition(_sprite.getPosition().x, 0);
        }
        /*if(_sprite.getPosition().y>475){ ///Para que no se vaya por abajo de la pantalla
            _sprite.setPosition(_sprite.getPosition().x, 475);
        }*/
        //Así hizo Brian

        if(_sprite.getPosition().x+_sprite.getGlobalBounds().width > 800){
            _sprite.setPosition(800- _sprite.getGlobalBounds().width, _sprite.getPosition().y);
        }
        if(_sprite.getPosition().y+_sprite.getGlobalBounds().height > 600){
            _sprite.setPosition(_sprite.getPosition().x, 600-_sprite.getGlobalBounds().height);
        }

}

void Personaje::draw(sf::RenderWindow& window){
    window.draw(_sprite);
}
