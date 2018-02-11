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
    this->b = 100.000000/7.000000;
            
    //ASIGNAR PROBABILIDAD A CADA UNO
    for(int i=0 ; i<7 ; i++){
        
        this->piezas[i].x = b*i;
        this->piezas[i].y = b*(i+1);
        this->piezas[i].z = i+1;
        
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
        if(this->piezas[i].x<=r && this->piezas[i].y>r){
            p = i;
            
            break;
        }
    }
    this->Debug();
    
    //EL NUMERO QUE DEVUELVO
    int dev = this->piezas[p].z;
    
    //P ES LA POSICION DEL ARRAY PIEZAS A LLEVAR A 0 SU PROBABILIDAD
    this->piezas[p].x = -1;
    this->piezas[p].y = -1;
    
    //REORDENO EL ARRAY
    if(p!=0){
        sf::Vector3f aux = this->piezas[p];

        for(int i=p ; i>0 ; i--){
            sf::Vector3f pa;
            pa.x = this->piezas[p-1].x;
            pa.y = this->piezas[p-1].y;
            pa.z = this->piezas[p-1].z;
            
            
            this->piezas[p] = pa;
            
            std::cout << "---------------ITERACION " << i << "---------------" << std::endl;
            this->Debug();
        }

        this->piezas[0] = aux;
    }
    this->Debug();
    
    
    /*
    if(this->piezas[1].x == -1){
            //SI ENTRA AQUI, SIGNIFICA QUE ES EL NUMERO DE LA ITERACION ANTERIOR
            this->piezas[1].x = 0;
            this->piezas[1].y = this->b;
        }
    
    //CALCULO PRIMERO LA CANTIDAD QUE HAY QUE SUMAR A LOS DEMAS NUMEROS
    float can = 0.000000;
    
    for(int i=1 ; i<7 ; i++){
        can += (piezas[i].y-piezas[i].x);
    }
    
    //RECALCULO LA PROBABILIDAD DEL ARRAY PIEZAS
    double b2 = 100.000000/6.000000;
    
    for(int i=1 ; i<7 ; i++){
        if(i!=6){
            this->piezas[i].x = this->piezas[i-1].y;
            this->piezas[i].y += (can/6.000000);
        }
        else{
            this->piezas[i].x = this->piezas[i-1].y;
            this->piezas[i].y = 100.000000;
        }
    }
    */
    
    
    
    return dev;
}

void GenerarPiezas::Debug(){
    //COUT PARA DEBUG
    for(int i=0 ; i<7 ; i++){
        std::cout << "piezas[" << i << "]:" << std:: endl;
        std::cout << "  x: " << this->piezas[i].x << std::endl;
        std::cout << "  y: " << this->piezas[i].y << std::endl;
        std::cout << "  z: " << this->piezas[i].z << std::endl;           
    }
    std::cout << "/////////////////////////////////////////" << std::endl;
}

GenerarPiezas::~GenerarPiezas() {
}

