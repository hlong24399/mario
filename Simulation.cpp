#include "Simulation.h"

Simulation::Simulation()
{
    env = Environment(0);
    env.draw();
    std::cout << "in simu" << std::endl;
}

// We use this mainly, to populate all chance and stuff
Simulation::Simulation(int level, int dimension, int init_live, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom)
{
    // set up the simulator
    this->level = level;
    this->dimension = dimension;
    this->live = init_live;
    this->chance_coin = chance_coin;
    this->chance_none = chance_none;
    this->chance_goomba = chance_goomba;
    this->chance_koopa = chance_koopa;
    this->chance_mushroom = chance_mushroom;


    this->mario = Mario(init_live);

    this->generateLevel();
}

void Simulation::generateLevel()
{
    for (int i = 0; i < level; i++)
    {
        Environment env(dimension, chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom);
        envs.push_back(env);
        // env.draw();
        // cout << endl;
    }
}

void Simulation::simulate()
{
    for (int i = 0; i < level; i++)
    {
        // envs[i].draw();
        // cout << endl;
        envs[i].run(mario);
        // envs[i].draw();
        // cout << endl;
    }
}
