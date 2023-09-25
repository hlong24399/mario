
#include "Environment.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
using namespace std;

Environment::Environment()
{
  this->setEnvironment(0);
  std::cout << "in env" << std::endl;
}

Environment::Environment(int d)
{
  this->setEnvironment(0);
}

// this one will be used when simulation runs.
Environment::Environment(int d, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom)
{
  dimension = d;
  this->setEnvironment(d);
  this->populateGrid(chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom);
  // this->draw();
  // // generate random items
  /*
● x - nothing
● m - a mushroom
● c - a coin
● g - a Goomba
● k - a Koopa Troopa
● b - the level boss
● w - a warp pipe
● H - stands for hero. Mario’s current position.
*/
}

void Environment::populateGrid(int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom)
{
  srand(time(0));
  for (int i = 0; i < dimension; i++)
  {
    for (int j = 0; j < dimension; j++)
    {
      int random = rand() % 100;
      if (random < chance_coin)
      {
        grid[i][j] = 'c';
      }
      else if (random < chance_coin + chance_goomba)
      {
        grid[i][j] = 'g';
      }
      else if (random < chance_coin + chance_goomba + chance_koopa)
      {
        grid[i][j] = 'k';
      }
      else if (random < chance_coin + chance_goomba + chance_koopa + chance_mushroom)
      {
        grid[i][j] = 'm';
      }
      else
      {
        // Handle the case where none of the conditions are met
        grid[i][j] = '-'; // or any default character you want
      }
    }
  }

  // Generate Mario
  int randRowMario, randColMario;
  do
  {
    randRowMario = rand() % dimension;
    randColMario = rand() % dimension;
  } while (grid[randRowMario][randColMario] != '-');
  // cout << randColMario << " " << randRowMario << endl;
  grid[randRowMario][randColMario] = 'H'; // Mario

  // Generate boss
  int randRowBoss, randColBoss;
  do
  {
    randRowBoss = rand() % dimension;
    randColBoss = rand() % dimension;
  } while (grid[randRowBoss][randColBoss] != '-' && grid[randRowBoss][randColBoss] != 'H');
  // cout << randColBoss << " " << randRowBoss << endl;
  grid[randRowBoss][randColBoss] = 'b'; // boss

  // Generate warp pipe
  int randRowPipe, randColPipe;
  do
  {
    randRowPipe = rand() % dimension;
    randColPipe = rand() % dimension;
  } while (grid[randRowPipe][randColPipe] != '-' && grid[randRowPipe][randColPipe] != 'H' && grid[randRowPipe][randColPipe] != 'b');
  grid[randRowPipe][randColPipe] = 'w'; // warp pipe
}

void Environment::run(Mario mario)
{
  this->draw();
  // mario will move in the grid with 25% chance of up down left right
  // if mario is at the edge, he will not move to that direction
  for (int i = 0; i < )
}

void Environment::setEnvironment(int d)
{
  dimension = d;
  for (int i = 0; i < d; i++)
  {
    for (int j = 0; j < d; j++)
    {
      grid[i][j] = '-';
    }
  }
}


void Environment::draw()
{
  // grid[1][3] = 'm';

  for (int i = 0; i < this->dimension; i++)
  {
    for (int j = 0; j < this->dimension; j++)
    {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
