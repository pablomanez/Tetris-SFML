/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextoLineas.cpp
 * Author: pablomanez
 * 
 * Created on 13 de febrero de 2018, 12:27
 */
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "TextoLineas.h"

TextoLineas::TextoLineas() {
    sf::Font font;
    font.loadFromFile("../assets/fuentes/PressStart2P.ttf");
    
    this->texto.setFont(font);
    this->texto.setCharacterSize(10);
    this->texto.setFillColor(sf::Color::White);
    
    this->n_lineas = 0;
    this->s_lineas = "Lineas: ";
    
}

TextoLineas::TextoLineas(const TextoLineas& orig) {
}

void TextoLineas::Actualizar(Tablero& tablero) {
    this->n_lineas += tablero.Linea();
    
    std::string aux = "Lineas: ";
    
    this->s_lineas = aux.operator +=(std::to_string(this->n_lineas));
    this->texto.setString(s_lineas);
}

void TextoLineas::Dibujar(sf::RenderWindow& window) {
    window.draw(this->texto);
}

//GETTER
sf::Text TextoLineas::getTexto() {
    return this->texto;
}

int TextoLineas::getLineas() {
    return this->n_lineas;
}



TextoLineas::~TextoLineas() {
}

