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
#include <iostream>

#include "Pieza.h"
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
    
    this->bloques = new Bloque**[10]();
    
    for(int i=0 ; i<10 ; i++){
        this->bloques[i] = new Bloque*[20]();
    }
    
    for(int i=0; i<10 ; i++){
        for(int j=0; j<20 ; j++){
            
            (this->bloques[i])[j] = NULL;
            
        }
    }
    
}

void Tablero::Dibujar(sf::RenderWindow& window) {
    window.draw(this->shape);
    
    for(int i=0; i<10 ; i++){
        for(int j=0; j<20 ; j++){
            
            if((this->bloques[i])[j] != NULL){
                (this->bloques[i])[j]->Dibujar(window);
            }
            
        }
    }
}

bool Tablero::Colision(Pieza& pieza) {
    Bloque * bloques = pieza.getBloques();
    
    for(int i=0 ; i<4 ; i++){
        if(bloques[i].getPosicion().y+20==400){
            //SIGNIFICA QUE ESTÁ TOCANDO EL BORDE JUSTO
            
            return true;
        }
        
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<20 ; k++){
                if((this->bloques[j])[k] != NULL 
                        && bloques[i].getPosicion().y+20 == (this->bloques[j])[k]->getPosicion().y
                        && bloques[i].getPosicion().x == (this->bloques[j])[k]->getPosicion().x){
                    
                    //SI COLISIONA CON LA PIEZA DE ABAJO
                    
                    return true;
                }
            }
        }
    }
    
    return false;

}

bool Tablero::Colision2(Pieza& pieza) {
    Bloque * bloques = pieza.getBloques();
    
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<20 ; k++){

                if((this->bloques[j])[k] != NULL 
                        && bloques[i].getPosicion().y == (this->bloques[j])[k]->getPosicion().y
                        && bloques[i].getPosicion().x == (this->bloques[j])[k]->getPosicion().x){

                    //SI COLISIONA CON LA PIEZA EN LA MISMA POSICION

                    //std::cout << "AAAA" << std::endl;

                    return true;
                }
            }
        }
    }
}


void Tablero::CopiarPiezas(Pieza& pieza) {
    Bloque * bloques = pieza.getBloques();
    
    sf::Vector2f c_0;
    int x;
    int y;

    for(int i=0 ; i<4 ; i++){
        c_0 = bloques[i].getPosicion();
        x = (c_0.x-10)/20;
        y = c_0.y/20;
        (this->bloques[x])[y] = new Bloque();
        (this->bloques[x])[y]->setColor(bloques[i].getColor());
        (this->bloques[x])[y]->setPosicion(bloques[i].getPosicion());

    }
}



Tablero::Tablero(const Tablero& orig) {
}

Tablero::~Tablero() {
}

