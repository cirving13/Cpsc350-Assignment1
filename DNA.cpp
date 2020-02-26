#include "DNA.h"

DNA::DNA() //default constructor
{

}
DNA::~DNA() //destructor
{
  cout << "Closing :)" << endl;
}
void DNA::OpenFile(string input) //opens and reads a file, finding basic information about the file
{
  ifstream inFile;
  inFile.open(input);
  char c;

  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
      char strInput = tolower(c);
      char strPrev;
      if(strInput == 'a' || strInput == 'c' || strInput == 'g' || strInput == 't' || strInput == '\n') //checks for a nucleotide or endline, ignores other characters
      {
        if(strInput == 'a')
        {
          ++ACount; //increments number of A nucleotides
          ++CharCount; //Used for finding bigrams
          ++Total; //increments total amount of nucleotides in file
        }
        else if(strInput == 'c')
        {
          ++CCount;
          ++CharCount;
          ++Total;
        }
        else if(strInput == 'g')
        {
          ++GCount;
          ++CharCount;
          ++Total;
        }
        else if(strInput == 't')
        {
          ++TCount;
          ++CharCount;
          ++Total;
        }
        else if(strInput == '\n')
        {
          ++LineCount;
          CharCount = 0;
          s = "";
        }
        if (CharCount % 2 == 1) //finds bigram of nucleotide and the one before it with no overlap
        {
          strPrev = strInput;
        }
        else if (CharCount != 0 && (strInput == 'a' || strInput == 'c' || strInput == 'g' || strInput == 't')) //Filters out non nucleotides in string
        {
          s.append(1,strPrev); //appends bigram to string s
          s.append(1,strInput);
          calcBigram(s);
          s = "";
          ++BigramCount; //used for calculating bigram probability
        }
      }
    }
  Mean = Total/LineCount;
  inFile.close();
}
float DNA::calcMean() //calculates mean
{
  Mean = Total/LineCount;
  return Mean;
}
float DNA::calcVariance(string input) //calculates Variance by running through file again
{
  ifstream inFile;
  inFile.open(input);
  char c;

  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
      char strInput = tolower(c); //calculates the length of each line
      if(strInput == 'a')
        ++LineCharCount;
      else if(strInput == 'c')
        ++LineCharCount;
      else if(strInput == 'g')
        ++LineCharCount;
      else if(strInput == 't')
        ++LineCharCount;
      else if(strInput == '\n') //shows the end of the line
      {
        Variance += pow((LineCharCount-Mean),2); //subtracts the actual length from the calculated average length and squares it
        LineCharCount = 0; //resets the line length to 0 to start again on the next line
      }
  }

  inFile.close();
  Variance -= pow(Mean,2); //The way i calculate Variance does not work with the way i read the file because it adds an extra Mean^2, this fixes it
  Variance = Variance/LineCount;
  return Variance;
}
float DNA::calcStdev() //calculates Standard Deviation
{
  Stdev = sqrt(Variance);
  return Stdev;
}
void DNA::calcBigram(string input) //counts the bigrams and keeps track of the numbers
{
  if(input == "aa")
    ++AACount;
  else if(input == "ac")
    ++ACCount;
  else if(input == "ag")
    ++AGCount;
  else if(input == "at")
    ++ATCount;
  else if(input == "ca")
    ++CACount;
  else if(input == "cc")
    ++CCCount;
  else if(input == "cg")
    ++CGCount;
  else if(input == "ct")
    ++CTCount;
  else if(input == "ga")
    ++GACount;
  else if(input == "gc")
    ++GCCount;
  else if(input == "gg")
    ++GGCount;
  else if(input == "gt")
    ++GTCount;
  else if(input == "ta")
    ++TACount;
  else if(input == "tc")
    ++TCCount;
  else if(input == "tg")
    ++TGCount;
  else if(input == "tt")
    ++TTCount;
}
float DNA::calcProb(float count) //calculates probability of single nucleotides
{
  float prob = count/Total;
  return prob;
}
float DNA::calcProbBigram(float count) //calculates probability of bigrams
{
  float prob = count/BigramCount;
  return prob;
}
void DNA::writeFile(string input) //writes the information to cirving.out file
{
  ofstream outFile;
  outFile.open("cirving.out", ios::app);
  outFile << "For the file: " << input << endl;
  outFile << endl;
  outFile << "The Sum of the length of the DNA strings is: " << Total << endl;
  outFile << "The Mean of the length of the DNA strings is: " << calcMean() << endl;
  outFile << "The Variance of the length of the DNA strings is: " << calcVariance(input) << endl;
  outFile << "The Standard Deviation of the length of the DNA strings is: " << calcStdev() << endl;
  outFile << endl;
  outFile << "The probabilities of nucleotides are listed below" << endl;
  outFile << "A: " << calcProb(ACount) << endl; //calculates the probabilities for each nucleotide
  outFile << "C: " << calcProb(CCount) << endl;
  outFile << "G: " << calcProb(GCount) << endl;
  outFile << "T: " << calcProb(TCount) << endl;
  outFile << "The probabilities of bigrams are listed below" << endl;
  outFile << "AA: " << calcProbBigram(AACount) << endl; //calculates the bigram probabilities for each bigram
  outFile << "AC: " << calcProbBigram(ACCount) << endl;
  outFile << "AG: " << calcProbBigram(AGCount) << endl;
  outFile << "AT: " << calcProbBigram(ATCount) << endl;
  outFile << "CA: " << calcProbBigram(CACount) << endl;
  outFile << "CC: " << calcProbBigram(CCCount) << endl;
  outFile << "CG: " << calcProbBigram(CGCount) << endl;
  outFile << "CT: " << calcProbBigram(CTCount) << endl;
  outFile << "GA: " << calcProbBigram(GACount) << endl;
  outFile << "GC: " << calcProbBigram(GCCount) << endl;
  outFile << "GG: " << calcProbBigram(GGCount) << endl;
  outFile << "GT: " << calcProbBigram(GTCount) << endl;
  outFile << "TA: " << calcProbBigram(TACount) << endl;
  outFile << "TC: " << calcProbBigram(TCCount) << endl;
  outFile << "TG: " << calcProbBigram(TGCount) << endl;
  outFile << "TT: " << calcProbBigram(TTCount) << endl;
  outFile << "A list of 1000 randomly generated strings is below" << endl;
  outFile << endl;
}
void DNA::writeHeader() //writes the header
{
  ofstream outFile;
  outFile.open("cirving.out", ios::app);
  outFile << "Cameron Irving" << endl;
  outFile << "ID: 2326756" << endl;
  outFile << endl;
}
void DNA::resetVariables() //sets all variables to 0 before reading files
{
  ACount = 0;
  CCount = 0;
  GCount = 0;
  TCount = 0;
  Total = 0;
  LineCount = -1.0;
  LineCharCount = 0;
  CharCount = 0;
  Mean = 0;
  Stdev = 0;
  Variance = 0;
  BigramCount = 0;
  AACount = 0;
  ACCount = 0;
  AGCount = 0;
  ATCount = 0;
  CACount = 0;
  CCCount = 0;
  CGCount = 0;
  CTCount = 0;
  GACount = 0;
  GCCount = 0;
  GGCount = 0;
  GTCount = 0;
  TACount = 0;
  TCCount = 0;
  TGCount = 0;
  TTCount = 0;
  s = "";
  rLength = 0;
  rValue1 = 0;
  rValue2 = 0;
  gaussDist = 0;
}
float DNA::gaussianDist() //generates length of strings to be output
{
  rValue1 = ((float) rand() / RAND_MAX);
  rValue2 = ((float) rand() / RAND_MAX);
  gaussDist = sqrt(-2*log(rValue1))*cos(2*M_PI*rValue2);
  rLength = Stdev*gaussDist + Mean;
  return rLength;
}
void DNA::generateDNA() //generates the dna using probabilities calculated
{
  ofstream outFile;
  outFile.open("cirving.out", ios::app);
  float a = calcProb(ACount);
  float c = a + calcProb(CCount);
  float g = c + calcProb(GCount);
  string output;
  string inner;
  for (int i = 0; i <= 1000; ++i) //loops 1000 times
  {
    rLength = gaussianDist();
    for (int k = 0; k <= (int)rLength; ++k) //calculates random number and chooses a nucleotide, then appends it to file
    {
      float r = ((float) rand() / RAND_MAX);
      if (0 <= r <= a)
        outFile << "A";
      else if (a < r <= c)
        outFile << "C";
      else if (c < r <= g)
        outFile << "G";
      else if (g < r <= 1)
        outFile << "T";
    }
    outFile << endl;
  }
}
