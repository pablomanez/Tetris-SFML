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

#include "Bloque.h"
#include "Pieza.h"

Pieza::Pieza(int n) {
    if(n==1){
        /*
         * T MORADA
         * 
         *   []
         * [][][]
         */
        //Bloque ** a_b = new Bloque*[4]();
        Bloque a_b[4];

        //this->bloques = a_b;
        
        //GENERA UN NUMERO ALEATORIO ENTRE 0 Y 10, LAS COORDENADAS DE X
        int x = std::rand() % 10;
        x *= 20;
        
        a_b[0].setPosicion(sf::Vector2f(x,20));
        a_b[1].setPosicion(sf::Vector2f(x,40));
        a_b[2].setPosicion(sf::Vector2f(x,60));
        a_b[3].setPosicion(sf::Vector2f(x-20,40));
        
        //bloques = a_b;
        
        
        
    }
    else if(n==2){
        /*
         * S VERDE
         * 
         *   [][]
         * [][]
         */
    }
    else if(n==3){
        /*
         * Z ROJA
         * 
         * [][]
         *   [][]
         */
    }
    else if(n==4){
        /*
         * PALO AZUL CLARO
         * 
         * [][][][]
         */
    }
    else if(n==5){
        /*
         * L AZUL
         * 
         * []
         * [][][]
         */
    }
    else if(n==6){
        /*
         * L NARANJA
         * 
         *     []
         * [][][]
         */
    }
    else if(n==7){
        /*
         * CUADRO AMARILLO
         * 
         * [][]
         * [][]
         */
    }
    
}

Pieza::Pieza(const Pieza& orig) {
}

Pieza::~Pieza() {
}

