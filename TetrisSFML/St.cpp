/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   St.cpp
 * Author: pablomanez
 * 
 * Created on 28 de febrero de 2018, 15:45
 */

#include <SFML/Graphics.hpp>
#include "St.h"

St::St() {
    //ALIADO
    V_a.setSize(sf::Vector2f(200,20));
    V_a.setFillColor(sf::Color::Green);
    V_a.rotate(180);
    V_a.setPosition(540,460);
    
    F_a.setSize(sf::Vector2f(80,80));
    F_a.setFillColor(sf::Color::White);
    F_a.setPosition(540,380);
    
    //ENEMIGO
    V_e.setSize(sf::Vector2f(200,20));
    V_e.setFillColor(sf::Color::Red);
    V_e.setPosition(420,80);
    
    F_e.setSize(sf::Vector2f(80,80));
    F_e.setFillColor(sf::Color::White);
    F_e.setPosition(340,20);
}

void St::Dibuja(sf::RenderWindow& window) {
    window.draw(V_a);
    window.draw(F_a);
    
    window.draw(V_e);
    window.draw(F_e);
}

void St::BajaVidaEnemigo() {
    int x = V_e.getSize().x;
    
    if(x>0){
        V_e.setSize(sf::Vector2f(x-10,20));
    }
}

St::St(const St& orig) {
}

St::~St() {
}

