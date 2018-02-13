/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: pablomanez
 *
 * Created on 9 de febrero de 2018, 0:14
 */

#ifndef TABLERO_H
#define TABLERO_H

#include <SFML/Graphics.hpp>

#include "Pieza.h"
#include "Bloque.h"

class Tablero {
public:
    Tablero();
    Tablero(const Tablero& orig);
    
    void Dibujar(sf::RenderWindow& window);
    bool Colision(Pieza& pieza);
    bool Colision2(Pieza& pieza);
    void CopiarPiezas(Pieza& pieza);
    int Linea();
    
    virtual ~Tablero();
private:
    Bloque *** bloques; 
    sf::ConvexShape shape;
};

#endif /* TABLERO_H */

