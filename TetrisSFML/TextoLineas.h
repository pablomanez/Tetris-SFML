/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoLineas.h
 * Author: pablomanez
 *
 * Created on 13 de febrero de 2018, 12:27
 */

#ifndef TEXTOLINEAS_H
#define TEXTOLINEAS_H

#include "Tablero.h"


class TextoLineas {
public:
    TextoLineas();
    TextoLineas(const TextoLineas& orig);
    
    void Actualizar(Tablero& tablero);
    void Dibujar(sf::RenderWindow& window, int puntos);
    
    //GETTER 
    int getLineas();
    
    virtual ~TextoLineas();
private:
    int n_lineas;
    //sf::Text texto;
};

#endif /* TEXTOLINEAS_H */

