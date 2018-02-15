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
    
    this->puntuacion = 0;
    
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

void Bloque::Mover(sf::Vector2f d){
    this->shape.move(d);
}

bool Bloque::Colisiona(Bloque b1) {
    if(this->shape.getGlobalBounds().intersects(b1.shape.getGlobalBounds())){
        return true;
    }
    else{
        false;
    }
}


//SETTER
void Bloque::setPosicion(sf::Vector2f pos) {
    this->shape.setPosition(pos.x,pos.y);
}

void Bloque::setColor(sf::Color color) {
    this->shape.setFillColor(color);
}

void Bloque::setBorde(sf::Color color) {
    this->shape.setOutlineThickness(-0.1);
    this->shape.setOutlineColor(color);
}

void Bloque::setPuntuacion() {
    
    sf::Color morado(128,0,128);
    sf::Color verde(1,135,5);
    sf::Color rojo(214,0,0);
    sf::Color azul_claro(25,170,207);
    sf::Color azul(0,88,166);
    sf::Color naranja(232,140,2);
    sf::Color amarillo(240,232,0);
    
    this->puntuacion = 10;
    
    /*
    if(this->shape.getFillColor() == morado){
        this->puntuacion = 50;
    }
    else if(this->shape.getFillColor() == verde){
        this->puntuacion = 30;
    }
    else if(this->shape.getFillColor() == rojo){
        this->puntuacion = 30;
    }
    else if(this->shape.getFillColor() == azul_claro){
        this->puntuacion = 10;
    }
    else if(this->shape.getFillColor() == azul){
        this->puntuacion = 20;
    }
    else if(this->shape.getFillColor() == naranja){
        this->puntuacion = 20;
    }
    else if(this->shape.getFillColor() == amarillo){
        this->puntuacion = 40;
    }
    */
        
}



//GETTER
sf::Vector2f Bloque::getPosicion() {
    return this->shape.getPosition();
}

sf::Color Bloque::getColor(){
    return this->shape.getFillColor();
}

int Bloque::getPuntuacion() {
    return this->puntuacion;
}


Bloque::~Bloque() {
}

