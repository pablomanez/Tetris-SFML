/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.h
 * Author: pablomanez
 *
 * Created on 7 de febrero de 2018, 17:41
 */

#ifndef BLOQUE_H
#define BLOQUE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Bloque {
public:
    Bloque();
    Bloque(const Bloque& orig);
    
    void Dibujar(sf::RenderWindow& window);
    void Mover(char d);
    void Mover(sf::Vector2f d);
    bool Colisiona(Bloque b1);
    
    //SETTER
    void setPosicion(sf::Vector2f pos);
    void setColor(sf::Color color);
    void setBorde(sf::Color color);
    
    //GETTER
    sf::Vector2f getPosicion();
    sf::Color getColor();
    
    virtual ~Bloque();
private:
    sf::Vector2f coordenadas;
    sf::RectangleShape shape;

};

#endif /* BLOQUE_H */

