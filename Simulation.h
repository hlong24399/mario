#ifndef SIMULATION_H
#define SIMULATION_H

#include "Environment.h"
#include "Logger.h"
#include "Mario.h"
#include <iostream>
#include <vector>

class Simulation
{
public:
  Mario mario;
  Environment env;
  Logger logger;
  int level;
  int live;
  vector<Environment> envs;
  int dimension, chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom;

  

public:
  Simulation();
  Simulation(int level, int dimension, int init_live, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom);
  void generateLevel();
  void simulate();
};

#endif