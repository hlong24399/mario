#include "Mario.h"

Mario::Mario()
{
}

Mario::Mario(int startingLives)
{
    lives = startingLives;
    coins = 0;
}

void Mario::collectCoin()
{
    coins++;
    if (coins % 20 == 0)
    {
        lives++;
        coins = 0;
    }
}

void Mario::eatMushroom()
{
    if (powerLevel < 2)
    {
        powerLevel++;
    }

}  
