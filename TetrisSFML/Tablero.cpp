/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.cpp
 * Author: pablomanez
 * 
 * Created on 9 de febrero de 2018, 0:14
 */

#include <SFML/Graphics.hpp>

#include "Bloque.h"
#include "Tablero.h"

Tablero::Tablero() {
    //INICIALIZAR EL TABLERO
    sf::ConvexShape tablero(9);
    tablero.setFillColor(sf::Color::Black);
    tablero.setOutlineThickness(1);
    tablero.setOutlineColor(sf::Color::White);
    tablero.setPoint(0,sf::Vector2f(0,0));
    tablero.setPoint(1,sf::Vector2f(0,480));
    tablero.setPoint(2,sf::Vector2f(640,480));
    tablero.setPoint(3,sf::Vector2f(640,0));
    tablero.setPoint(4,sf::Vector2f(211,0));
    tablero.setPoint(5,sf::Vector2f(211,400));
    tablero.setPoint(6,sf::Vector2f(10,400));
    tablero.setPoint(7,sf::Vector2f(10,0));
    tablero.setPoint(8,sf::Vector2f(0,0));
    
    this->shape = tablero;
    
    this->bloques = new Bloque*[10]();
    
    for(int i=0 ; i<10 ; i++){
        this->bloques[i] = new Bloque[20]();
    }
    
}

void Tablero::Dibujar(sf::RenderWindow& window) {
    window.draw(this->shape);
}


Tablero::Tablero(const Tablero& orig) {
}

Tablero::~Tablero() {
}

