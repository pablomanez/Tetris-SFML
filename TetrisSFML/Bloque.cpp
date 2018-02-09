/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.cpp
 * Author: pablomanez
 * 
 * Created on 7 de febrero de 2018, 17:41
 */

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "Bloque.h"

Bloque::Bloque() {
    
    this->shape.setSize(sf::Vector2f(1,1));
    this->shape.scale(sf::Vector2f(20,20));
    this->shape.setFillColor(sf::Color::Black);
    //this->shape.setPosition(10,0);
    
}

Bloque::Bloque(const Bloque& orig) {
}

void Bloque::Dibujar(sf::RenderWindow& window) {
    window.draw(this->shape);
}

void Bloque::Mover(char d) {
    switch(d){
        case 'u':
            this->shape.move(0,-20);
            this->coordenadas = this->shape.getPosition();
            /*
            if(this->shape.getPosition().y<0){
                //std::cout << shape.getPosition().x << std::endl;
                this->shape.move(0,20);
            }            
            */
            break;
        case 'd':
            this->shape.move(0,20);
            this->coordenadas = this->shape.getPosition();
            /*
            if(this->shape.getPosition().y+20>400){
                //std::cout << shape.getPosition().x << std::endl;
                this->shape.move(0,-20);
            }
            */
            
            break;
        case 'l':
            this->shape.move(-20,0);
            this->coordenadas = this->shape.getPosition();
            /*
            if(this->shape.getPosition().x<10){
                //std::cout << shape.getPosition().x << std::endl;
                this->shape.move(20,0);
            }
            */
            break;
        case 'r':
            this->shape.move(20,0);
            this->coordenadas = this->shape.getPosition();
            /*
            if(this->shape.getPosition().x+20>210){
                //std::cout << shape.getPosition().x << std::endl;
                this->shape.move(-20,0);
            }
            */
            break;
        default:
            break;
    }
}

//SETTER
void Bloque::setPosicion(sf::Vector2f pos) {
    this->shape.setPosition(pos.x,pos.y);
}

void Bloque::setColor(sf::Color color) {
    this->shape.setFillColor(color);
}


//GETTER

sf::Vector2f Bloque::getPosicion() {
    return this->coordenadas;
}




Bloque::~Bloque() {
}

