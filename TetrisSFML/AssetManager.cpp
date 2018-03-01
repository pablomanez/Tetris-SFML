/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetManager.cpp
 * Author: pablomanez
 * 
 * Created on 1 de marzo de 2018, 13:25
 */

#include "AssetManager.h"
#include <assert.h>
#include <iostream>

AssetManager* AssetManager::sInstance = NULL;

/*
AssetManager::AssetManager() {
    
    assert(sInstance == nullptr);
    sInstance = this;
}
*/

//getting the instance
AssetManager * AssetManager::instance()
{
    //create new instance of return existing one
    if (sInstance == NULL) {
            sInstance = new AssetManager();
    }
    return sInstance;
}

sf::Texture *AssetManager::getTexture(const std::string &filename) {
    //reference to our map
    std::map<std::string, sf::Texture> &textureMap = sInstance->textures;

    //search for entry
    auto pairFound = textureMap.find(filename);
    if (pairFound != textureMap.end())
            //return existing texture pointer
            return &(pairFound->second);
    else {
            //create texture
            sf::Texture &texture = textureMap[filename];

            if (!texture.loadFromFile(filename)) {
                    system("pause");
            }
            return &texture;
    }
}

/*
sf::Texture& AssetManager::GetTexture(std::string const& filename) {
    auto& texMap = sInstance->m_Textures;
    
        std::cout << filename << std::endl;
        
    
    auto pairFound = texMap.find(filename);
    
    if(pairFound != texMap.end()){
        
        return pairFound->second;
        
    }
    else{
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
    
    
    
    
}
*/
