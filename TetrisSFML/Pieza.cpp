/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pieza.cpp
 * Author: pablomanez
 * 
 * Created on 7 de febrero de 2018, 17:39
 */
#include <iostream>

#include "Bloque.h"
#include "Pieza.h"

Pieza::Pieza(int n) {
    this->bloques = new Bloque[4]();
    /*
    //GENERA UN NUMERO ALEATORIO ENTRE 0 Y 10, LAS COORDENADAS DE X
    srand(time(NULL));
    int x = std::rand() % 10;
    x *= 20;
    x += 10;
    */
    this->tipo = n;
    this->fase_rotacion = 1;
    
    if(n==1){
        /*
         * T MORADA
         * 
         * [0][1][2]
         *    [3]
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Magenta);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Magenta);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Magenta);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Magenta);
        
    }
    else if(n==2){
        /*
         * S VERDE
         * 
         *    [1][2]
         * [0][3]
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,20));
        this->bloques[0].setColor(sf::Color::Green);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Green);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Green);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Green);
        
    }
    else if(n==3){
        /*
         * Z ROJA
         * 
         * [0][1]
         *    [3][2]
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Red);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Red);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,20));
        this->bloques[2].setColor(sf::Color::Red);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Red);
    }
    else if(n==4){
        /*
         * PALO AZUL CLARO
         * 
         * [0][1][2][3]
         */
        int x = 70;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Blue.Cyan);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Blue.Cyan);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Blue.Cyan);
        this->bloques[3].setPosicion(sf::Vector2f(x+60,0));
        this->bloques[3].setColor(sf::Color::Blue.Cyan);
    }
    else if(n==5){
        /*
         * J AZUL
         * 
         * [0][1][2]
         *       [3]
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Blue);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Blue);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(sf::Color::Blue);
        this->bloques[3].setPosicion(sf::Vector2f(x+40,20));
        this->bloques[3].setColor(sf::Color::Blue);
    }
    else if(n==6){
        /*
         * L NARANJA
         * 
         * [0][1][2]
         * [3]
         */
        int x = 70;
        sf::Color naranja(255,165,0);
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(naranja);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(naranja);
        this->bloques[2].setPosicion(sf::Vector2f(x+40,0));
        this->bloques[2].setColor(naranja);
        this->bloques[3].setPosicion(sf::Vector2f(x,20));
        this->bloques[3].setColor(naranja);
    }
    else if(n==7){
        /*
         * CUADRO AMARILLO
         * 
         * [0][1]
         * [2][3]
         */
        int x = 90;
        
        this->bloques[0].setPosicion(sf::Vector2f(x,0));
        this->bloques[0].setColor(sf::Color::Yellow);
        this->bloques[1].setPosicion(sf::Vector2f(x+20,0));
        this->bloques[1].setColor(sf::Color::Yellow);
        this->bloques[2].setPosicion(sf::Vector2f(x,20));
        this->bloques[2].setColor(sf::Color::Yellow);
        this->bloques[3].setPosicion(sf::Vector2f(x+20,20));
        this->bloques[3].setColor(sf::Color::Yellow);
    }
    
}

Pieza::Pieza(const Pieza& orig) {
}

void Pieza::Dibujar(sf::RenderWindow& window) {
    this->bloques[0].Dibujar(window);
    this->bloques[1].Dibujar(window);
    this->bloques[2].Dibujar(window);
    this->bloques[3].Dibujar(window);
}

void Pieza::Mover(char d) {
    Bloque * b_aux = this->bloques;
    bool col = false;
    
    switch(d){
        case 'r':
            for(int i=0 ; i<4; i++){
                this->bloques[i].Mover(d);
                if(bloques[i].getPosicion().x+20>210){
                    //this->bloques = b_aux
                    
                    col = true;
                }
            }
            break;
        case 'l':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
                if(bloques[i].getPosicion().x<10){
                    //this->bloques = b_aux
                    
                    col = true;
                }
                
            }
            break;
        case 'u':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
                if(bloques[i].getPosicion().y<0){
                    //this->bloques = b_aux
                    
                    col = true;
                }
            }
            break;
        case 'd':
            for(int i=0 ; i<4 ; i++){
                this->bloques[i].Mover(d);
                if(bloques[i].getPosicion().y+20>400){
                    //this->bloques = b_aux
                    
                    col = true;
                }
            }
            break;
        default:
            break;
    }
    if(col){
        //std::cout << "Choca" << std::endl;
        switch(d){
            case 'l':
                for(int i=0 ; i<4; i++){
                    this->bloques[i].Mover('r');
                }
                break;
            case 'r':
                for(int i=0 ; i<4 ; i++){
                    this->bloques[i].Mover('l');
                }
                break;
            case 'd':
                for(int i=0 ; i<4 ; i++){
                    this->bloques[i].Mover('u');
                }
                break;
            case 'u':
                for(int i=0 ; i<4 ; i++){
                    this->bloques[i].Mover('d');
                }
                break;
            default:
                break;
        }

    }
}

