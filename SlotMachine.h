#pragma once

#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H

#include "Roll.h"

class SlotMachine :
    public Roll, public ResourceManager
{
private:
    double moneyPlundered = 0.0;
    double totalWinnings = 0.0;
    double money = 0.0;
    double cost = 0.10;
    bool running = true;
    bool rolling = false;
    double lastWin = 0.0;
    Text txtBalance;
    Text txtWinner;
    Text txtStart;
    Text txtStop;

    Sprite sprite;
    random_device seed;

    Roll roll1 = Roll(1, Vector2i(120, 20), seed(), true);
    Roll roll2 = Roll(2, Vector2i(220, 20), seed(), false);
    Roll roll3 = Roll(3, Vector2i(320, 20), seed(), true);

    void payRound() {
        moneyPlundered += cost;
        money -= cost;
    };

    bool checkBalance() {
        if (money > cost)
            return true;
        return false;
    };

    void checkWin() {
        
        lastWin = 0;

        if (compareItems(*roll1.getItem(3), *roll2.getItem(3), *roll3.getItem(3))) {
            lastWin += roll1.getPrizeAt(3);
        }
        else if (compareItems(*roll1.getItem(4), *roll2.getItem(4), *roll3.getItem(4))) {
            lastWin += roll1.getPrizeAt(4);
        }
        else if (compareItems(*roll1.getItem(5), *roll2.getItem(5), *roll3.getItem(5))) {
            lastWin += roll1.getPrizeAt(5);
        }
        else if (compareItems(*roll1.getItem(3), *roll2.getItem(4), *roll3.getItem(5))) {
            lastWin += roll1.getPrizeAt(3);
        }
        else if (compareItems(*roll1.getItem(5), *roll2.getItem(4), *roll3.getItem(3))) {
            lastWin += roll1.getPrizeAt(5);
        }

        addMoney(lastWin);
        totalWinnings += lastWin;
    }

    bool compareItems(RollItem r1, RollItem r2, RollItem r3) {
        return r1.getName() == r2.getName() && r2.getName() == r3.getName();
    }

public:

    SlotMachine(ResourceManager&);
    ~SlotMachine();

    void pushStart();
    void stopSpinning();
    virtual void drawer(RenderWindow*) override;
    double getMoney() { return money; };
    void eventsHandler(Event*, Vector2i);
    void addMoney(double money);
};

#endif