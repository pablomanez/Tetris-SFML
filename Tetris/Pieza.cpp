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

#include "Pieza.h"

Pieza::Pieza(int n) {
    switch(n){
        case 1:
            /*
             * T MORADA
             * 
             *   []
             * [][][]
             */
            break;
        case 2:
            /*
             * S VERDE
             * 
             *   [][]
             * [][]
             */
            break;
        case 3:
            /*
             * Z ROJA
             * 
             * [][]
             *   [][]
             */
            break;
        case 4:
            /*
             * PALO AZUL CLARO
             * 
             * [][][][]
             */
            break;
        case 5:
            /*
             * L AZUL
             * 
             * []
             * [][][]
             */
            break;
        case 6:
            /*
             * L NARANJA
             * 
             *     []
             * [][][]
             */
            break;
        case 7:
            /*
             * CUADRO AMARILLO
             * 
             * [][]
             * [][]
             */
            break;
        default:
            break;
            
    }
    
}

Pieza::Pieza(const Pieza& orig) {
}

Pieza::~Pieza() {
}

