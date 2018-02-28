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
#include "GenerarPiezas.h"
#include "St.h"


class Juego {
public:
    Juego();
    void Bucle();
    void Eventos(sf::Event event);
    void Update(int pos);
    void Render(int pos);
    
    void MovAbajo(int pos);
    void GuardaPieza(int pos);
    void ColisionPieza(int pos);
    void GeneraPiezas(int pos);
    
    void GeneraPiezaFin(int pos);
    
    //GETTER
    bool abierto();
    
    //SETTER
    void setVista(sf::View view);
    
    Juego(const Juego& orig);
    virtual ~Juego();
private:
    //NUMERO DE JUGADORES 1-2
    int J;
    bool J1;
    
    //LA VENTANA
    sf::RenderWindow window;
    
    //MATRIZ 10x20 DE BLOQUES INICIALIZADOS A NULL
    Tablero tablero[2];
    
    //DETERMINA SI HA COLISIONADO UNA PIEZA
    bool colision[2];
    
    //EL TEXTO QUE APARECE
    TextoLineas lineas[2];
    
    //GUARDA LA PIEZA ACTUAL
    Pieza * pieza_auxiliar[2];
    bool guardar_pieza [2];
    //Pieza * pieza_auxiliar;
    //bool guardar_pieza;
    
    //VARIABLES NECESARIAS PARA GENERAR LAS PIEZAS
    Pieza * pieza1[2];
    int n_p[2];
    Pieza ** piezas_sig[2];
    GenerarPiezas gen[2];
    std::queue<int> cola[2];
    
    //RELOJES
    sf::Clock reloj[2];
    sf::Clock c_colision[2];
    
    //PARA CONTROLES
    bool m_d[2];
    
    //PIEZA QUE MUESTRA LA POSICION FINAL
    Pieza * pieza_fin[2];
    
    //LUCHA
    St *st;
};

#endif /* JUEGO_H */

