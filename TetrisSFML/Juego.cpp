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
#include "St.h"

#include "Juego.h"

Juego::Juego():
    window(sf::VideoMode(640,480), "Tetris", sf::Style::Default)

{
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);
    
    //VISTA DEL JUGADOR 1
    view1.setCenter(320,240);
    view1.setSize(640,480);
    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    //VISTA DEL JUGADOR 2
    view2.setCenter(0,240);
    view2.setSize(640,480);
    view2.setViewport(sf::FloatRect(0, 0, 1, 1));
    
    J = 1;
    if(J==1){
        //1 JUGADOR
        J1 = false;
        
        st = new St;
    }
    else{
        //2 JUGADORES
        J1 = true;
    }
    
    //ARRAYS
    for(int i=0 ; i<J ; i++){
        pieza_auxiliar[i] = NULL;
        guardar_pieza[i] = false;
        
        pieza1[i] = NULL;
        pieza_fin[i] = NULL;
        
        n_p[i] = 20;
        piezas_sig[i] = new Pieza*[n_p[i]];
        GeneraPiezas(i);
        
        m_d[i] = false;
        
        tetris[i] = false;
        n_lineas[i] = 0;
        count_t[i] = 0;
    }
}

//UN PERRO
void Juego::Bucle() {
    /*
    //VISTA DEL JUGADOR 1
    sf::View view1(sf::FloatRect(0,0,640,480));
    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    
    //VISTA DEL JUGADOR 2
    sf::View view2(sf::FloatRect(-320,0,640,480));
    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    */
    
    timeStartUpdate[0] = dt[0].getElapsedTime();
    timeStartUpdate[1] = dt[1].getElapsedTime();
        
    while(window.isOpen()){
        for(int i=0 ; i<J ; i++){
            MovAbajo(i);

            sf::Event event;
            Eventos(event);
            
            if(dt[i].getElapsedTime().asMilliseconds() - timeStartUpdate[i].asMilliseconds() > 1000/15){
                Update(i);
                    //std::cout << dt.getElapsedTime().asSeconds() << std::endl;
                timeStartUpdate[i] = dt[i].getElapsedTime();
            }
        }

        //RENDER
        window.clear(sf::Color::Black);
            window.setView(view1);
            Render(0);
            
            if(J1){
                window.setView(view2);
                Render(1);
            }
        window.display();
        
    }
}

//EL RENDER
void Juego::Render(int pos) {
    //window.clear(sf::Color::Black);
    
    tablero[pos].Dibujar(window);
    lineas[pos].Dibujar(window,tablero[pos].getPuntuacionTotal());
    pieza_fin[pos]->Dibujar(window);
    pieza1[pos]->Dibujar(window);
    
    for(int i=0 ; i<4 ; i++){
        //std::cout << "Aqui no peta" << std::endl;
        (piezas_sig[pos])[i]->Dibujar(window);

    }

    if(pieza_auxiliar[pos]){
        
        pieza_auxiliar[pos]->Dibujar(window);

    }
    
    if(J==1){
        st->Dibuja(window);
    }
    
    //window.display();
}

//EL UPDEIT
void Juego::Update(int pos) {
    //ACTUALIZO OBJETOS
    if(!colision[pos]){
        colision[pos] = tablero[pos].Colision(*(pieza1[pos]));
        c_colision[pos].restart();
    }

    if(m_d[pos]){
        if(!tablero[pos].Colision(*(pieza1[pos]))){
            pieza1[pos]->Mover('d');
        }
    }
    
    //CONTROL DE LAS LINEAS
    int l_aux1 = lineas[pos].getLineas();
    lineas[pos].Actualizar(tablero[pos]);
    int l_aux2 = lineas[pos].getLineas();
    
    if(n_lineas[pos]==4){
        tetris[pos] = true;
        count_t[pos] = 4;
    }
    if(tetris[pos]){
        HazTetris(pos);
    }
    
    l_aux1 != l_aux2 ? n_lineas[pos] += l_aux2-l_aux1 : n_lineas[pos] = 0;
        
    //UPDATE DE LUCHA
    if(!J1){
        UpdateLucha(l_aux1,l_aux2);
    }    
    
    GuardaPieza(pos);
    
    ColisionPieza(pos);
        
    GeneraPiezaFin(pos);
    
}

