#ifndef SIMULATION_H
#define SIMULATION_H

#include "Environment.h"
#include "Mario.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Simulation
{
public:
  Mario mario;
  Environment env;
  int level;
  int live;
  Environment envs [100];
  int dimension, chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom;
  ofstream outfile;

  

public:
  Simulation();
  Simulation(int level, int dimension, int init_live, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom);
  void play();
};

#endif