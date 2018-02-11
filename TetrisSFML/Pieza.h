/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pieza.h
 * Author: pablomanez
 *
 * Created on 7 de febrero de 2018, 17:39
 */

#ifndef PIEZA_H
#define PIEZA_H
 
#include "Bloque.h"

class Pieza {
public:
    Pieza(int n);
    Pieza(const Pieza& orig);
    
    void Dibujar(sf::RenderWindow& window);
    void Mover(char d);
    void Rotar(char d);
    void Rotacion(char d);
    
    virtual ~Pieza();
private:
    
    //Bloque ** bloques;
    Bloque * bloques;
    int tipo;
    int fase_rotacion;
};

#endif /* PIEZA_H */

