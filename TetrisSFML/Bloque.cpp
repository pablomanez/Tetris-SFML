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
    
    shape.setSize(sf::Vector2f(1,1));
    shape.scale(sf::Vector2f(20,20));
    shape.setFillColor(sf::Color::Black);
    //shape.setPosition(10,0);
    
    puntuacion = 0;
    
}

Bloque::Bloque(const Bloque& orig) {
}

void Bloque::Dibujar(sf::RenderWindow& window) {
    window.draw(shape);
}

void Bloque::Mover(char d) {
    switch(d){
        case 'u':
            shape.move(0,-20);
            coordenadas = shape.getPosition();
            /*
            if(shape.getPosition().y<0){
                //std::cout << shape.getPosition().x << std::endl;
                shape.move(0,20);
            }            
            */
            break;
        case 'd':
            shape.move(0,20);
            coordenadas = shape.getPosition();
            /*
            if(shape.getPosition().y+20>400){
                //std::cout << shape.getPosition().x << std::endl;
                shape.move(0,-20);
            }
            */
            
            break;
        case 'l':
            shape.move(-20,0);
            coordenadas = shape.getPosition();
            /*
            if(shape.getPosition().x<10){
                //std::cout << shape.getPosition().x << std::endl;
                shape.move(20,0);
            }
            */
            break;
        case 'r':
            shape.move(20,0);
            coordenadas = shape.getPosition();
            /*
            if(shape.getPosition().x+20>210){
                //std::cout << shape.getPosition().x << std::endl;
                shape.move(-20,0);
            }
            */
            break;
        default:
            break;
    }
}

void Bloque::Mover(sf::Vector2f d){
    shape.move(d);
}

bool Bloque::Colisiona(Bloque b1) {
    if(shape.getGlobalBounds().intersects(b1.shape.getGlobalBounds())){
        return true;
    }
    else{
        false;
    }
}


//SETTER
void Bloque::setPosicion(sf::Vector2f pos) {
    shape.setPosition(pos.x,pos.y);
}

void Bloque::setColor(sf::Color color) {
    shape.setFillColor(color);
}

void Bloque::setBorde(sf::Color color) {
    shape.setOutlineThickness(-0.1);
    shape.setOutlineColor(color);
}

void Bloque::setPuntuacion() {
    
    sf::Color morado(128,0,128);
    sf::Color verde(1,135,5);
    sf::Color rojo(214,0,0);
    sf::Color azul_claro(25,170,207);
    sf::Color azul(0,88,166);
    sf::Color naranja(232,140,2);
    sf::Color amarillo(240,232,0);
    
    
    if(shape.getFillColor() == morado){
        puntuacion = 50;
    }
    else if(shape.getFillColor() == verde){
        puntuacion = 30;
    }
    else if(shape.getFillColor() == rojo){
        puntuacion = 30;
    }
    else if(shape.getFillColor() == azul_claro){
        puntuacion = 10;
    }
    else if(shape.getFillColor() == azul){
        puntuacion = 20;
    }
    else if(shape.getFillColor() == naranja){
        puntuacion = 20;
    }
    else if(shape.getFillColor() == amarillo){
        puntuacion = 40;
    }
    
        
}



//GETTER
sf::Vector2f Bloque::getPosicion() {
    return shape.getPosition();
}

sf::Color Bloque::getColor(){
    return shape.getFillColor();
}

int Bloque::getPuntuacion() {
    return puntuacion;
}


Bloque::~Bloque() {
}

