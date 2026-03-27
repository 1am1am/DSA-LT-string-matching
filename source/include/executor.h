#ifndef EXECUTOR_H 
#define EXECUTOR_H

#include <string>
#include <vector>
#include "algorithms.h"
// #include "commandProcessing.h"

using namespace std;
Result getAlgorithm(string Name, const vector<vector<char>>& text, const vector<string>& patterns);
void readFile(string inputFile, vector<vector<char>>& text, vector<string>& patterns);

#endif