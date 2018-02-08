/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pieza.cpp
 * Author: pablomanez
 * 
 * Created on 7 de febrero de 2018, 17:39
 */
#include <iostream>

#include "Bloque.h"
#include "Pieza.h"

Pieza::Pieza(int n) {
    this->bloques = new Bloque[4]();
    /*
    //GENERA UN NUMERO ALEATORIO ENTRE 0 Y 10, LAS COORDENADAS DE X
    srand(time(NULL));
    int x = std::rand() % 10;
    x *= 20;
    x += 10;
    */
    
    if(n==1){
        /*
         * T MORADA
         * 
         * [][][]
         *   []
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Magenta);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Magenta);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Magenta);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Magenta);
        
        
        
        
    }
    else if(n==2){
        /*
         * S VERDE
         * 
         *   [][]
         * [][]
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,20));
        this->bloques[0].setColor(sf::Color::Green);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Green);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Green);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Green);
        
    }
    else if(n==3){
        /*
         * Z ROJA
         * 
         * [][]
         *   [][]
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Red);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Red);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,20));
        this->bloques[2].setColor(sf::Color::Red);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Red);
    }
    else if(n==4){
        /*
         * PALO AZUL CLARO
         * 
         * [][][][]
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Blue.Cyan);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Blue.Cyan);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Blue.Cyan);
        this->bloques[3].setPosicion(sf::Vector2f(x+60,0));
        this->bloques[3].setColor(sf::Color::Blue.Cyan);
    }
    else if(n==5){
        /*
         * L AZUL
         * 
         * [][][]
         *     []
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Blue);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Blue);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Blue);
        this->bloques[3].setPosicion(sf::Vector2f(x+40,20));
        this->bloques[3].setColor(sf::Color::Blue);
    }
    else if(n==6){
        /*
         * L NARANJA
         * 
         * [][][]
         * []
         */
        int x = 70;
        sf::Color naranja(255,165,0);
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(naranja);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(naranja);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(naranja);
        this->bloques[3].setPosicion(sf::Vector2f(x,20));
        this->bloques[3].setColor(naranja);
    }
    else if(n==7){
        /*
         * CUADRO AMARILLO
         * 
         * [][]
         * [][]
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Yellow);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Yellow);
        this->bloques[2].setPosicion(sf::Vector2f(x,20));
        this->bloques[2].setColor(sf::Color::Yellow);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Yellow);
    }
    
}

Pieza::Pieza(const Pieza& orig) {
}

void Pieza::Dibujar(sf::RenderWindow& window) {
    this->bloques[0].Dibujar(window);
    this->bloques[1].Dibujar(window);
    this->bloques[2].Dibujar(window);
    this->bloques[3].Dibujar(window);
}

void Pieza::Mover(char d) {
    Bloque * b_aux = this->bloques;
    bool col = false;
    
    switch(d){
        case 'r':
            for(int i=0 ; i<4 && !col ; i++){
                this->bloques[i].Mover(d);
                if(bloques[i].getPosicion().x+20>210){
                    this->bloques = b_aux;
                    
                    col = true;
                }
            }
            break;
        case 'l':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
            }
            break;
        case 'u':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
            }
            break;
        case 'd':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
            }
            break;
        default:
            break;
    }
}



Pieza::~Pieza() {
}

