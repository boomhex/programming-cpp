#include "workforce/workforce.h"

using namespace std;

int main()
{
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    WorkForce wf;
    wf.run(inputFile, outputFile);
}