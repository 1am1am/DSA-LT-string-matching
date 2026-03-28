#ifndef EXECUTOR_H 
#define EXECUTOR_H

#include <string>
#include <vector>
#include "algorithms.h"

using namespace std;

Result getAlgorithm(string Name, Data data);

void readFile(string inputFile, Data& data);

void writeOutputFile(const string& outputFile, const string& algName, const Data& data, const Result& result);

#endif