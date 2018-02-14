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
#include <queue>
#include <set>

#include "Bloque.h"
#include "Pieza.h"
#include "Tablero.h"
#include "GenerarPiezas.h"
#include "TextoLineas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(640,480), "Tetris", sf::Style::Default);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(30);
    
    auto wsize = window.getSize();
    
    sf::View view1(sf::Vector2f(320,240), sf::Vector2f(wsize.x,wsize.y));
    //sf::View view1(sf::FloatRect(100,100,100,100));
    view1.setViewport(sf::FloatRect(0,0,1,1));
    
    sf::View view2(sf::Vector2f(320,240), sf::Vector2f(wsize.x,wsize.y));
    view2.setViewport(sf::FloatRect(0.5f,0,0.5f,1));
    
    window.setView(view1);
    //window.setView(view2);
            
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
    
    //EL TEXTO QUE MARCA LAS LINEAS
    TextoLineas lineas;
    
    //EN CASO QUE IMPLEMENTE GUARDAR LA PIEZA ACTUAL
    //Pieza * pieza_auxiliar = NULL;
        
    //PARA GENERAR LAS PIEZAS
    Pieza * pieza1 = NULL;
    Pieza ** piezas_sig = new Pieza*[4]();
    GenerarPiezas gen;
    std::queue<int> cola;
    for(int i=0 ; i<5 ; i++){
        if(i==0){
            pieza1 = new Pieza(gen.Generar());
        }
        else{
            int aux_g = gen.Generar();
            
            //CREA Y COLOCA LAS PRIMERAS 4 PIEZAS QUE REPRESENTAN LAS SIGUIENTES
            piezas_sig[i-1] = new Pieza(aux_g);
            piezas_sig[i-1]->ColocarPiezasSiguientes((i-1)*60);
            
            cola.push(aux_g);
        }
    }
    
    
    //RELOJES
    sf::Clock reloj;
    sf::Clock c_colision;
    
    //MANDO
    sf::Joystick mando;
    bool m_d = false;
    
    
    ////////////////
    //INPUT TECLAS//
    ////////////////
    while(window.isOpen()){
        if(reloj.getElapsedTime().asSeconds() > 0.3){
            //MOVER LA PIEZA HACIA ABAJO
            
            if(!tablero.Colision(*pieza1)){
                pieza1->Mover('d');
            }
            reloj.restart();
        }
        
        sf::Event event;
        
        if(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::EventType::JoystickButtonPressed:
                    if(mando.isButtonPressed(0,1)){
                        //cout << "A" << endl;
                        /*
                        if(pieza_auxiliar == NULL){
                            pieza_auxiliar = new Pieza(pieza1->getTipo());
                        }
                        else{
                            pieza1
                        }
                        pieza_auxiliar->ColocarFuera();
                        */
                    }
                    if(mando.isButtonPressed(0,2)){
                        //cout << "B" << endl;
                        pieza1->Rotacion('r');
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Rotacion('l');
                        }
                    }
                    if(mando.isButtonPressed(0,3)){
                        //cout << "Y" << endl;
                        pieza1->Rotacion('l');
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Rotacion('r');
                        }
                    }                    
                    else{
                        //cout << event.joystickButton.button << endl;
                    }
                    break;
                case sf::Event::EventType::JoystickMoved:
                    if(event.joystickMove.position == 100 && event.joystickMove.axis == 0){
                        //cout << "derecha" << endl;
                        pieza1->Mover('r');
                        
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Mover('l');
                        }
                    }
                    if(event.joystickMove.position == -100 && event.joystickMove.axis == 0){
                        //cout << "izquierda" << endl;
                        pieza1->Mover('l');
                        
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Mover('r');
                        }
                    }
                    if(event.joystickMove.position == 100 && event.joystickMove.axis == 1){
                        //cout << "abajo" << endl;
                        m_d = true;
                    }
                    if(!(event.joystickMove.position == 100 && event.joystickMove.axis == 1)){
                        //cout << "abajo" << endl;
                        m_d = false;
                    }
                    else{
                        //cout << event.joystickMove.axis << endl;
                    }
                    break;
                case sf::Event::EventType::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Q || event.key.code == sf::Keyboard::Key::Escape){
                        window.close();
                    }
                    if(event.key.code == sf::Keyboard::Key::Right){
                        pieza1->Mover('r');
                        
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Mover('l');
                        }
                        
                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        pieza1->Mover('l');
                        
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Mover('r');
                        }
                        
                    }
                    if(event.key.code == sf::Keyboard::Key::Down){
                        m_d = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Up){
                        //pieza1->Mover('u');
                    }
                    if(event.key.code == sf::Keyboard::Key::Z){
                        pieza1->Rotacion('l');
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Rotacion('r');
                        }
                        //cout << "Roto a la izquierda" << endl;
                    }
                    if(event.key.code == sf::Keyboard::Key::X){
                        pieza1->Rotacion('r');
                        if(tablero.Colision2(*pieza1)){
                            pieza1->Rotacion('l');
                        }
                        //cout << "Roto a la derecha" << endl;
                    }
                    break;
                    
                case sf::Event::EventType::KeyReleased:
                    if(event.key.code == sf::Keyboard::Key::Down){
                        m_d = false;
                    }
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
            c_colision.restart();
        }
        
        if(m_d){
            if(!tablero.Colision(*pieza1)){
                pieza1->Mover('d');
            }
        }

        //STRING QUE MARCA LAS LINEAS HECHAS QUE LLEVA EL JUGADOR
        lineas.Actualizar(tablero);
        
        //EN CASO QUE HAYA COLISIONADO CON UNA PIEZA O EL FONDO
        if(colision){
            
            if(!tablero.Colision(*pieza1)){
                colision = false;
            }
            else if(c_colision.getElapsedTime().asSeconds() >0.5){
                
                colision = false;
                
                tablero.CopiarPiezas(*pieza1);
                
                pieza1 = NULL;
                pieza1 = new Pieza(cola.front());
                
                if(tablero.Colision2(*pieza1)){
                    //FIN DEL JUEGO
                    cout << "Dedicate al parchis" << endl;
                    window.close();
                }
                
                int pieza_cola = gen.Generar();
                cola.pop();
                cola.push(pieza_cola);
                     
                //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
                for(int i=0 ; i<4 ; i++){
                    if(i!=3){
                        piezas_sig[i] = NULL;
                        piezas_sig[i] = new Pieza(piezas_sig[i+1]->getTipo());
                        piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                    }
                    else{
                        piezas_sig[i] = NULL;
                        piezas_sig[i] = new Pieza(pieza_cola);
                        piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                    }
                }
                
                reloj.restart();
            }
        }
        
        //////////////////
        //RENDER OBJETOS//
        //////////////////
        window.clear(sf::Color::Black);
        tablero.Dibujar(window);
        
        lineas.Dibujar(window);
        pieza1->Dibujar(window);
        
        for(int i=0 ; i<4 ; i++){
            
            piezas_sig[i]->Dibujar(window);
        }
        
        /*
        //EN EL CASO QUE SE HAYA GUARDADO ALGUNA PIEZA
        if(pieza_auxiliar != NULL){
            pieza_auxiliar->Dibujar(window);
            
        }
        */
        
        window.display();        
    }
        return 0;
}