//EFECTO MOLON
void Juego::HazTetris(int pos) {
    int var = 10;
    if(pos==0){
        //std::cout << "EL JUGADOR 1 HA HECHO TETRIS!!!" << std::endl;
        switch(count_t[pos]){
            case 4:
                view1.move(var,0);
                count_t[pos]--;
                break;
            case 3:
                view1.move(-var*2,0);
                count_t[pos]--;
                break;
            case 2:
                view1.move(var*2,0);
                count_t[pos]--;
                break;
            case 1:
                view1.move(-var,0);
                count_t[pos]--;
                break;
            default:
                tetris[pos] = false;
                break;
        }
        
        
    }
    else if(pos==1){
        //std::cout << "EL JUGADOR 2 HA HECHO TETRIS!!!" << std::endl;
        switch(count_t[pos]){
            case 4:
                view2.move(var,0);
                count_t[pos]--;
                break;
            case 3:
                view2.move(-var*2,0);
                count_t[pos]--;
                break;
            case 2:
                view2.move(var*2,0);
                count_t[pos]--;
                break;
            case 1:
                view2.move(-var,0);
                count_t[pos]--;
                break;
            default:
                tetris[pos] = false;
                break;
        }
        
    }
}

void Juego::UpdateLucha(int a, int b) {
    for(int i=0 ; i<(b-a) ; i++) st->BajaVidaEnemigo();

    if(st->getDeadAliado()){
        window.close();
    }

    if(st->getDeadEnemigo()){
        //std::cout << "Ronda pasada" << std::endl;
        st->SubeRonda();
    }

    if(r_lucha.getElapsedTime().asSeconds()>1.5){

        std::random_device rd;
        std::default_random_engine gen(rd());
        std::uniform_int_distribution<int> distribution(0,100);

        int r = distribution(gen);
            //std::cout << r << std::endl;
        if(r<15){
            st->BajaVidaAliado();

        }

        r_lucha.restart();
    }

    st->updateR();
    st->updateK();
}

