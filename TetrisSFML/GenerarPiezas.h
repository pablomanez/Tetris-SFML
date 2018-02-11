/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenerarPiezas.h
 * Author: pablomanez
 *
 * Created on 11 de febrero de 2018, 13:52
 */

#ifndef GENERARPIEZAS_H
#define GENERARPIEZAS_H

#include <SFML/System/Vector3.hpp>


class GenerarPiezas {
public:
    GenerarPiezas();
    GenerarPiezas(const GenerarPiezas& orig);
    
    int Generar();
    void Debug();
    virtual ~GenerarPiezas();
private:
    sf::Vector3f piezas[7];
    
    double b;

};

#endif /* GENERARPIEZAS_H */

