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


class Juego {
public:
    Juego();
    void GeneraPiezas();
    void Bucle();
    void Eventos(sf::Event event);
    void Update();
    void Render();
    
    void MovAbajo();
    void GuardaPieza();
    void ColisionPieza();
    
    //GETTER
    bool abierto();
    
    //SETTER
    void setVista(sf::View view);
    
    Juego(const Juego& orig);
    virtual ~Juego();
private:
    //LA VENTANA
    sf::RenderWindow window;
    
    //MATRIZ 10x20 DE BLOQUES INICIALIZADOS A NULL
    Tablero tablero;
    
    //DETERMINA SI HA COLISIONADO UNA PIEZA
    bool colision;
    
    //EL TEXTO QUE APARECE
    TextoLineas lineas;
    
    //GUARDA LA PIEZA ACTUAL
    Pieza * pieza_auxiliar;
    bool guardar_pieza;
    
    //VARIABLES NECESARIAS PARA GENERAR LAS PIEZAS
    Pieza * pieza1;
    int n_p;
    Pieza ** piezas_sig;
    GenerarPiezas gen;
    std::queue<int> cola;
    
    //RELOJES
    sf::Clock reloj;
    sf::Clock c_colision;
    
    //PARA CONTROLES
    bool m_d;
};

#endif /* JUEGO_H */

