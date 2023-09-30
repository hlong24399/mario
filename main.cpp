#include <iostream>
#include "Simulation.h"
#include "Environment.h"
#include "Mario.h"
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
  cout << "hello world" << endl;
  srand(time(NULL));

  int param1, param2, param3, param4, param5, param6, param7, param8;

  // Open the file for reading
  std::ifstream inputFile("input.txt");

  // Check if the file is open
  if (!inputFile.is_open())
  {
    std::cerr << "Error: Could not open the file." << std::endl;
    return 1; // Exit with an error code
  }

  // Read parameters from the file, one per line
  inputFile >> param1 >> param2 >> param3 >> param4 >> param5 >> param6 >> param7 >> param8;

  // Close the file
  inputFile.close();

  // Create an instance of the Simulation class using the extracted parameters
  Simulation s(param1, param2, param3, param4, param5, param6, param7, param8);

  s.play();
  cout << "fnished game" << endl;
  return 0;
}