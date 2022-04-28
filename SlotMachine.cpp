#include "SlotMachine.h"

SlotMachine::SlotMachine(ResourceManager& rManager) {
   
    addMoney(10.0);

    txtBalance.setFont(rManager.getFont("arial"));
    txtBalance.setCharacterSize(17);
    txtBalance.setPosition(200, 225);
    txtBalance.setFillColor(Color::White);

    txtStart.setFont(rManager.getFont("arial"));
    txtStart.setCharacterSize(16);
    txtStart.setPosition(490, 225);
    txtStart.setString(" ");
    txtStart.setFillColor(Color::White);

    txtStop.setFont(rManager.getFont("arial"));
    txtStop.setCharacterSize(16);
    txtStop.setPosition(490, 350);
    txtStop.setString(" ");
    txtStop.setFillColor(Color::White);

    txtWinner.setFont(rManager.getFont("Cowboys"));
    txtWinner.setCharacterSize(20);
    txtWinner.setPosition(155, 190);
    txtWinner.setFillColor(Color::White);

    roll1.loadTextures(rManager);
    roll2.loadTextures(rManager);
    roll3.loadTextures(rManager);
    sprite.setTexture(rManager.getTexture("chassis"));
};

SlotMachine::~SlotMachine() {};

void SlotMachine::addMoney(double money) {
    this->money += money;
}

void SlotMachine::stopSpinning() {
    roll1.stop();
    roll2.stop();
    roll3.stop();
}

void SlotMachine::pushStart() {

    if (rolling) { return; }

    if (!checkBalance()) { return; }

    payRound();
    
    rolling = true;
    roll1.roll();
    roll2.roll();
    roll3.roll();
}


void SlotMachine::drawer(RenderWindow* window) {
    
    window->draw(sprite);

    roll1.drawRoll(window, 3, 6);
    roll2.drawRoll(window, 3, 6);
    roll3.drawRoll(window, 3, 6);

    string tempStr = "Balance: $";
    tempStr += to_string(money);
    string rounded = tempStr.substr(0, tempStr.find(".") + 3);
    txtBalance.setString(rounded);

    if (lastWin >= 0.10) {
        if (lastWin == 20) {
            txtWinner.setString("$$$ JACKPOT $$$");
        }
        else {
            txtWinner.setString("  !!! YOU WIN !!!  ");
        }
        window->draw(txtWinner);
        
    }

    window->draw(txtBalance);
    window->draw(txtStart);
    window->draw(txtStop);

    if (!roll1.isRolling() && !roll2.isRolling() && !roll3.isRolling()) {
        if (rolling) {
            checkWin();
        }
        rolling = false;
    }
}

void SlotMachine::eventsHandler(Event* event, Vector2i mouse) {

    if (event->type == Event::MouseButtonPressed) {

        Vector2i startButton(505, 230);
        Vector2i startButtonDif = startButton - mouse;

        float dist = sqrt(pow(startButtonDif.x, 2) + pow(startButtonDif.y, 2));

        if (dist < 40) {
            pushStart();
        }

    }

    if (event->type == Event::MouseButtonPressed) {

        Vector2i stopButton(505, 355);
        Vector2i stopButtonDif = stopButton - mouse;

        float dist = sqrt(pow(stopButtonDif.x, 2) + pow(stopButtonDif.y, 2));

        if (dist < 40) {
            stopSpinning();
        }

    }

}