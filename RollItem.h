#pragma once

#ifndef REEL_ITEM_H
#define REEL_ITEM_H

#include "ResourceManager.h"

class RollItem :
    public ResourceManager
{
private:
    Sprite sprite;
    string name;
    float prize;

public:
 
    RollItem() {};
    RollItem(string, Texture&);
    RollItem(string, float);
    RollItem(string);

    virtual void drawer(RenderWindow* window) { window->draw(sprite); }

    Vector2f getPosition() { return sprite.getPosition(); }
    float getPrize() { return prize; }
    string getName() { return name; }

    void setPosition(float, float);
    void setTexture(Texture&);

};

#endif

