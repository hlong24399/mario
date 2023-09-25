#ifndef MODEL_H
#define MODEL_H

// needed library
#include <string>

// boilerplate
using namespace std;

class Model
{
public:
  char letter;

public:
  // Constructor
  Model();

  // Destructor
  ~Model();

  // convert single consonant
  string translateSingleConsonant(char consonant);

  // convert single vowel
  string translateSingleVowel(char vowel);
};

#endif