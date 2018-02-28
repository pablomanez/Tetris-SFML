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
    bloques = new Bloque[4]();
    /*
    //GENERA UN NUMERO ALEATORIO ENTRE 0 Y 10, LAS COORDENADAS DE X
    srand(time(NULL));
    int x = std::rand() % 10;
    x *= 20;
    x += 10;
    */
    tipo = n;
    fase_rotacion = 1;
    
    if(n==1){
        /*
         * T MORADA
         * 
         * [0][1][2]
         *    [3]
         */
        int x = 70;
        
        sf::Color morado(128,0,128);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(morado);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(morado);
        bloques[2].setPosicion(sf::Vector2f(x+40,0));
        bloques[2].setColor(morado);
        bloques[3].setPosicion(sf::Vector2f(x+20,20));
        bloques[3].setColor(morado);
        
    }
    else if(n==2){
        /*
         * S VERDE
         * 
         *    [1][2]
         * [0][3]
         */
        int x = 70;
        
        sf::Color verde(1,135,5);
        
        bloques[0].setPosicion(sf::Vector2f(x,20));
        bloques[0].setColor(verde);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(verde);
        bloques[2].setPosicion(sf::Vector2f(x+40,0));
        bloques[2].setColor(verde);
        bloques[3].setPosicion(sf::Vector2f(x+20,20));
        bloques[3].setColor(verde);
        
    }
    else if(n==3){
        /*
         * Z ROJA
         * 
         * [0][1]
         *    [3][2]
         */
        int x = 90;
        
        sf::Color rojo(214,0,0);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(rojo);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(rojo);
        bloques[2].setPosicion(sf::Vector2f(x+40,20));
        bloques[2].setColor(rojo);
        bloques[3].setPosicion(sf::Vector2f(x+20,20));
        bloques[3].setColor(rojo);
    }
    else if(n==4){
        /*
         * PALO AZUL CLARO
         * 
         * [0][1][2][3]
         */
        int x = 70;
        
        sf::Color azul_claro(25,170,207);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(azul_claro);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(azul_claro);
        bloques[2].setPosicion(sf::Vector2f(x+40,0));
        bloques[2].setColor(azul_claro);
        bloques[3].setPosicion(sf::Vector2f(x+60,0));
        bloques[3].setColor(azul_claro);
    }
    else if(n==5){
        /*
         * J AZUL
         * 
         * [0][1][2]
         *       [3]
         */
        int x = 90;
        
        sf::Color azul(0,88,166);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(azul);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(azul);
        bloques[2].setPosicion(sf::Vector2f(x+40,0));
        bloques[2].setColor(azul);
        bloques[3].setPosicion(sf::Vector2f(x+40,20));
        bloques[3].setColor(azul);
    }
    else if(n==6){
        /*
         * L NARANJA
         * 
         * [0][1][2]
         * [3]
         */
        int x = 70;
        
        sf::Color naranja(232,140,2);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(naranja);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(naranja);
        bloques[2].setPosicion(sf::Vector2f(x+40,0));
        bloques[2].setColor(naranja);
        bloques[3].setPosicion(sf::Vector2f(x,20));
        bloques[3].setColor(naranja);
    }
    else if(n==7){
        /*
         * CUADRO AMARILLO
         * 
         * [0][1]
         * [2][3]
         */
        int x = 90;
        
        sf::Color amarillo(240,232,0);
        
        bloques[0].setPosicion(sf::Vector2f(x,0));
        bloques[0].setColor(amarillo);
        bloques[1].setPosicion(sf::Vector2f(x+20,0));
        bloques[1].setColor(amarillo);
        bloques[2].setPosicion(sf::Vector2f(x,20));
        bloques[2].setColor(amarillo);
        bloques[3].setPosicion(sf::Vector2f(x+20,20));
        bloques[3].setColor(amarillo);
    }
    
}

Pieza::Pieza(const Pieza& orig) {
    
}

void Pieza::Dibujar(sf::RenderWindow& window) {    
    bloques[0].Dibujar(window);
    bloques[1].Dibujar(window);
    bloques[2].Dibujar(window);
    bloques[3].Dibujar(window);
}

void Pieza::Mover(char d) {
    Bloque * b_aux = bloques;
    bool col = false;
    
    switch(d){
        case 'r':
            for(int i=0 ; i<4; i++){
                bloques[i].Mover(d);
                if(bloques[i].getPosicion().x+20>210){
                    //bloques = b_aux
                    
                    col = true;
                }
            }
            break;
        case 'l':
            for(int i=0 ; i<4 ; i++){
                bloques[i].Mover(d);
                if(bloques[i].getPosicion().x<10){
                    //bloques = b_aux
                    
                    col = true;
                }
                
            }
            break;
        case 'u':
            for(int i=0 ; i<4 ; i++){
                bloques[i].Mover(d);
                if(bloques[i].getPosicion().y<0){
                    //bloques = b_aux
                    
                    col = true;
                }
            }
            break;
        case 'd':
            for(int i=0 ; i<4 ; i++){
                bloques[i].Mover(d);
                if(bloques[i].getPosicion().y+20>400){
                    //bloques = b_aux
                    
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
                    bloques[i].Mover('r');
                }
                break;
            case 'r':
                for(int i=0 ; i<4 ; i++){
                    bloques[i].Mover('l');
                }
                break;
            case 'd':
                for(int i=0 ; i<4 ; i++){
                    bloques[i].Mover('u');
                }
                break;
            case 'u':
                for(int i=0 ; i<4 ; i++){
                    bloques[i].Mover('d');
                }
                break;
            default:
                break;
        }

    }
}

