#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class DNA
{
  //variables
  private:
    float ACount; //counts of nucleotides
    float CCount;
    float GCount;
    float TCount;
    float Total; //total number of nucleotides
    float LineCount = -1.0; //number of lines, set to -1 because textfiles have an empty line at the end
    float LineCharCount;
    int CharCount;
    float Mean;
    float Stdev;
    float Variance;
    float BigramCount; //total number of bigrams
    float AACount; //count of bigrams
    float ACCount;
    float AGCount;
    float ATCount;
    float CACount;
    float CCCount;
    float CGCount;
    float CTCount;
    float GACount;
    float GCCount;
    float GGCount;
    float GTCount;
    float TACount;
    float TCCount;
    float TGCount;
    float TTCount;
    string s; //used for calculating bigrams
    float rLength; //length of lines output onto file
    float rValue1; //random values used to calculate gauss Dist
    float rValue2;
    float gaussDist; //used to calculate rLength

    //funcions and constructors
  public:
    DNA();
    ~DNA();
    void OpenFile(string input);
    float calcMean();
    float calcVariance(string input);
    float calcStdev();
    void calcBigram(string input);
    float calcProb(float count);
    float calcProbBigram(float count);
    void writeHeader();
    void writeFile(string input);
    void resetVariables();
    float gaussianDist();
    void generateDNA();
};
