#ifndef FILEPROCESSOR_h
#define FILEPROCESSOR_h

#include "Translator.h"

class FileProcessor
{
  public:
    Translator t;

  public:
    // Constructor
    FileProcessor();

    // Destructor
    ~FileProcessor();

    // processFile
    void processFile(string input, string output);
};


#endif