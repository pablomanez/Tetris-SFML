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
    void Bucle();
    
    void GeneraPiezas();
    void GeneraPiezas_J2();
    
    void Eventos(sf::Event event);
    void Eventos_J2(sf::Event event);
    
    void Update();
    void Update_J2();
    
    void Render();
    void Render_J2();
    
    void MovAbajo();
    void MovAbajo_J2();
    
    void GuardaPieza();
    void GuardaPieza_J2();

    void ColisionPieza();
    void ColisionPieza_J2();
    
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
    
    Tablero tablero_J2;
    
    //DETERMINA SI HA COLISIONADO UNA PIEZA
    bool colision;
    
    bool colision_J2;
    
    //EL TEXTO QUE APARECE
    TextoLineas lineas;
    
    TextoLineas lineas_J2;
    
    //GUARDA LA PIEZA ACTUAL
    Pieza * pieza_auxiliar;
    bool guardar_pieza;
    
    Pieza * pieza_auxiliar_J2;
    bool guardar_pieza_J2;
    
    //VARIABLES NECESARIAS PARA GENERAR LAS PIEZAS
    Pieza * pieza1;
    int n_p;
    Pieza ** piezas_sig;
    GenerarPiezas gen;
    std::queue<int> cola;
    
    Pieza * pieza1_J2;
    int n_p_J2;
    Pieza ** piezas_sig_J2;
    GenerarPiezas gen_J2;
    std::queue<int> cola_J2;
    
    //RELOJES
    sf::Clock reloj;
    sf::Clock c_colision;
    
    sf::Clock reloj_J2;
    sf::Clock c_colision_J2;
    
    //PARA CONTROLES
    bool m_d;
    
    bool m_d_J2;
};

#endif /* JUEGO_H */

