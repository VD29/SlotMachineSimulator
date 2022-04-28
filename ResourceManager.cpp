#include "ResourceManager.h"

void ResourceManager::loadTexture(string name, string textureFile) {

    Texture tempTexture;

    if (tempTexture.loadFromFile(textureFile))
        this->textures[name] = tempTexture;
}

Texture& ResourceManager::getTexture(string name) { return this->textures.at(name); }

void ResourceManager::loadFont(string name, string fontFile) {

    Font tempFont;

    if (tempFont.loadFromFile(fontFile))
        this->fonts[name] = tempFont;
}

Font& ResourceManager::getFont(string name) { return this->fonts.at(name); }