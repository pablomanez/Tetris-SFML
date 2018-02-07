/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: pablomanez
 *
 * Created on 7 de febrero de 2018, 17:24
 */

#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>


class Juego {
public:
    Juego();
    Juego(const Juego& orig);
    
    sf::RenderWindow getWindow();
    
    virtual ~Juego();
private:
    sf::RenderWindow window;
};

#endif /* JUEGO_H */

