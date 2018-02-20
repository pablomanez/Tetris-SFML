/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: pablomanez
 * 
 * Created on 18 de febrero de 2018, 21:27
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

#include "Juego.h"

Juego::Juego():
    window(sf::VideoMode(640,480), "Tetris", sf::Style::Default)
{
    this->window.setMouseCursorVisible(false);
    this->window.setFramerateLimit(30);
    
    this->int J = 2;
    
    //ARRAYS
    for(int i=0 ; i<this->J ; i++){
        this->pieza_auxiliar[i] = NULL;
        this->guardar_pieza[i] = false;
        
        this->pieza1[i] = NULL;
        this->n_p[i] = 100;
        this->piezas_sig[i] = new Pieza*[this->n_p[i]];
        this->GeneraPiezas(i);
        
        this->m_d[i] = false;
    }
    
    /*
    //J1
    this->pieza_auxiliar = NULL;
    this->guardar_pieza = false;
    
    this->pieza1 = NULL;
    this->n_p = 100;
    this->piezas_sig = new Pieza*[n_p]();
    this->GeneraPiezas();
    
    this->m_d = false;
    */
}

//UN PERRO
void Juego::Bucle() {
    //VISTA DEL JUGADOR 1
    sf::View view1(sf::FloatRect(0,0,640,480));
    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    
    //VISTA DEL JUGADOR 2
    sf::View view2(sf::FloatRect(-320,0,640,480));
    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    
    while(this->window.isOpen()){
        for(int i=0 ; i<this->J ; i++){
            this->MovAbajo(i);
            
            sf::Event event;
            this->Eventos(event);
            
        }
        /*
        
        
        this->Update();
        
        //RENDER
        this->window.clear(sf::Color::Black);
            this->window.setView(view1);
            this->Render();

            this->window.setView(view2);
            this->Render_J2();
        this->window.display();
        */
    }
}

//EL RENDER
void Juego::Render() {
    //this->window.clear(sf::Color::Black);
    this->tablero.Dibujar(this->window);

    this->lineas.Dibujar(this->window,this->tablero.getPuntuacionTotal());
    this->pieza1->Dibujar(this->window);

    for(int i=0 ; i<4 ; i++){
        this->piezas_sig[i]->Dibujar(this->window);

    }

    if(this->pieza_auxiliar){
        this->pieza_auxiliar->Dibujar(this->window);

    }
    
    //this->window.display();
}

//EL UPDEIT
void Juego::Update() {
    //ACTUALIZO OBJETOS
    if(!this->colision){
        this->colision = this->tablero.Colision(*(this->pieza1));
        this->c_colision.restart();
    }

    if(this->m_d){
        if(!this->tablero.Colision(*(this->pieza1))){
            this->pieza1->Mover('d');
        }
    }
    
    //STRING QUE MARCA LAS LINEAS HECHAS QUE LLEVA EL JUGADOR
    this->lineas.Actualizar(this->tablero);

    this->GuardaPieza();
    
    this->ColisionPieza();
    
}

