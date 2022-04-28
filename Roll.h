#pragma once

#ifndef ROLL_H
#define ROLL_H

#include "RollItem.h"

class Roll :
    public RollItem
{
private:
    int rollNumber;
    bool rolling = false;
    int rollCount = 0;
    bool spinPolarity = false;

    Vector2i position;
    vector<RollItem*> items;
    unsigned int seed = 0;

    RollItem lemon = RollItem("lemon", 0.10);
    RollItem heart = RollItem("heart", 0.50);
    RollItem diamonds = RollItem("diamonds", 1);
    RollItem spades = RollItem("spades", 1.50);
    RollItem trefoil = RollItem("trefoil", 10);
    RollItem bell = RollItem("bell", 5);
    RollItem bag = RollItem("bag", 50);
    RollItem clubs = RollItem("clubs", 2);

public:
   
    Roll() {}
    Roll(int, Vector2i, unsigned int, bool);

    void loadTextures(ResourceManager&);
    void drawRoll(RenderWindow*, int, int);
    void spin(bool);
    void roll();
    void stop();

    vector<RollItem*> getItems() { return items; }
    RollItem* getItem(int rollSlot) { return items.at(rollSlot); }
    float getPrizeAt(int pos) { return items.at(pos)->getPrize(); }
    bool isRolling() { return rolling; }
};

#endif