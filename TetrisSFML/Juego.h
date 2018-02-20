/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: pablomanez
 *
 * Created on 18 de febrero de 2018, 21:27
 */

#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "TextoLineas.h"


class Juego {
public:
    Juego();
    void Bucle();
    void Eventos(sf::Event event);
    void Update();
    void Render();
    
    void MovAbajo(int pos);
    void GuardaPieza();
    void ColisionPieza();
    void GeneraPiezas(int pos);
    
    //GETTER
    bool abierto();
    
    //SETTER
    void setVista(sf::View view);
    
    Juego(const Juego& orig);
    virtual ~Juego();
private:
    //NUMERO DE JUGADORES 1-2
    int J;
    
    //LA VENTANA
    sf::RenderWindow window;
    
    //MATRIZ 10x20 DE BLOQUES INICIALIZADOS A NULL
    Tablero tablero[2];
    
    //DETERMINA SI HA COLISIONADO UNA PIEZA
    bool colision[2];
    
    //EL TEXTO QUE APARECE
    TextoLineas lineas[2];
    
    //GUARDA LA PIEZA ACTUAL
    Pieza ** pieza_auxiliar[2];
    bool guardar_pieza [2];
    //Pieza * pieza_auxiliar;
    //bool guardar_pieza;
    
    //VARIABLES NECESARIAS PARA GENERAR LAS PIEZAS
    Pieza * pieza1[2];
    int n_p[2];
    Pieza ** piezas_sig[2];
    GenerarPiezas gen[2];
    std::queue<int> cola[2];
    /*
    Pieza * pieza1;
    int n_p;
    Pieza ** piezas_sig;
    GenerarPiezas gen;
    std::queue<int> cola;
    */
    
    //RELOJES
    sf::Clock reloj[2];
    sf::Clock c_colision[2];
    
    //PARA CONTROLES
    bool m_d[2];
};

#endif /* JUEGO_H */

