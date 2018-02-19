/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pablomanez
 *
 * Created on 7 de febrero de 2018, 16:26
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

#include "Bloque.h"
#include "Pieza.h"
#include "Tablero.h"
#include "GenerarPiezas.h"
#include "TextoLineas.h"

#include "Juego.h"
using namespace std;

/*
 * ANTES:   334 LINEAS (CONTANDO COMENTARIOS)
 * DESPUES: 3 LINEAS
 */

int main(int argc, char** argv) {
    Juego juego;
    juego.Bucle();
    return 0;
}

