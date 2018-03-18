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
#include <SFML/Audio/Music.hpp>
#include "AssetManager.h"
#include "St.h"

St::St(){
    float scale = 2.5;
    AssetManager *instance = AssetManager::instance();
    int y;
    int x;
    
    //RYU IDLE
    y = 150;
    x = 360;
    
    ryu_i.frames=4;
    ryu_i.animDuration = 0.5;
    ryu_i.size = sf::Vector2i(49,82);
    
    ryu_i.sprite.setTexture(*instance->getTexture("../assets/sprites/ryu_idle.png"));
    ryu_i.sprite.setTextureRect(sf::IntRect(0,0,ryu_i.size.x,ryu_i.size.y));
    ryu_i.sprite.setPosition(x,y);
    ryu_i.sprite.setOrigin(0,0);
    ryu_i.sprite.setScale(scale,scale);
    ryu_i.name = "idle";
    
    //RYU PUNCH
    ryu_p.frames=3;
    ryu_p.animDuration = 0.3;
    ryu_p.size = sf::Vector2i(65,82);
    
    ryu_p.sprite.setTexture(*instance->getTexture("../assets/sprites/ryu_punch.png"));
    ryu_p.sprite.setTextureRect(sf::IntRect(0,0,ryu_p.size.x,ryu_p.size.y));
    ryu_p.sprite.setPosition(x,y);
    ryu_p.sprite.setOrigin(0,0);
    ryu_p.sprite.setScale(scale,scale);
    ryu_p.name = "punch";
    
    //KEN IDLE
    x = 600;
    
    ken_i.frames=4;
    ken_i.animDuration = 0.5;
    ken_i.size = sf::Vector2i(49,82);
    
    ken_i.sprite.setTexture(*instance->getTexture("../assets/sprites/ken_idle.png"));
    ken_i.sprite.setTextureRect(sf::IntRect(0,0,ken_i.size.x,ken_i.size.y));
    ken_i.sprite.setPosition(x,y);
    ken_i.sprite.setOrigin(0,0);
    ken_i.sprite.setScale(-scale,scale);
    ken_i.name = "idle";
    
    //KEN IDLE
    ken_p.frames=3;
    ken_p.animDuration = 0.3;
    ken_p.size = sf::Vector2i(65,82);
    
    ken_p.sprite.setTexture(*instance->getTexture("../assets/sprites/ken_punch.png"));
    ken_p.sprite.setTextureRect(sf::IntRect(0,0,ken_p.size.x,ken_p.size.y));
    ken_p.sprite.setPosition(x,y);
    ken_p.sprite.setOrigin(0,0);
    ken_p.sprite.setScale(-scale,scale);
    ken_p.name = "punch";
    
    
    
    //ALIADO 
    V_a.setSize(sf::Vector2f(200,20));
    V_a.setFillColor(sf::Color::Green);
    V_a.setTexture(instance->getTexture("../assets/sprites/barravida_100_r.png"));
    V_a.rotate(180);
    V_a.setPosition(540,460);
    
    F_a.setSize(sf::Vector2f(80,80));
    F_a.setFillColor(sf::Color::White);
    F_a.setPosition(540,380);
    
    //ENEMIGO
    V_e.setSize(sf::Vector2f(200,20));
    V_e.setFillColor(sf::Color::Red);
    V_e.setTexture(instance->getTexture("../assets/sprites/barravida_100.png"));
    V_e.setPosition(420,80);
    
    F_e.setSize(sf::Vector2f(80,80));
    F_e.setFillColor(sf::Color::White);
    F_e.setPosition(340,20);
    
    ronda = 1;
    cambia_r = false;
    cambia_k = false;
    
    ryu = ryu_i;
    ken = ken_i;
    
    punch.setBuffer(*instance->getSoundBuffer("../assets/sonidos/punch.wav"));
    punch.setVolume(100);
    
}

void St::Dibuja(sf::RenderWindow& window) {
    window.draw(V_a);
    //window.draw(F_a);
    
    window.draw(V_e);
    //window.draw(F_e);
    
    
    window.draw(ryu.sprite);
    window.draw(ken.sprite);
    
    if(cambia_r) DibujaShader(window,ryu.sprite);
}

void St::updateK() {
    //KEN
    
    k_et += k.restart();
    
    if(cambia_k){
        ken = ken_i;
        cambia_k = false;
    }
    
    int animFrame = static_cast<int>(( (float)k_et.asSeconds() / ken.animDuration ) * ken.frames ) %  ken.frames;
    ken.sprite.setTextureRect(sf::IntRect( animFrame*ken.size.x, 0, ken.size.x, ken.size.y ));
    
    if(animFrame == 2 && ken.name == "punch"){
            //std::cout << animFrame<< std::endl;
        cambia_k = true;
            //std::cout << et.asSeconds() << std::endl;
    }
}

void St::updateR() {
    //RYU
    
    r_et += r.restart();
    
    if(cambia_r){
        ryu = ryu_i;
        cambia_r = false;
    }
    
    int animFrame = static_cast<int>(( (float)r_et.asSeconds() / ryu.animDuration ) * ryu.frames ) %  ryu.frames;
    ryu.sprite.setTextureRect(sf::IntRect( animFrame*ryu.size.x, 0, ryu.size.x, ryu.size.y ));
    
    if(animFrame == 2 && ryu.name == "punch"){
            //std::cout << animFrame<< std::endl;
        cambia_r = true;
            //std::cout << et.asSeconds() << std::endl;
    }
}


void St::BajaVidaEnemigo() {
    punch.play();
    
    int x = V_e.getSize().x;
    
    r_et = sf::Time::Zero;
    ryu = ryu_p;
    
    if(x>0){
        V_e.setSize(sf::Vector2f(x-(20/ronda),20));
        V_e.setTextureRect(sf::IntRect(0,0,(int)V_e.getSize().x,20));
    }
}

void St::BajaVidaAliado() {
    punch.play();
    
    int x = V_a.getSize().x;
    
    k_et = sf::Time::Zero;
    ken = ken_p;
    
    if(x>0){
        V_a.setSize(sf::Vector2f(x-10,20));
        V_a.setTextureRect(sf::IntRect(0,0,(int)V_a.getSize().x,20));
    }

}

void St::SubeRonda() {
    ronda++;
    AssetManager *instance = AssetManager::instance();
    
    V_e.setSize(sf::Vector2f(200,20));
    V_e.setTextureRect(sf::IntRect(0,0,(int)V_e.getSize().x,20));
    
    //CADA VEZ QUE SE SUBE UNA RONDA
    //EL ALIADO RECUPERA LA MITAD DE LA VIDA QUE HA PERDIDO
    //RESPECTO A LA VIDA MAXIMA
    if(V_a.getSize().x!=200){
            //std::cout << "No tiene toda la vida" << std::endl;
        
        int x = V_a.getSize().x + (200-V_a.getSize().x)/2;
        
        V_a.setSize(sf::Vector2f(x,20));
        
        V_a.setTexture(instance->getTexture("../assets/sprites/barravida_100_r.png"));
        V_a.setTextureRect(sf::IntRect(0,0,(int)V_a.getSize().x,20));
        
        
        
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

void St::DibujaShader(sf::RenderWindow& window, sf::Sprite sprite) {
    sf::Shader shader;
    AssetManager *instance = AssetManager::instance();
    
    shader.setUniform("overlay", instance->getTexture("../assets/sprites/bloqueFV.png"));
    
    
    window.draw(sprite, &shader);
    
}

St::St(const St& orig) {
}

St::~St() {
}

