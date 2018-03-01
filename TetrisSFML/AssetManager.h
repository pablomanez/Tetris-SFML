/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetManager.h
 * Author: pablomanez
 *
 * Created on 1 de marzo de 2018, 13:25
 */

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager {
public:
    //instance getter
    static AssetManager *instance();

    //resource getters
    sf::Texture *getTexture(const std::string &filename);

private:
    //constructor should be private
    AssetManager() {}

    //static instance
    static AssetManager* sInstance;

    //map
    std::map<std::string, sf::Texture> textures;

};

#endif /* ASSETMANAGER_H */

