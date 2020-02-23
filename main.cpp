#include "DNA.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

  string dnaList = argv[1];
  DNA *dna = new DNA();
  dna->OpenFile(dnaList);

  cout << "The mean is: " << dna->calcMean() << endl;
  cout << "The Variance is: " << dna->calcVariance(dnaList) << endl;
  cout << "The Standard Deviation is: " << dna->calcStdev() << endl;

  delete dna;
  return 0;
}
