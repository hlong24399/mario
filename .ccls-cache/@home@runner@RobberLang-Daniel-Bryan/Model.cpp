#include "Model.h"
#include <iostream>
using namespace std;


Model::Model()
{
  letter = 't';
}

Model::~Model()
{
  letter = ' ';
}

string Model::translateSingleConsonant(char consonant)
{
  string robber_str = "";
  robber_str.push_back(consonant);
  robber_str.push_back('o');
  robber_str.push_back(consonant);
  // cout << robber_str << endl;
  return robber_str;
}

string Model::translateSingleVowel(char vowel)
{
  string robber_str = "";
  robber_str.push_back(vowel);
  return robber_str;
}