#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include "Mario.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Environment
{
public:
  char grid[100][100];
  int dimension;
  int old_r, old_c;
  bool is_pipe;
  bool finished = false;


public:

  Environment();
  Environment(int d);
  Environment(int d, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom, Mario & mario, bool is_pipe, ofstream & out);
  void setEnvironment(int d);
  void populateGrid(int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom, Mario & mario,  ofstream & out);
  void run(Mario & mario,  ofstream & out);
  void move(Mario & mario,  ofstream & out);
  void update_mario(Mario & mario,  ofstream & out);
  void update_map(Mario & mario,  ofstream & out);
  void draw(ofstream & out);
  
};

#endif