void Pieza::Rotar(char d) {
    int m = 20;
    
    switch(this->tipo){
        case 1:

            if(this->fase_rotacion == 1){
                if(d=='r'){
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,-m));
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,-m));
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    this->fase_rotacion = 4;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r'){
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,-m));
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,+m));
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    
                    this->fase_rotacion--;
                }

            }
            else if(this->fase_rotacion == 3){
                if(d=='r'){
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,+m));
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,+m));
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    
                    this->fase_rotacion--;
                }

            }
            else if(this->fase_rotacion == 4){
                if(d=='r'){
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,+m));
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));

                    this->fase_rotacion = 1;
                }
                else{
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,-m));
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    
                    this->fase_rotacion--;
                }

            }
            break;
            
        case 2:
            if(this->fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,-m));
                    this->bloques[0].Mover(sf::Vector2f((+m)*2,0));
                    
                    this->fase_rotacion++;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,+m));
                    this->bloques[0].Mover(sf::Vector2f((-m)*2,0));
                    
                    this->fase_rotacion = 1;
                }

            }

            break;
        case 3:
            if(this->fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    this->bloques[2].Mover(sf::Vector2f(0,(-m)*2));
                    this->bloques[3].Mover(sf::Vector2f(+m,-m));
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    this->fase_rotacion++;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    this->bloques[2].Mover(sf::Vector2f(0,(+m)*2));
                    this->bloques[3].Mover(sf::Vector2f(-m,+m));
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    
                    this->fase_rotacion = 1;
                }

            }

            break;
        case 4:
            if(this->fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    this->bloques[0].Mover(sf::Vector2f((+m)*2,-m));
                    this->bloques[1].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(-m,(+m)*2));
                    
                    this->fase_rotacion++;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    this->bloques[0].Mover(sf::Vector2f((-m)*2,+m));
                    this->bloques[1].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(+m,(-m)*2));
                    
                    this->fase_rotacion = 1;
                }

            }

            break;
        case 5:

            if(this->fase_rotacion == 1){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(0,(-m)*2));

                    this->fase_rotacion = 4;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    this->fase_rotacion--;
                }

            }
            else if(this->fase_rotacion == 3){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    this->fase_rotacion--;
                }
                //std::cout << "Ha rotado desde la fase 3" << std::endl;

            }
            else if(this->fase_rotacion == 4){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f(0,(+m)*2));

                    this->fase_rotacion = 1;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    this->fase_rotacion--;
                }

            }
            break;
        case 6:

            if(this->fase_rotacion == 1){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f((+m)*2,0));

                    this->fase_rotacion = 4;
                }

            }
            else if(this->fase_rotacion == 2){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(+m,+m));
                    this->bloques[2].Mover(sf::Vector2f(-m,-m));
                    this->bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    this->fase_rotacion--;
                }

            }
            else if(this->fase_rotacion == 3){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(-m,+m));
                    this->bloques[2].Mover(sf::Vector2f(+m,-m));
                    this->bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    this->fase_rotacion++;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    this->fase_rotacion--;
                }

            }
            else if(this->fase_rotacion == 4){
                if(d=='r'){
                    this->bloques[0].Mover(sf::Vector2f(-m,-m));
                    this->bloques[2].Mover(sf::Vector2f(+m,+m));
                    this->bloques[3].Mover(sf::Vector2f((-m)*2,0));

                    this->fase_rotacion = 1;
                }
                else{
                    this->bloques[0].Mover(sf::Vector2f(+m,-m));
                    this->bloques[2].Mover(sf::Vector2f(-m,+m));
                    this->bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    this->fase_rotacion--;
                }

            }
            break;
        default:
            break;
    }
    
}

void Pieza::Rotacion(char d) {
    
    this->Rotar(d);
    //CONTROLA LA SUPERPOSICION
    bool sup = false;
    
    for(int i=0 ; i<4 ; i++){
        //std::cout << i << ": x=" << bloques[i].getPosicion().x << ", y=" << bloques[i].getPosicion().y << std::endl;
        
        if(this->bloques[i].getPosicion().x+20>210){
            //std::cout << "Choca por la derecha" << std::endl;
            sup = true;
        }
        else if(this->bloques[i].getPosicion().x<10){
            sup = true;
        }
        else if(this->bloques[i].getPosicion().y+20>400){
            sup = true;
        }
        else if(this->bloques[i].getPosicion().y<0){
            sup = true;
        }
    }
    
    if(sup){
        if(d == 'r'){
            this->Rotar('l');
        }
        else{
            this->Rotar('r');
        }
    }
    
    
}


Pieza::~Pieza() {
}