void Pieza::Rotar(char d) {
    int m = 20;
    
    switch(tipo){
        case 1:

            if(fase_rotacion == 1){
                if(d=='r'){
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,-m));
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,-m));
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    fase_rotacion = 4;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r'){
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,-m));
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,+m));
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    
                    fase_rotacion--;
                }

            }
            else if(fase_rotacion == 3){
                if(d=='r'){
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,+m));
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,+m));
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    
                    fase_rotacion--;
                }

            }
            else if(fase_rotacion == 4){
                if(d=='r'){
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,+m));
                    bloques[0].Mover(sf::Vector2f(-m,-m));

                    fase_rotacion = 1;
                }
                else{
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,-m));
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    
                    fase_rotacion--;
                }

            }
            break;
            
        case 2:
            if(fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,-m));
                    bloques[0].Mover(sf::Vector2f((+m)*2,0));
                    
                    fase_rotacion++;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,+m));
                    bloques[0].Mover(sf::Vector2f((-m)*2,0));
                    
                    fase_rotacion = 1;
                }

            }

            break;
        case 3:
            if(fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    bloques[2].Mover(sf::Vector2f(0,(-m)*2));
                    bloques[3].Mover(sf::Vector2f(+m,-m));
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    
                    fase_rotacion++;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    bloques[2].Mover(sf::Vector2f(0,(+m)*2));
                    bloques[3].Mover(sf::Vector2f(-m,+m));
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    
                    fase_rotacion = 1;
                }

            }

            break;
        case 4:
            if(fase_rotacion == 1){
                if(d=='r' || d=='l'){
                    bloques[0].Mover(sf::Vector2f((+m)*2,-m));
                    bloques[1].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(-m,(+m)*2));
                    
                    fase_rotacion++;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r' || d=='l'){
                    bloques[0].Mover(sf::Vector2f((-m)*2,+m));
                    bloques[1].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(+m,(-m)*2));
                    
                    fase_rotacion = 1;
                }

            }

            break;
        case 5:

            if(fase_rotacion == 1){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(0,(-m)*2));

                    fase_rotacion = 4;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    fase_rotacion--;
                }

            }
            else if(fase_rotacion == 3){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    fase_rotacion--;
                }
                //std::cout << "Ha rotado desde la fase 3" << std::endl;

            }
            else if(fase_rotacion == 4){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f(0,(+m)*2));

                    fase_rotacion = 1;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    fase_rotacion--;
                }

            }
            break;
        case 6:

            if(fase_rotacion == 1){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f((+m)*2,0));

                    fase_rotacion = 4;
                }

            }
            else if(fase_rotacion == 2){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(+m,+m));
                    bloques[2].Mover(sf::Vector2f(-m,-m));
                    bloques[3].Mover(sf::Vector2f((+m)*2,0));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    fase_rotacion--;
                }

            }
            else if(fase_rotacion == 3){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(-m,+m));
                    bloques[2].Mover(sf::Vector2f(+m,-m));
                    bloques[3].Mover(sf::Vector2f(0,(+m)*2));
                    
                    fase_rotacion++;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f((-m)*2,0));
                    
                    fase_rotacion--;
                }

            }
            else if(fase_rotacion == 4){
                if(d=='r'){
                    bloques[0].Mover(sf::Vector2f(-m,-m));
                    bloques[2].Mover(sf::Vector2f(+m,+m));
                    bloques[3].Mover(sf::Vector2f((-m)*2,0));

                    fase_rotacion = 1;
                }
                else{
                    bloques[0].Mover(sf::Vector2f(+m,-m));
                    bloques[2].Mover(sf::Vector2f(-m,+m));
                    bloques[3].Mover(sf::Vector2f(0,(-m)*2));
                    
                    fase_rotacion--;
                }

            }
            break;
        default:
            break;
    }
    
}

void Pieza::Rotacion(char d) {
    
    Rotar(d);
    //CONTROLA LA SUPERPOSICION
    bool sup = false;
    
    for(int i=0 ; i<4 ; i++){
        //std::cout << i << ": x=" << bloques[i].getPosicion().x << ", y=" << bloques[i].getPosicion().y << std::endl;
        
        if(bloques[i].getPosicion().x+20>210){
            //std::cout << "Choca por la derecha" << std::endl;
            sup = true;
        }
        else if(bloques[i].getPosicion().x<10){
            sup = true;
        }
        else if(bloques[i].getPosicion().y+20>400){
            sup = true;
        }
        else if(bloques[i].getPosicion().y<0){
            sup = true;
        }
    }
    
    if(sup){
        if(d == 'r'){
            Rotar('l');
        }
        else{
            Rotar('r');
        }
    }
    
    
}

//COLOCA LA PIEZA GUARDADA FUERA
void Pieza::ColocarFuera() {
    int y = 340;
    bloques[0].Mover(sf::Vector2f(150,y));
    bloques[1].Mover(sf::Vector2f(150,y));
    bloques[2].Mover(sf::Vector2f(150,y));
    bloques[3].Mover(sf::Vector2f(150,y));
}

//COLOCA EN FILA VERTICAL TODAS LAS PIEZAS SIGUIENTES
void Pieza::ColocarPiezasSiguientes(int y) {
    for(int i=0 ; i<4 ; i++){
        bloques[i].Mover(sf::Vector2f(150,y+40));
    }
}

//CAMBIA EL COLOR DE LA PIEZA QUE QUIERAS
void Pieza::CambiaColor(sf::Color color) {
    for(int i=0 ; i<4 ; i++){
        bloques[i].setColor(color);
    }
}



//GETTER

Bloque * Pieza::getBloques() {
    return bloques;
}

int Pieza::getTipo() {
    return tipo;
}

int Pieza::getFase() {
    return fase_rotacion;
}




Pieza::~Pieza() {
}

