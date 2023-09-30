#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <fstream>
using namespace std;

class Mario {
public:
    int lives;
    int coins;
    int powerLevel = 0;
    int level;
    int r;
    int c;
    bool finished = false;
    bool lost = false;

public:
    Mario();
    Mario(int startingLives);

    // // Getter methods for Mario's attributes
    int getLives();
    int getCoins();
    int getPowerLevel();
    int getLevel();
    int getRow();
    int getCol();

    // Methods to handle Mario's interactions
    void collectCoin();
    void eatMushroom();
    // bool fightEnemy(Level& currentLevel);
    // bool fightBoss(Level& currentLevel);
    // void warpToNextLevel();


};

#endif