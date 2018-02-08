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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(640,480), "Tetris", sf::Style::Default);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(24);
            
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
    
    sf::ConvexShape tablero(9);
    tablero.setFillColor(sf::Color::Black);
    tablero.setOutlineThickness(1);
    tablero.setOutlineColor(sf::Color::White);
    tablero.setPoint(0,sf::Vector2f(0,0));
    tablero.setPoint(1,sf::Vector2f(0,480));
    tablero.setPoint(2,sf::Vector2f(640,480));
    tablero.setPoint(3,sf::Vector2f(640,0));
    tablero.setPoint(4,sf::Vector2f(211,0));
    tablero.setPoint(5,sf::Vector2f(211,400));
    tablero.setPoint(6,sf::Vector2f(10,400));
    tablero.setPoint(7,sf::Vector2f(10,0));
    tablero.setPoint(8,sf::Vector2f(0,0));
    
    
    Bloque * bloque = new Bloque();
    bloque->setPosicion(sf::Vector2f(10,0));
    //bloque->~Bloque(); //FUNCIONA
    
    Pieza * pieza1 = new Pieza(1);
    
    
    
    ////////////////
    //INPUT TECLAS//
    ////////////////
    while(window.isOpen()){
        
        
        sf::Event event;
        
        if(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::EventType::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Q || event.key.code == sf::Keyboard::Key::Escape ){
                        window.close();
                    }
                    if(event.key.code == sf::Keyboard::Key::Right){
                        bloque->Mover('r');
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        bloque->Mover('l');
                    }
                    if(event.key.code == sf::Keyboard::Key::Down){
                        bloque->Mover('d');
                    }
                    if(event.key.code == sf::Keyboard::Key::Up){
                        bloque->Mover('u');
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
        window.draw(tablero);
        
        bloque->Dibujar(window);
        
        window.display();        
    }
        return 0;
}

