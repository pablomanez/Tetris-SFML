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
#include <iostream>

#include "TextoLineas.h"

TextoLineas::TextoLineas() {
    /*
    sf::Font font;
    font.loadFromFile("../assets/fuentes/PressStart2P.ttf");
    
    this->texto.setFont(font);
    this->texto.setCharacterSize(10);
    this->texto.setFillColor(sf::Color::White);
    */
    
    this->n_lineas = 0;
    
}

TextoLineas::TextoLineas(const TextoLineas& orig) {
}

void TextoLineas::Actualizar(Tablero& tablero) {
    this->n_lineas += tablero.Linea();
    
}

void TextoLineas::Dibujar(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("../assets/fuentes/PressStart2P.ttf");
    
    sf::Text texto;
    
    texto.setFont(font);
    texto.setCharacterSize(10);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(sf::Vector2f(9,410));
    
    std::string aux = "Lineas: ";
    
    std::string s_lineas = aux.operator +=(std::to_string(this->n_lineas));
    texto.setString(s_lineas);
    
    //std::cout << "Funca" << std::endl;
    
    window.draw(texto);
}

//GETTER
int TextoLineas::getLineas() {
    return this->n_lineas;
}



TextoLineas::~TextoLineas() {
}

