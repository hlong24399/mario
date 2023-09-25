#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include "Environment.h"

class Mario {
public:
    int lives;
    int coins;
    int powerLevel;
    int level;
    int r;
    int c;

public:
    Mario(int startingLives);

    // // Getter methods for Mario's attributes
    // int getLives() const;
    // int getCoins() const;
    // int getPowerLevel() const;
    // int getLevel() const;
    // int getRow() const;
    // int getCol() const;

    // Methods to handle Mario's interactions
    void collectCoin();
    void eatMushroom();
    // bool fightEnemy(Level& currentLevel);
    // bool fightBoss(Level& currentLevel);
    // void warpToNextLevel();


};

#endif