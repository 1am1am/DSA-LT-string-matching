#include <iostream>
#include "include/all_headers.h"
#include "include/cli_parser.h"

int main(int argc, char* argv[]) {
    //g++ source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o crossword.exe -std=c++17
    Config config = getCommand(argc, argv);
    Data data;
    readFile(config.inputFile, data);
    Result result = getAlgorithm(config.algorithm, data);
    writeOutputFile(config.outputFile, config.algorithm, data, result);
    cout << "DONE!";
    //crossword.exe -a bf -i source/data/scenario1_1.txt -o output.txt --> command de chay

    return 0;
}