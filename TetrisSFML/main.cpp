/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pablomanez
 *
 * Created on 7 de febrero de 2018, 16:26
 */

#include <cstdlib>
#include <iostream>
#include <random>
#include <array>
#include <valarray>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <queue>

#include "Bloque.h"
#include "Pieza.h"
#include "Tablero.h"
#include "GenerarPiezas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(640,480), "Tetris", sf::Style::Default);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(30);
    
            
    ////////////////////
    //CREO LOS BLOQUES//
    ////////////////////
    //Existe un tablero de 10x20 bloques 
    //Cada pieza está hecha por n bloques
    //Bloque = [], dimensiones = 1x1, coordenadas propias
    //Cada bloque se escalara por 20
    /* [0,0]         [10,0]
     * |                  |
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * [][][][][][][][][][]
     * |                  |
     * [0,20]       [10,20]
     * 
     */
    
    //CONTIENE EL MAPA Y LOS 10x20 BLOQUES INICIALIZADOS A NULL
    Tablero tablero;
    bool colision = false;
    
    //PARA GENERAR LAS PIEZAS
    Pieza * pieza1 = NULL;
    GenerarPiezas gen;
    std::queue<int> cola;
    for(int i=0 ; i<5 ; i++){
        if(i==0){
            pieza1 = new Pieza(gen.Generar());
        }
        else{
            cola.push(gen.Generar());
        }
    }
    
    
    //RELOJ
    sf::Clock reloj;
    
    ////////////////
    //INPUT TECLAS//
    ////////////////
    while(window.isOpen()){
        if(colision){
            colision = false;
            
            pieza1 = NULL;
            pieza1 = new Pieza(cola.front());
            cola.pop();
            cola.push(gen.Generar());
        }
        
        if(reloj.getElapsedTime().asSeconds() > 1){
            //cout << gen.Generar() << endl;
            
            //pieza1->Mover('d');
            reloj.restart();
        }
        
        sf::Event event;
        
        if(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::EventType::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Q || event.key.code == sf::Keyboard::Key::Escape ){
                        window.close();
                    }
                    if(event.key.code == sf::Keyboard::Key::Right){
                        pieza1->Mover('r');
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        pieza1->Mover('l');
                    }
                    if(event.key.code == sf::Keyboard::Key::Down){
                        pieza1->Mover('d');
                    }
                    if(event.key.code == sf::Keyboard::Key::Up){
                        pieza1->Mover('u');
                    }
                    if(event.key.code == sf::Keyboard::Key::Z){
                        pieza1->Rotacion('l');
                        cout << "Roto a la izquierda" << endl;
                    }
                    if(event.key.code == sf::Keyboard::Key::X){
                        pieza1->Rotacion('r');
                        cout << "Roto a la derecha" << endl;
                    }
                    break;
                    
                case sf::Event::EventType::KeyReleased:
                    break;
                default:
                    break;
                
            }
        }
    
        //////////////////////
        //ACTUALIZAR OBJETOS//
        //////////////////////
        if(!colision){
            colision = tablero.Colision(*pieza1);
        }

        //////////////////
        //RENDER OBJETOS//
        //////////////////
        window.clear(sf::Color::Black);
        tablero.Dibujar(window);
        
        //bloque->Dibujar(window);
        pieza1->Dibujar(window);
        
        window.display();        
    }
        return 0;
}

