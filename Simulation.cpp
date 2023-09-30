#include "Simulation.h"

Simulation::Simulation()
{
    env = Environment(0);
    std::cout << "in simu" << std::endl;
}

// We use this mainly, to populate all chance and stuff
Simulation::Simulation(int level, int dimension, int init_live, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom)
{
    // set up the simulator
    this->level = level + 1;
    this->dimension = dimension;
    this->live = init_live;
    this->chance_coin = chance_coin;
    this->chance_none = chance_none;
    this->chance_goomba = chance_goomba;
    this->chance_koopa = chance_koopa;
    this->chance_mushroom = chance_mushroom;

    outfile.open("output.txt");

    this->mario = Mario(init_live);
}

void Simulation::play()
{
    // create the environment
   for (int i = 0; i < level; i++)
    {
        if (level - i == 1)
        {
            envs[i] = Environment(dimension, chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom, mario, false, outfile);
        }
        else
        {
            envs[i] = Environment(dimension, chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom, mario, true, outfile);
        }
        cout << "before run" << endl;
    }

    // run the environment
    for (int i = 0; i < level; i++)
    {
        outfile << "start level: " << i + 1 << endl;
        envs[i].run(mario, outfile);
        mario.finished = false;

        // check if mario is dead
        if (mario.lost)
        {
            outfile << "MARIO LOST" << endl;
            break;
        }
        outfile << "finished level " << i << endl;
    }

    if (!mario.lost)
    {
        outfile << "MARIO WINS" << endl;
    }
    outfile.close();
}
