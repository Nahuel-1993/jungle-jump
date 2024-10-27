#pragma once
#include <SFML/Graphics.hpp>

class Personaje{
    private:
        sf::Sprite _sprite;
        sf::Texture _textura;
        float _velocity;

    public:
        Personaje();///Constructor de personaje
        void update();
        void draw(sf:: RenderWindow&);

            /*void draw(sf::RenderWindow& window){
                window.draw(_sprite);
            }*/

};
