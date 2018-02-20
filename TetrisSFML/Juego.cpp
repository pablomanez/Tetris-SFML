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
#include <cstring>

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
    
    this->J = 1;
    if(this->J==1){
        //1 JUGADOR
        this->J1 = false;
    }
    else{
        //2 JUGADORES
        this->J1 = true;
    }
    
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
        for(int i=0 ; i<(this->J) ; i++){
            this->MovAbajo(i);
            sf::Event event;
            this->Eventos(event);
            
            this->Update(i);
        }
                
        //RENDER
        this->window.clear(sf::Color::Black);
            this->window.setView(view1);
            this->Render(0);
            
            if(this->J1){
                this->window.setView(view2);
                this->Render(1);
            }
        this->window.display();
        
    }
}

//EL RENDER
void Juego::Render(int pos) {
    //this->window.clear(sf::Color::Black);
    this->tablero[pos].Dibujar(this->window);
    this->lineas[pos].Dibujar(this->window,this->tablero[pos].getPuntuacionTotal());
    this->pieza1[pos]->Dibujar(this->window);
    
    Pieza *p_fin = new Pieza(this->pieza1[pos]->getTipo());
    for(int i=0 ; i<4 ; i++){
        p_fin->getBloques()[i].setPosicion(this->pieza1[pos]->getBloques()[i].getPosicion());
    }
    while(!(p_fin->getFase()==this->pieza1[pos]->getFase())){
        p_fin->Rotar('l');
    }
    this->DibujaPiezaFin(pos,*p_fin);
    
    delete p_fin;
    p_fin = NULL;
    
    for(int i=0 ; i<4 ; i++){
        (this->piezas_sig[pos])[i]->Dibujar(this->window);

    }

    if(this->pieza_auxiliar[pos]){
        this->pieza_auxiliar[pos]->Dibujar(this->window);

    }
    
    //this->window.display();
}

//EL UPDEIT
void Juego::Update(int pos) {
    //ACTUALIZO OBJETOS
    if(!this->colision[pos]){
        this->colision[pos] = this->tablero[pos].Colision(*(this->pieza1[pos]));
        this->c_colision[pos].restart();
    }

    if(this->m_d[pos]){
        if(!this->tablero[pos].Colision(*(this->pieza1[pos]))){
            this->pieza1[pos]->Mover('d');
        }
    }
    
    //STRING QUE MARCA LAS LINEAS HECHAS QUE LLEVA EL JUGADOR
    this->lineas[pos].Actualizar(this->tablero[pos]);

    this->GuardaPieza(pos);
    
    this->ColisionPieza(pos);
    
}

//EN CASO QUE HAYA COLISIONADO CON UNA PIEZA O EL FONDO
void Juego::ColisionPieza(int pos) {
    if(this->colision[pos]){

        if(!this->tablero[pos].Colision(*(this->pieza1[pos]))){
            this->colision[pos] = false;
        }
        else if(this->c_colision[pos].getElapsedTime().asSeconds() >0.5){

            this->colision[pos] = false;

            this->tablero[pos].CopiarPiezas(*(this->pieza1[pos]));

            this->pieza1[pos] = NULL;
            this->pieza1[pos] = new Pieza(this->cola[pos].front());

            if(this->tablero[pos].Colision2(*(this->pieza1[pos]))){
                //FIN DEL JUEGO
                std::cout << "Dedicate al parchis" << std::endl;
                this->window.close();
            }

            int pieza_cola = this->gen[pos].Generar();
            this->cola[pos].pop();
            this->cola[pos].push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<this->n_p[pos] ; i++){
                if(i!=(n_p[pos]-1)){
                    (this->piezas_sig[pos])[i] = NULL;
                    (this->piezas_sig[pos])[i] = new Pieza((this->piezas_sig[pos])[i+1]->getTipo());
                    (this->piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    (this->piezas_sig[pos])[i] = NULL;
                    (this->piezas_sig[pos])[i] = new Pieza(pieza_cola);
                    (this->piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

            this->reloj[pos].restart();
        }
    }
}

//EN CASO QUE QUIERA GUARDAR LA PIEZA
void Juego::GuardaPieza(int pos) {
    if(this->guardar_pieza[pos]){
        if(!this->pieza_auxiliar[pos]){
            //SI NO HAY NINGUNA PIEZA GUARDADA

            this->pieza_auxiliar[pos] = new Pieza(this->pieza1[pos]->getTipo());

            delete this->pieza1[pos];
            this->pieza1[pos] = NULL;
            this->pieza1[pos] = new Pieza(this->cola[pos].front());

            int pieza_cola = this->gen[pos].Generar();
            this->cola[pos].pop();
            this->cola[pos].push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<this->n_p[pos] ; i++){
                if(i!=(n_p[pos]-1)){
                    (this->piezas_sig[pos])[i] = NULL;
                    (this->piezas_sig[pos])[i] = new Pieza((this->piezas_sig[pos])[i+1]->getTipo());
                    (this->piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    (this->piezas_sig[pos])[i] = NULL;
                    (this->piezas_sig[pos])[i] = new Pieza(pieza_cola);
                    (this->piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

        }
        else{
            int tipo_aux = this->pieza_auxiliar[pos]->getTipo();

            delete this->pieza_auxiliar[pos];
            this->pieza_auxiliar[pos] = NULL;
            this->pieza_auxiliar[pos] = new Pieza(this->pieza1[pos]->getTipo());

            delete this->pieza1[pos];
            this->pieza1[pos] = NULL;
            this->pieza1[pos] = new Pieza(tipo_aux);

        }

        this->pieza_auxiliar[pos]->ColocarFuera();

        this->guardar_pieza[pos] = false;
        this->reloj[pos].restart();
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
                    this->m_d[0] = true;
                }
                if(event.key.code == sf::Keyboard::Key::Down){
                    this->m_d[1] = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::G){
                    //cout << "Guardo pieza" << endl;
                    this->guardar_pieza[0] = true;
                }
                if(event.key.code == sf::Keyboard::Key::Numpad2){
                    //cout << "Guardo pieza" << endl;
                    this->guardar_pieza[1] = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::F){
                    this->pieza1[0]->Rotacion('r');
                    if(this->tablero[0].Colision2(*(this->pieza1[0]))){
                        this->pieza1[0]->Rotacion('l');
                    }
                }
                if(event.key.code == sf::Keyboard::Key::Numpad1){
                    this->pieza1[1]->Rotacion('r');
                    if(this->tablero[1].Colision2(*(this->pieza1[1]))){
                        this->pieza1[1]->Rotacion('l');
                    }
                }
                break;

            case sf::Event::EventType::KeyReleased:
                if(event.key.code == sf::Keyboard::Key::S){
                    this->m_d[0] = false;
                }
                if(event.key.code == sf::Keyboard::Key::Down){
                    this->m_d[1] = false;
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

//DIBUJA LA PIEZA FINAL
void Juego::DibujaPiezaFin(int pos, Pieza &pieza) {
    while(!this->tablero[pos].Colision(pieza)){
        pieza.Mover('d');
    }
    
    pieza.Dibujar(this->window);
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

