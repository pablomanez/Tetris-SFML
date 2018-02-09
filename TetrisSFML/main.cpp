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
#include <array>
#include <valarray>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Bloque.h"
#include "Pieza.h"
#include "Tablero.h"

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
    
    Tablero tablero;
    
    Pieza * pieza1 = new Pieza(5);
    
    //RELOJ
    sf::Clock reloj;
    
    ////////////////
    //INPUT TECLAS//
    ////////////////
    while(window.isOpen()){
        /*
        if(reloj.getElapsedTime().asSeconds() > 0.8){
            pieza1->Mover('d');
            reloj.restart();
        }
        */
        
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
                        pieza1->Rotar('l');
                        cout << "Roto a la izquierda" << endl;
                    }
                    if(event.key.code == sf::Keyboard::Key::X){
                        pieza1->Rotar('r');
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

