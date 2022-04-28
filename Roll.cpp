#include "Roll.h"

Roll::Roll(int rollNumber, Vector2i position, unsigned int seed, bool spinPolarity) {

    this->rollNumber = rollNumber;
    this->position = position;
    this->spinPolarity = spinPolarity;
    this->seed = seed;

    items.push_back(&lemon);
    items.push_back(&bell);
    items.push_back(&heart);
    items.push_back(&diamonds);
    items.push_back(&spades);
    items.push_back(&trefoil);
    items.push_back(&bag);
    items.push_back(&clubs);

    default_random_engine defRandEng = default_random_engine(seed);

    shuffle(items.begin(), items.end(), defRandEng);

    for (int i = 0; i < 8; i++)
    {
        float tempY = position.y;
        if (i > 0)
            tempY = position.y + (i * 90);

        items.at(i)->setPosition(position.x, tempY);
    }
}

void Roll::loadTextures(ResourceManager& resourceMGR) {
    lemon.setTexture(resourceMGR.getTexture("lemon"));
    heart.setTexture(resourceMGR.getTexture("heart"));
    diamonds.setTexture(resourceMGR.getTexture("diamonds"));
    spades.setTexture(resourceMGR.getTexture("spades"));
    bell.setTexture(resourceMGR.getTexture("bell"));
    trefoil.setTexture(resourceMGR.getTexture("trefoil"));
    bag.setTexture(resourceMGR.getTexture("bag"));
    clubs.setTexture(resourceMGR.getTexture("clubs"));
}

void Roll::spin(bool clockwise) {

    if (clockwise) {
        rotate(items.begin(), items.begin() + 1, items.end());
    }
    else {
        rotate(items.begin(), items.begin() + 7, items.end());
    }

    for (int i = 0; i < 8; ++i)
    {
        float tempY = position.y;
        if (i > 0)
            tempY = position.y + (i * 90);

        items.at(i)->setPosition(position.x, tempY);
    }
}

void Roll::roll() {
    
    rolling = true;
    rollCount = rand() % 700 + 700;
}

void Roll::stop() {
    rollCount = rand() % 500;
}

void Roll::drawRoll(RenderWindow* window, int begin, int end) {

    if (rolling) {
        if (rollCount < 1)
            rolling = false;

        if (rollCount % 20 == 0)
            spin(spinPolarity);

        --rollCount;
    }

    for (int i = begin; i < end; i++)
        items.at(i)->drawer(window);
}
