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
    float scale = 1.5;
    //RYU IDLE
    ryu_i.frames=4;
    ryu_i.animDuration = 0.5;
    ryu_i.size = sf::Vector2i(49,82);
    
    AssetManager *instance = AssetManager::instance();
    ryu_i.sprite.setTexture(*instance->getTexture("../assets/sprites/ryu_idle.png"));
    ryu_i.sprite.setTextureRect(sf::IntRect(0,0,ryu_i.size.x,ryu_i.size.y));
    ryu_i.sprite.setPosition(400,200);
    ryu_i.sprite.setOrigin(0,0);
    ryu_i.sprite.setScale(scale,scale);
    ryu_i.name = "idle";
    
    //RYU PUNCH
    ryu_p.frames=3;
    ryu_p.animDuration = 0.3;
    ryu_p.size = sf::Vector2i(65,82);
    
    ryu_p.sprite.setTexture(*instance->getTexture("../assets/sprites/ryu_punch.png"));
    ryu_p.sprite.setTextureRect(sf::IntRect(0,0,ryu_p.size.x,ryu_p.size.y));
    ryu_p.sprite.setPosition(400,200);
    ryu_p.sprite.setOrigin(0,0);
    ryu_p.sprite.setScale(scale,scale);
    ryu_p.name = "punch";
    
    //KEN IDLE
    ken_i.frames=4;
    ken_i.animDuration = 0.5;
    ken_i.size = sf::Vector2i(49,82);
    
    ken_i.sprite.setTexture(*instance->getTexture("../assets/sprites/ken_idle.png"));
    ken_i.sprite.setTextureRect(sf::IntRect(0,0,ken_i.size.x,ken_i.size.y));
    ken_i.sprite.setPosition(470,200);
    ken_i.sprite.setOrigin(0,0);
    ken_i.sprite.setScale(scale,scale);
    ken_i.name = "idle";
    
    
    
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
    cambia_r = false;
    cambia_k = false;
    
    ryu = ryu_i;
    ken = ken_i;
    
}

void St::Dibuja(sf::RenderWindow& window) {
    window.draw(V_a);
    window.draw(F_a);
    
    window.draw(V_e);
    window.draw(F_e);
    
    window.draw(ryu.sprite);
    window.draw(ken.sprite);
}

void St::updateK(sf::Time et) {
    //KEN
    int animFrame = static_cast<int>(( (float)et.asSeconds() / ken.animDuration ) * ken.frames ) %  ken.frames;
    ken.sprite.setTextureRect(sf::IntRect( animFrame*ken.size.x, 0, ken.size.x, ken.size.y ));
}

void St::updateR(sf::Time et) {
    if(cambia_r){
        ryu = ryu_i;
        cambia_r = false;
    }
    
    int animFrame = static_cast<int>(( (float)et.asSeconds() / ryu.animDuration ) * ryu.frames ) %  ryu.frames;
    ryu.sprite.setTextureRect(sf::IntRect( animFrame*ryu.size.x, 0, ryu.size.x, ryu.size.y ));
    
    if(animFrame == 2 && ryu.name == "punch"){
            //std::cout << animFrame<< std::endl;
        cambia_r = true;
            //std::cout << et.asSeconds() << std::endl;
    }
}


void St::BajaVidaEnemigo() {
    int x = V_e.getSize().x;
    
    ryu = ryu_p;
    
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

