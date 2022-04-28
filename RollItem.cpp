#include "RollItem.h"

RollItem::RollItem(string name, Texture& texture) {
    this->name = name;
    sprite.setTexture(texture);
}

RollItem::RollItem(string name, float prize) {
    this->name = name;
    this->prize = prize;
}

RollItem::RollItem(string name) { this->name = name; }

void RollItem::setPosition(float x, float y) { sprite.setPosition(x, y); }

void RollItem::setTexture(Texture& text) { this->sprite.setTexture(text); }
