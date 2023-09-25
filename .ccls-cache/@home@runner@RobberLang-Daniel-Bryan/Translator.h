#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"

class Translator
{
public:
  Model m;

public:

  // Constructor
  Translator();

  // Destructor
  ~Translator();

  // check consonant or vowel
  bool isVowel(char letter);

  // translate word
  string translateEnglishWord(string word);

  // translate sentence
  string translateEnglishSentence(string sentence);
};

#endif