/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenerarPiezas.cpp
 * Author: pablomanez
 * 
 * Created on 11 de febrero de 2018, 13:52
 */
#include <iostream>
#include <random>
#include <SFML/System/Vector3.hpp>

#include "GenerarPiezas.h"

GenerarPiezas::GenerarPiezas() {
    b = 100.000000/7.000000;
            
    //ASIGNAR PROBABILIDAD A CADA UNO
    for(int i=0 ; i<7 ; i++){
        
        piezas[i].x = b*i;
        piezas[i].y = b*(i+1);
        piezas[i].z = i+1;
        
    }
    
}

GenerarPiezas::GenerarPiezas(const GenerarPiezas& orig) {
}

int GenerarPiezas::Generar() {
    //PRIMERO GENERO EL NUMERO ALEATORIO
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<double> distribution(0,100);
    
    double r = distribution(gen);
    
    //BUSCO EL NUMERO ELEGIDO EN MI ARRAY PIEZAS
    int p;
    
    for(int i=0 ; i<7 ; i++){
        if(piezas[i].x<=r && piezas[i].y>r){
            p = i;
            
            break;
        }
    }
    
    //EL NUMERO QUE DEVUELVO
    int dev = piezas[p].z;
    
    //P ES LA POSICION DEL ARRAY PIEZAS A LLEVAR A 0 SU PROBABILIDAD
    piezas[p].x = -1;
    piezas[p].y = -1;
    
    //REORDENO EL ARRAY
    sf::Vector3f aux[7] = piezas;
    sf::Vector3f cero = aux[p];
    
    if(p!=0){

        for(int i=p ; i>0 ; i--){
            aux[i] = aux[i-1];
            
        }

        aux[0] = cero;
        //piezas = aux;
        for(int j=0 ; j<7 ; j++){
            piezas[j] = aux[j];
        }
        
    }
    
    if(piezas[1].x == -1){
        //SI ENTRA AQUI, SIGNIFICA QUE ES EL NUMERO DE LA ITERACION ANTERIOR
        piezas[1].x = 0;
        piezas[1].y = b;
    }
    
    //CALCULO PRIMERO LA CANTIDAD QUE HAY QUE SUMAR A LOS DEMAS NUMEROS
    float can = 0.000000;
    
    for(int i=1 ; i<7 ; i++){
        can += (piezas[i].y-piezas[i].x);
    }
    can = 100-can;
    
    //std::cout << "Can: " << can << std::endl;
    
    //RECALCULO LA PROBABILIDAD DEL ARRAY PIEZAS
    double b2 = 100.000000/6.000000;
    
    for(int i=1 ; i<7 ; i++){
        if(i==1){
            piezas[i].x = 0;
            piezas[i].y += (can/6.000000);
        }
        else if(i!=6){
            piezas[i].x = piezas[i-1].y;
            piezas[i].y += (can/6.000000);
        }
        else{
            piezas[i].x = piezas[i-1].y;
            piezas[i].y = 100.000000;
        }
    }
    //Debug();
    
    return dev;
}

void GenerarPiezas::Debug(){
    //COUT PARA DEBUG
    for(int i=0 ; i<7 ; i++){
        std::cout << "piezas[" << i << "]:" << std:: endl;
        std::cout << "  x: " << piezas[i].x << std::endl;
        std::cout << "  y: " << piezas[i].y << std::endl;
        std::cout << "  z: " << piezas[i].z << std::endl;           
    }
    std::cout << "/////////////////////////////////////////" << std::endl;
}

GenerarPiezas::~GenerarPiezas() {
}

