/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   St.h
 * Author: pablomanez
 *
 * Created on 28 de febrero de 2018, 15:45
 */

#ifndef ST_H
#define ST_H

#include "AssetManager.h"


class St {
public:
    St();
    St(const St& orig);
    
    void BajaVidaEnemigo();
    void BajaVidaAliado();
    void Dibuja(sf::RenderWindow &window);
    void SubeRonda();
    
    void updateR();
    void updateK();
    void DibujaShader(sf::RenderWindow& window, sf::Sprite sprite);
    
    bool getDeadEnemigo();
    bool getDeadAliado();
    
    virtual ~St();
private:
    bool cambia_r;
    bool cambia_k;
    
    struct anim{
        sf::Sprite sprite;
        sf::Vector2i size;
        int frames;
        float animDuration;
        std::string name;
    };
    anim ryu_i;
    anim ryu_p;
    anim ryu;
    sf::Clock r;
    sf::Time r_et;
    
    anim ken_i;
    anim ken_p;
    anim ken;
    sf::Clock k;
    sf::Time k_et;
    
    
    //ALIADO
    sf::RectangleShape F_a;
    sf::RectangleShape V_a;
    
    
    //ENEMIGO
    sf::RectangleShape F_e;
    sf::RectangleShape V_e;
    
    int ronda;
};

#endif /* ST_H */

