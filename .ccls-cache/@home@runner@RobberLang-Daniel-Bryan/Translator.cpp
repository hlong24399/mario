#include "Translator.h"
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


Translator::Translator()
{
}

Translator::~Translator()
{ 
}

bool Translator::isVowel(char letter)
{
  if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
                letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
    {
      return false;
    }
  return true;
}


string Translator::translateEnglishWord(string word)
{
  string result = "";
  for (int i = 0; i < word.size(); i++)
    {
      // check if it is a vowel or not, then call the appropriate function from the model
      // cout << result << endl;
      if (!isVowel(word[i]))
      {
        string temp = m.translateSingleVowel(word[i]);
        // cout << "in here" << temp << endl;
        result += temp;
      }
      else
      {
        string temp = m.translateSingleConsonant(word[i]);
        // cout << "consonatn now" << temp << endl;
        result += temp;
      }
      
    }
  cout << "the word is : " << result<< endl;
  return result;
}

string Translator::translateEnglishSentence(string s)
{
  vector<std::string> tokens;
  string token;
  string result;
  for (char ch : s) {
      if (ch == ' ') {
          if (!token.empty()) {
              tokens.push_back(token);
              token.clear();
          }
      } else {
          token += ch;
      }
  }

  if (!token.empty()) {
      tokens.push_back(token);
  }
  for (int i = 0; i < tokens.size(); i++)
    {
      string temp = this->translateEnglishWord(tokens[i]);
      result += temp;
      result += " ";
    }
  // return tokens;
  return result;
}
