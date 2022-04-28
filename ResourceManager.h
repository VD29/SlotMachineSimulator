#pragma once

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iterator>
#include <cmath>
#include <chrono>
#include <time.h>

using namespace std;
using namespace sf;

class ResourceManager
{
private:
    map<string, Texture> textures;
    map<string, Font> fonts;

public:
    ResourceManager() { }
    ~ResourceManager() { }

    void loadTexture(string name, string textureFile);
    Texture& getTexture(string name);

    void loadFont(string name, string fontFile);
    Font& getFont(string name);

};

#endif
