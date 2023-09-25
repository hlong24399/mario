#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include "Position.h"
#include <vector>
#include <iostream>
using namespace std;


class Environment
{
public:
  vector<vector<char>> grid;  
  int dimension;

public:

  Environment()
  {
    this->dimension = 7;
    this->setEnvironment(dimension);
  }
  Environment(int d)
  {
    this->dimension = d;
    for (int i = 0; i < d; i++)
      {
        for (int j = 0; j < d; i++)
          {
            grid[i].push_back('-');
          }
      }
  }

  void setEnvironment(int d)
  {
  this->dimension = d;
    for (int i = 0; i < d; i++)
      {
        for (int j = 0; j < d; i++)
          {
            grid[i].push_back('-');
          }
      }
  }

  void draw()
  {
    for (int i = 0; i < this->dimension; i++)
      {
        for (int j = 0; j < this->dimension; i++)
          {
            cout << grid[j][i] << " ";
          }
        cout << endl;
      }
  }

};

#endif