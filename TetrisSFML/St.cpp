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
#include <iostream>
#include "AssetManager.h"
#include "St.h"

St::St(){
    //SPRITES
    ryu_i.frames=4;
    ryu_i.animDuration = 1;
    ryu_i.size = sf::Vector2i(46,82);
    
    AssetManager *instance = AssetManager::instance();
    ryu_i.sprite.setTexture(*instance->getTexture("../assets/sprites/ryu_idle.png"));
    ryu_i.sprite.setTextureRect(sf::IntRect(0,0,ryu_i.size.x,ryu_i.size.y));
    ryu_i.sprite.setPosition(400,200);
    //ryu_i.sprite.setScale(sf::Vector2f(1.5,1.5));
    
    
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
    
    ronda = 1;
    
    
}

void St::Dibuja(sf::RenderWindow& window, sf::Time et) {
    window.draw(V_a);
    window.draw(F_a);
    
    window.draw(V_e);
    window.draw(F_e);
    
    
    
    int animFrame = static_cast<int>(( (float)et.asSeconds() / ryu_i.animDuration ) * ryu_i.frames ) %  ryu_i.frames;
    ryu_i.sprite.setTextureRect(sf::IntRect( animFrame*ryu_i.size.x, 0, ryu_i.size.x, ryu_i.size.y ));
    window.draw(ryu_i.sprite);
}

void St::BajaVidaEnemigo() {
    int x = V_e.getSize().x;
    
    if(x>0){
        V_e.setSize(sf::Vector2f(x-(10/ronda),20));
    }
}

void St::BajaVidaAliado() {
    int x = V_a.getSize().x;
    
    if(x>0){
        V_a.setSize(sf::Vector2f(x-10,20));
    }

}

void St::SubeRonda() {
    ronda++;
    
    V_e.setSize(sf::Vector2f(200,20));
    
    //CADA VEZ QUE SE SUBE UNA RONDA
    //EL ALIADO RECUPERA LA MITAD DE LA VIDA QUE HA PERDIDO
    //RESPECTO A LA VIDA MAXIMA
    if(V_a.getSize().x!=200){
            //std::cout << "No tiene toda la vida" << std::endl;
        
        int x = V_a.getSize().x + (200-V_a.getSize().x)/2;
        
        V_a.setSize(sf::Vector2f(x,20));
        
        
    }
    
}

bool St::getDeadAliado() {
    if(V_a.getSize().x <= 0){
        return true;
    }
    else{
        return false;
    }
}

bool St::getDeadEnemigo() {    
    if(V_e.getSize().x <= 0){
        return true;
    }
    else{
        return false;
    }
}

St::St(const St& orig) {
}

St::~St() {
}

