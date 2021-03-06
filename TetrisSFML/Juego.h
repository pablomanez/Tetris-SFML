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
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>

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
    void UpdateLucha(int a, int b);
    void HazTetris(int pos);
    void GeneraPiezaFin(int pos);
    void ManejarEventos(int pos);
    
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
    sf::View view1;
    sf::View view2;
    
    
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
    
    sf::Clock dt[2]; //DELTA TIME
    sf::Time timeStartUpdate[2]; //ELAPSED TIME
    
    
    //PARA CONTROLES
    bool m_d[2]; //ABAJO
    bool m_r[2]; //DERECHA
    bool m_l[2]; //IZQUIERDA
    bool g_p[2]; //GUARDAR LA PIEZA
    bool r_p[2]; //ROTAR LA PIEZA
    
    //PIEZA QUE MUESTRA LA POSICION FINAL
    Pieza * pieza_fin[2];
    
    //LUCHA
    St *st;
    sf::Clock r_lucha;
    
    //PARA CUANDO SE HAGA TETRIS
    bool tetris[2]; //true: se ha hecho tetris
    int n_lineas[2];  //1-2-3-4
    int count_t[2];
    
    //MUSICA
    sf::Music musica;
    sf::Music punch;
};

#endif /* JUEGO_H */