//EN CASO QUE HAYA COLISIONADO CON UNA PIEZA O EL FONDO
void Juego::ColisionPieza() {
    if(this->colision){

        if(!this->tablero.Colision(*(this->pieza1))){
            this->colision = false;
        }
        else if(this->c_colision.getElapsedTime().asSeconds() >0.5){

            this->colision = false;

            this->tablero.CopiarPiezas(*(this->pieza1));

            this->pieza1 = NULL;
            this->pieza1 = new Pieza(this->cola.front());

            if(this->tablero.Colision2(*(this->pieza1))){
                //FIN DEL JUEGO
                std::cout << "Dedicate al parchis" << std::endl;
                this->window.close();
            }

            int pieza_cola = this->gen.Generar();
            this->cola.pop();
            this->cola.push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<this->n_p ; i++){
                if(i!=(n_p-1)){
                    this->piezas_sig[i] = NULL;
                    this->piezas_sig[i] = new Pieza(this->piezas_sig[i+1]->getTipo());
                    this->piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    this->piezas_sig[i] = NULL;
                    this->piezas_sig[i] = new Pieza(pieza_cola);
                    this->piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

            this->reloj.restart();
        }
    }
}

//EN CASO QUE QUIERA GUARDAR LA PIEZA
void Juego::GuardaPieza() {
    if(this->guardar_pieza){
        if(!this->pieza_auxiliar){
            //SI NO HAY NINGUNA PIEZA GUARDADA

            this->pieza_auxiliar = new Pieza(this->pieza1->getTipo());

            delete this->pieza1;
            this->pieza1 = NULL;
            this->pieza1 = new Pieza(this->cola.front());

            int pieza_cola = this->gen.Generar();
            this->cola.pop();
            this->cola.push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<this->n_p ; i++){
                if(i!=(n_p-1)){
                    this->piezas_sig[i] = NULL;
                    this->piezas_sig[i] = new Pieza(this->piezas_sig[i+1]->getTipo());
                    this->piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    this->piezas_sig[i] = NULL;
                    this->piezas_sig[i] = new Pieza(pieza_cola);
                    this->piezas_sig[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

        }
        else{
            int tipo_aux = this->pieza_auxiliar->getTipo();

            delete this->pieza_auxiliar;
            this->pieza_auxiliar = NULL;
            this->pieza_auxiliar = new Pieza(this->pieza1->getTipo());

            delete this->pieza1;
            this->pieza1 = NULL;
            this->pieza1 = new Pieza(tipo_aux);

        }

        this->pieza_auxiliar->ColocarFuera();

        this->guardar_pieza = false;
        this->reloj.restart();
    }
}

//CHECKEA LOS EVENTOS DE LAS TECLAS
void Juego::Eventos(sf::Event event) {
    if(this->window.pollEvent(event)){
        switch(event.type){
            case sf::Event::EventType::KeyPressed:
                if(event.key.code == sf::Keyboard::Key::Q || event.key.code == sf::Keyboard::Key::Escape){
                    this->window.close();
                }
                
                if(event.key.code == sf::Keyboard::Key::D){
                    this->pieza1[0]->Mover('r');

                    if(this->tablero[0].Colision2(*(this->pieza1[0]))){
                        this->pieza1[0]->Mover('l');
                    }

                }
                if(event.key.code == sf::Keyboard::Key::Right){
                    this->pieza1[1]->Mover('r');

                    if(this->tablero[1].Colision2(*(this->pieza1[1]))){
                        this->pieza1[1]->Mover('l');
                    }

                }
                
                if(event.key.code == sf::Keyboard::Key::A){
                    this->pieza1[0]->Mover('l');

                    if(tablero[0].Colision2(*(this->pieza1[0]))){
                        this->pieza1[0]->Mover('r');
                    }

                }
                if(event.key.code == sf::Keyboard::Key::Left){
                    this->pieza1[1]->Mover('l');

                    if(tablero[1].Colision2(*(this->pieza1[1]))){
                        this->pieza1[1]->Mover('r');
                    }

                }
                
                if(event.key.code == sf::Keyboard::Key::S){
                    this->m_d = true;
                }
                if(event.key.code == sf::Keyboard::Key::Down){
                    this->m_d_J2 = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::G){
                    //cout << "Guardo pieza" << endl;
                    this->guardar_pieza = true;
                }
                if(event.key.code == sf::Keyboard::Key::Numpad2){
                    //cout << "Guardo pieza" << endl;
                    this->guardar_pieza_J2 = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::F){
                    this->pieza1->Rotacion('r');
                    if(this->tablero.Colision2(*(this->pieza1))){
                        this->pieza1->Rotacion('l');
                    }
                }
                if(event.key.code == sf::Keyboard::Key::Numpad1){
                    this->pieza1_J2->Rotacion('r');
                    if(this->tablero_J2.Colision2(*(this->pieza1_J2))){
                        this->pieza1_J2->Rotacion('l');
                    }
                }
                break;

            case sf::Event::EventType::KeyReleased:
                if(event.key.code == sf::Keyboard::Key::S){
                    this->m_d = false;
                }
                if(event.key.code == sf::Keyboard::Key::Down){
                    this->m_d_J2 = false;
                }
                break;
            default:
                break;

        }
    }
}

//MUEVE LA PIEZA HACIA ABAJO
void Juego::MovAbajo(int pos) {
    if(this->reloj[pos].getElapsedTime().asSeconds() > 0.3){
            //MOVER LA PIEZA HACIA ABAJO
            
            if(!this->tablero[pos].Colision( *(this->pieza1[pos]) )){
                this->pieza1[pos]->Mover('d');
            }
            this->reloj[pos].restart();
        }
}

//GENERA LAS PIEZAS NECESARIAS
void Juego::GeneraPiezas(int pos) {
    for(int i=0 ; i<(this->n_p[pos]+1) ; i++){
        if(i==0){
            this->pieza1[pos] = new Pieza(this->gen[pos].Generar());
        }
        else{
            int aux_g = this->gen[pos].Generar();
            
            //CREA Y COLOCA LAS PRIMERAS 4 PIEZAS QUE REPRESENTAN LAS SIGUIENTES
            (this->piezas_sig[pos])[i-1] = new Pieza(aux_g);
            (this->piezas_sig[pos])[i-1]->ColocarPiezasSiguientes((i-1)*60);
            
            this->cola[pos].push(aux_g);
        }
    }
}


//GETTER
bool Juego::abierto() {
    return this->window.isOpen();
}

//SETTER
void Juego::setVista(sf::View view) {
    this->window.setView(view);
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

