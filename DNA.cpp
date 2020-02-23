#include "DNA.h"
#include <fstream>
#include <cmath>

DNA::DNA()
{

}
DNA::~DNA()
{
  cout << "the object has been deleted" << endl;
}
void DNA::OpenFile(string input)
{
  ifstream inFile;
  inFile.open(input);
  char c;

  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1); //Exits program, need to make into a loop
  }
  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
      char strInput = tolower(c);
      if(strInput == 'a')
      {
        ++ACount;
        ++Total;
      }
      else if(strInput == 'c')
      {
        ++CCount;
        ++Total;
      }
      else if(strInput == 'g')
      {
        ++GCount;
        ++Total;
      }
      else if(strInput == 't')
      {
        ++TCount;
        ++Total;
      }
      else if(strInput == '\n')
        ++LineCount;
  }
  Mean = Total/LineCount;
  inFile.close();
}
// int DNA::countBigram(string input)
// {
//
// }
float DNA::calcMean()
{
  Mean = Total/LineCount;
  return Mean;
}
float DNA::calcVariance(string input)
{
  ifstream inFile;
  inFile.open(input);
  char c;

  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1); //Exits program, need to make into a loop
  }
  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
      char strInput = tolower(c);
      if(strInput == 'a')
        ++LineCharCount;
      else if(strInput == 'c')
        ++LineCharCount;
      else if(strInput == 'g')
        ++LineCharCount;
      else if(strInput == 't')
        ++LineCharCount;
      else if(strInput == '\n')
      {
        Variance += pow((LineCharCount-Mean),2);
        LineCharCount = 0;
      }
  }

  inFile.close();
  Variance -= pow(Mean,2); //The way i calculate Variance does not work with the way i read the file because it adds an extra Mean^2, this fixes it
  Variance = Variance/LineCount;
  return Variance;
}
float DNA::calcStdev()
{
  Stdev = sqrt(Variance);
  return Stdev;
}
