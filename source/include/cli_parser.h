#ifndef CLI_PARSER_H
#define CLI_PARSER_H
#include <vector>
#include <string>

struct Config {
    std::string algorithm;
    
    std::vector<std::string> pattern;
    std::string inputFile;
    
    bool isValid = true;
    bool showPositions = false;

    std::string errorMsg;
};

#endif