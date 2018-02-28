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

class St {
public:
    St();
    St(const St& orig);
    
    void BajaVidaEnemigo();
    void Dibuja(sf::RenderWindow &window);
    
    virtual ~St();
private:
    //ALIADO
    sf::RectangleShape F_a;
    sf::RectangleShape V_a;
    
    //ENEMIGO
    sf::RectangleShape F_e;
    sf::RectangleShape V_e;
};

#endif /* ST_H */