//EN CASO QUE HAYA COLISIONADO CON UNA PIEZA O EL FONDO
void Juego::ColisionPieza(int pos) {
    if(colision[pos]){
        if(!tablero[pos].Colision(*(pieza1[pos]))){
            colision[pos] = false;
        }
        else if(c_colision[pos].getElapsedTime().asSeconds() >0.5){

            colision[pos] = false;

            tablero[pos].CopiarPiezas(*(pieza1[pos]));

            pieza1[pos] = NULL;
            pieza1[pos] = new Pieza(cola[pos].front());

            if(tablero[pos].Colision2(*(pieza1[pos]))){
                //FIN DEL JUEGO
                //std::cout << "Dedicate al parchis" << std::endl;
                window.close();
            }

            int pieza_cola = gen[pos].Generar();
            cola[pos].pop();
            cola[pos].push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<n_p[pos] ; i++){
                if(i!=(n_p[pos]-1)){
                    //delete (piezas_sig[pos])[i];
                    (piezas_sig[pos])[i] = NULL;
                    (piezas_sig[pos])[i] = new Pieza((piezas_sig[pos])[i+1]->getTipo());
                    (piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    //delete (piezas_sig[pos])[i];
                    (piezas_sig[pos])[i] = NULL;
                    (piezas_sig[pos])[i] = new Pieza(pieza_cola);
                    (piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

            reloj[pos].restart();
        }
    }
}

//EN CASO QUE QUIERA GUARDAR LA PIEZA
void Juego::GuardaPieza(int pos) {
    if(guardar_pieza[pos]){
        if(!pieza_auxiliar[pos]){
            //SI NO HAY NINGUNA PIEZA GUARDADA

            pieza_auxiliar[pos] = new Pieza(pieza1[pos]->getTipo());

            delete pieza1[pos];
            pieza1[pos] = NULL;
            pieza1[pos] = new Pieza(cola[pos].front());

            int pieza_cola = gen[pos].Generar();
            cola[pos].pop();
            cola[pos].push(pieza_cola);

            //RECARGA LAS PIEZAS QUE VIENEN A CONTINUACION
            for(int i=0 ; i<n_p[pos] ; i++){
                if(i!=(n_p[pos]-1)){
                    (piezas_sig[pos])[i] = NULL;
                    (piezas_sig[pos])[i] = new Pieza((piezas_sig[pos])[i+1]->getTipo());
                    (piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
                else{
                    (piezas_sig[pos])[i] = NULL;
                    (piezas_sig[pos])[i] = new Pieza(pieza_cola);
                    (piezas_sig[pos])[i]->ColocarPiezasSiguientes((i)*60);
                }
            }

        }
        else{
            int tipo_aux = pieza_auxiliar[pos]->getTipo();

            delete pieza_auxiliar[pos];
            pieza_auxiliar[pos] = NULL;
            pieza_auxiliar[pos] = new Pieza(pieza1[pos]->getTipo());

            delete pieza1[pos];
            pieza1[pos] = NULL;
            pieza1[pos] = new Pieza(tipo_aux);

        }

        pieza_auxiliar[pos]->ColocarFuera();

        guardar_pieza[pos] = false;
        reloj[pos].restart();
    }
}

//CHECKEA LOS EVENTOS DE LAS TECLAS
void Juego::Eventos(sf::Event event) {
    if(window.pollEvent(event)){
        
        switch(event.type){
            case sf::Event::EventType::KeyPressed:
                if(event.key.code == sf::Keyboard::Key::T){
                    st->BajaVidaEnemigo();
                }
                if(event.key.code == sf::Keyboard::Key::Y){
                    st->BajaVidaAliado();
                }
                if(event.key.code == sf::Keyboard::Key::Q || event.key.code == sf::Keyboard::Key::Escape){
                    window.close();
                }
                
                if(event.key.code == sf::Keyboard::Key::D){
                    pieza1[0]->Mover('r');
                    
                    if(tablero[0].Colision2(*(pieza1[0]))){
                        pieza1[0]->Mover('l');
                    }

                }
                
                if(event.key.code == sf::Keyboard::Key::A){
                    pieza1[0]->Mover('l');

                    if(tablero[0].Colision2(*(pieza1[0]))){
                        pieza1[0]->Mover('r');
                    }

                }
                
                
                if(event.key.code == sf::Keyboard::Key::S){
                    m_d[0] = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::J){
                    //cout << "Guardo pieza" << endl;
                    guardar_pieza[0] = true;
                }
                
                if(event.key.code == sf::Keyboard::Key::H){
                    pieza1[0]->Rotacion('r');
                    if(tablero[0].Colision2(*(pieza1[0]))){
                        pieza1[0]->Rotacion('l');
                    }
                }
                if(J==2){
                    if(event.key.code == sf::Keyboard::Key::Right){
                        pieza1[1]->Mover('r');

                        if(tablero[1].Colision2(*(pieza1[1]))){
                            pieza1[1]->Mover('l');
                        }

                    }
                    if(event.key.code == sf::Keyboard::Key::Left){
                        pieza1[1]->Mover('l');

                        if(tablero[1].Colision2(*(pieza1[1]))){
                            pieza1[1]->Mover('r');
                        }

                    }
                    if(event.key.code == sf::Keyboard::Key::Down){
                        m_d[1] = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Numpad2){
                        //cout << "Guardo pieza" << endl;
                        guardar_pieza[1] = true;
                    }
                    if(event.key.code == sf::Keyboard::Key::Numpad1){
                        pieza1[1]->Rotacion('r');
                        if(tablero[1].Colision2(*(pieza1[1]))){
                            pieza1[1]->Rotacion('l');
                        }
                    }
                }
                break;

            case sf::Event::EventType::KeyReleased:
                if(event.key.code == sf::Keyboard::Key::S){
                    m_d[0] = false;
                }
                
                if(J==2){
                    if(event.key.code == sf::Keyboard::Key::Down){
                        m_d[1] = false;
                    }
                }
                
                break;
            default:
                break;

        }
    }
}

//MUEVE LA PIEZA HACIA ABAJO
void Juego::MovAbajo(int pos) {
    if(reloj[pos].getElapsedTime().asSeconds() > 0.3){        
        //MOVER LA PIEZA HACIA ABAJO
        if(!tablero[pos].Colision( *(pieza1[pos]) )){
            pieza1[pos]->Mover('d');
        }
        reloj[pos].restart();
    }
}

//GENERA LAS PIEZAS NECESARIAS
void Juego::GeneraPiezas(int pos) {
    for(int i=0 ; i<(n_p[pos]+1) ; i++){
        if(i==0){
            int gen_aux = gen[pos].Generar();
            pieza1[pos] = new Pieza(gen_aux);
            
            pieza_fin[pos] = new Pieza(gen_aux);
            pieza_fin[pos]->CambiaColor(sf::Color (187,187,187,120));
            
        }
        else{
            int aux_g = gen[pos].Generar();
            
            //CREA Y COLOCA LAS PRIMERAS 4 PIEZAS QUE REPRESENTAN LAS SIGUIENTES
            (piezas_sig[pos])[i-1] = new Pieza(aux_g);
            (piezas_sig[pos])[i-1]->ColocarPiezasSiguientes((i-1)*60);
            
            cola[pos].push(aux_g);
        }
    }
}

//CALCULA LA POSICION FINAL Y LA ROTACION DE LA PIEZA FIN
void Juego::GeneraPiezaFin(int pos) {
    //GIRO LA PIEZA
    
    if(pieza_fin[pos]->getFase()!=pieza1[pos]->getFase()){
        pieza_fin[pos]->Rotacion('r');
    }
    
    //MUEVO LA PIEZA FIN HACIA ABAJO DEL TODO
    for(int i=0 ; i<4 ; i++){
        pieza_fin[pos]->getBloques()[i].setPosicion(pieza1[pos]->getBloques()[i].getPosicion());
    }
    
    while(!tablero[pos].Colision( *(pieza_fin[pos]) )){
        pieza_fin[pos]->Mover('d');
    }
    
}

//GETTER
bool Juego::abierto() {
    return window.isOpen();
}

//SETTER
void Juego::setVista(sf::View view) {
    window.setView(view);
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

