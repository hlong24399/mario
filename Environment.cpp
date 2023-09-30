
#include "Environment.h"
#include "Mario.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

Environment::Environment()
{
  setEnvironment(0);
  std::cout << "in env" << std::endl;
}

Environment::Environment(int d)
{
  setEnvironment(0);
}

// this one will be used when simulation runs.
Environment::Environment(int d, int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom, Mario &mario, bool is_pipe, ofstream & out)
{
  this->is_pipe = is_pipe;
  dimension = d;
  setEnvironment(d);
  populateGrid(chance_coin, chance_none, chance_goomba, chance_koopa, chance_mushroom, mario, out);
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

void Environment::populateGrid(int chance_coin, int chance_none, int chance_goomba, int chance_koopa, int chance_mushroom, Mario &mario, ofstream & out)
{

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
  cout << "mario: " << randColMario << " " << randRowMario << endl;
  grid[randRowMario][randColMario] = 'H'; // Mario
  

  // Set pos for mario
  mario.c = randColMario;
  mario.r = randRowMario;

  // Write to file mario's pos

  // Generate boss
  int randRowBoss, randColBoss;
  do
  {
    randRowBoss = rand() % dimension;
    randColBoss = rand() % dimension;
  } while (grid[randRowBoss][randColBoss] != '-');
  cout << "boss: " << randColBoss << " " << randRowBoss << endl;
  grid[randRowBoss][randColBoss] = 'b'; // Boss

  // Generate warp pipe
  int randRowPipe, randColPipe;
  do
  {
    randRowPipe = rand() % dimension;
    randColPipe = rand() % dimension;
  } while (grid[randRowPipe][randColPipe] != '-');
  if (is_pipe)
  {
    grid[randRowPipe][randColPipe] = 'w'; // Warp pipe
    cout << "pipe: " << randColPipe << " " << randRowPipe << endl;
  }
  else
  {
    grid[randRowPipe][randColPipe] = '-'; // Warp pipe
  }
}

void Environment::run(Mario &mario, ofstream & out)
{

  // Game Engine logic goes here
  while (mario.lives > 0 && !mario.finished && !mario.lost)
  {
    // cout << "here" << endl;
    if (mario.powerLevel < 0 && mario.lives > 0)
    {
      mario.lives -=1;
      mario.powerLevel = 0;
      move(mario, out);
    }
    else if (mario.powerLevel < 0 && mario.lives == 0)
    {
      mario.lost = true;
    }
    else
    {
      move(mario, out);
    }
    if (mario.lives <= 0 && mario.powerLevel < 0)
    {
      mario.lost = true;
    }
  }
}

void Environment::move(Mario &mario, ofstream & out)
{
  old_r = mario.r;
  old_c = mario.c;
  out << "mario's power level: " << mario.powerLevel << endl;

  bool moved = false;
  while (!moved)
  {
    int randMove = rand() % 4;
    if (randMove == 0 && mario.c < dimension - 1)
    {
      mario.c += 1;
      moved = true;
      out << "mario moved RIGHT! " << endl;
    }
    else if (randMove == 1 && mario.c > 0)
    {
      mario.c -= 1;
      moved = true;
      out << "mario moved LEFT! " << endl;
    }
    else if (randMove == 2 && mario.r < dimension - 1)
    {
      mario.r += 1;
      moved = true;
      out << "mario moved DOWN! " << endl;
    }
    else if (randMove == 3 && mario.r > 0)
    {
      mario.r -= 1;
      moved = true;
      out << "mario moved UP! " << endl;
    }
  }
  cout << "mario live: " << mario.lives << endl;

  update_mario(mario, out);
  update_map(mario, out);

  out << "mario coin: " << mario.coins << endl;
  out << "mario live: " << mario.lives << endl;
}

void Environment::update_mario(Mario &mario, ofstream & out)
{
  if (mario.r < 0 || mario.r >= dimension || mario.c < 0 || mario.c >= dimension)
  {
    // do nothing
  }
  else if (grid[mario.r][mario.c] == 'c')
  {
    mario.collectCoin();
    out << "mario collected a coin! " << endl;
  }
  else if (grid[mario.r][mario.c] == 'm')
  {
    mario.eatMushroom();
    out << "mario ate a mushroom! " << endl;
  }
  else if (grid[mario.r][mario.c] == 'g')
  {
    int random = rand() % 10;
    if (random < 2)
    {
      out << "mario lost a Goomba! " << endl;
      mario.powerLevel -= 1;
      if (mario.powerLevel < 0)
      {
        mario.lives -= 1;
      }
    }
    else
    {
      out << "mario killed a Goomba! " << endl;
    }
  }
  else if (grid[mario.r][mario.c] == 'k')
  {
    int random = rand() % 100;
    if (random < 35)
    {
      out << "mario lost a Koopa Troopa! " << endl;
      mario.powerLevel -= 1;
      if (mario.powerLevel < 0)
      {
        mario.lives -= 1;
      }
    }
    else
    {
      out << "mario killed a Koopa Troopa! " << endl;
    }
  }
  else if (grid[mario.r][mario.c] == 'b')
  {
    while (mario.lives > 0)
    {
      int random = rand() % 100;
      if (random < 50)
      {
        out << "mario lost a boss! " << endl;
        if (mario.powerLevel >= 2)
        {
          mario.powerLevel -=2;
        }
        else if (mario.powerLevel < 2 && mario.lives > 0)
        {
          cout << "lose boss, try again" << endl;
          mario.lives -= 1;
        }
        else
        {
          // mario loses the game
          out << "mario lost the game! " << endl;
          mario.lost = true;
          break;
        }
      }
      else
      {
        out << "mario killed a boss! " << endl;
        // go to next level
        mario.finished = true;
        break;
      }
    }

  }
  else if (grid[mario.r][mario.c] == 'w')
  {
    out << "mario warped to new level! " << endl;
    mario.finished = true;
  }
  else
  {
    // do nothing
    out << "mario moved to a new position! " << endl;
  }
}
void Environment::update_map(Mario &mario, ofstream & out)
{
  // update the map
  // if mario is at the edge, he will not move to that direction
  grid[old_r][old_c] = '-'; // old pos
  for (int i = 0; i < dimension; i++)
  {
    for (int j = 0; j < dimension; j++)
    {
      if (grid[i][j] == 'H')
      {
        grid[i][j] = '-';
      }
    }
  }
  grid[mario.r][mario.c] = 'H';
  
  draw(out);

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

void Environment::draw(ofstream & out)
{
  // Draw the presentation of the game
  for (int i = 0; i < dimension; i++)
  {
    for (int j = 0; j < dimension; j++)
    {
      out << grid[i][j] << " ";
    }
    out << endl;
  }
  out << "\n" << endl;
}
