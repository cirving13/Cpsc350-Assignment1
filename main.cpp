#include "DNA.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  string dnaList;
  if(argv[1]!=NULL)
    dnaList = argv[1];
  DNA *dna = new DNA();
  dna->writeHeader();
  bool x = true; //used for while loop
  char y;

  if (dnaList!="") //runs analysis if dnaList has a file as input
  {
    dna->resetVariables();
    dna->OpenFile(dnaList);
    dna->writeFile(dnaList);
    dna->generateDNA();
  }
  else
  {
    cout << "Please enter a valid file to be computed: " << endl;
    cin >> dnaList;
    dna->resetVariables();
    dna->OpenFile(dnaList);
    dna->writeFile(dnaList);
    dna->generateDNA();
  }
  while (x) //loops through asking for a file to be computed and
  {
    cout << "Would you like to compute a file? y for yes, anything else to quit: " << endl;
    cin >> y;
    if (y == 'y')
    {
      cout << "Enter a file name: " << endl;
      cin >> dnaList;
      dna->resetVariables();
      dna->OpenFile(dnaList);
      dna->writeFile(dnaList);
      dna->generateDNA();
    }
    else
      x = false; //breaks while loop if someone quits
  }
  delete dna;
  return 0;
}
