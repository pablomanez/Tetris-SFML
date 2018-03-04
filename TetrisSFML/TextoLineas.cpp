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
    font.loadFromFile("../assets/fuentes/PressStart2P.ttf");
    
    this->n_lineas = 0;
    
}

TextoLineas::TextoLineas(const TextoLineas& orig) {
}

void TextoLineas::Actualizar(Tablero& tablero) {
    this->n_lineas += tablero.Linea();
    //std::cout << n_lineas << std::endl;
    
}

void TextoLineas::Dibujar(sf::RenderWindow& window, int puntos) {
    /*
    sf::Font font;
    font.loadFromFile("../assets/fuentes/PressStart2P.ttf");
    */
    
        
    
    sf::Text texto;
    sf::Text texto2;
    sf::Text texto3;
    sf::Text texto4;
    
    //NUMERO DE LINEAS
    texto.setFont(font);
    texto.setCharacterSize(16);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(sf::Vector2f(20,422));
    
    std::string aux = "LINES:";
    
    std::string s_lineas = aux.operator +=(std::to_string(this->n_lineas));
    texto.setString(s_lineas);
    
    //HOLD    
    texto2.setFont(font);
    texto2.setCharacterSize(16);
    texto2.setFillColor(sf::Color::White);
    texto2.setPosition(sf::Vector2f(234,302));
    
    std::string aux2 = "HODL:";
    texto2.setString(aux2);
    
    //NEXT
    texto3.setFont(font);
    texto3.setCharacterSize(16);
    texto3.setFillColor(sf::Color::White);
    texto3.setPosition(sf::Vector2f(234,0));
    
    std::string aux3 = "NEXT:";
    texto3.setString(aux3);
    
    //PUNTUACION
    texto4.setFont(font);
    texto4.setCharacterSize(16);
    texto4.setFillColor(sf::Color::White);
    texto4.setPosition(sf::Vector2f(20,442));
    
    std::string aux4 = "SCORE:";
    
    std::string s_lineas2 = aux4.operator +=(std::to_string(puntos));
    texto4.setString(s_lineas2);
    
    //DIBUJAR
    window.draw(texto4);
    window.draw(texto3);
    window.draw(texto2);
    window.draw(texto);
    
}

//GETTER
int TextoLineas::getLineas() {
    return this->n_lineas;
}



TextoLineas::~TextoLineas() {
}

