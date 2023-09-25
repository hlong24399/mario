#include <iostream>
#include "Simulation.h"
#include "Environment.h"
#include "Mario.h"
#include <vector>
using namespace std;

int main() {
  cout << "hello world" << endl;
  // Simulation::Simulation(int level, int dimension, int init_live, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom)
  Simulation s(4, 6, 3, 10, 10, 10, 10, 10);
  s.simulate();
  return 0;
}