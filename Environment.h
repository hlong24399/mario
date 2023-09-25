#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include "Mario.h"
#include <vector>
#include <iostream>
using namespace std;


class Environment
{
public:
  // vector<vector<char>> grid;  
  char grid[100][100];
  int dimension;

public:

  Environment();
  Environment(int d);
  Environment(int d, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom);
  void setEnvironment(int d);
  void populateGrid(int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom);
  void run(Mario mario);
  void draw();
  
};

#endif