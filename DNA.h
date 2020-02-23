#include <iostream>
#include <string>
using namespace std;

class DNA
{
  private:
    int ACount;
    int CCount;
    int GCount;
    int TCount;
    float Total;
    float LineCount = -1.0;
    float LineCharCount;
    float Mean;
    float Stdev;
    float Variance;
    float ProbA;
    float ProbC;
    float ProbG;
    float ProbT;
    float ProbAA;
    float ProbAC;
    float ProbAG;
    float ProbAT;
    float ProbCA;
    float ProbCC;
    float ProbCG;
    float ProbCT;
    float ProbGA;
    float ProbGC;
    float ProbGG;
    float ProbGT;
    float ProbTA;
    float ProbTC;
    float ProbTG;
    float ProbTT;

  public:
    DNA();
    ~DNA();
    void OpenFile(string input);
    float calcMean();
    float calcVariance(string input);
    float calcStdev();
};
