/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: pablomanez
 * 
 * Created on 7 de febrero de 2018, 17:24
 */
#include <SFML/Graphics.hpp>

#include "Juego.h"

Juego::Juego() {
    sf::RenderWindow window2(sf::VideoMode(640,480), "Tetris", sf::Style::Default);
    window2.setMouseCursorVisible(false);
    window2.setFramerateLimit(24);
}

Juego::Juego(const Juego& orig) {
}



Juego::~Juego() {
}

