#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <string>

struct Config {
    string algorithm, inputFile, outputFile, errorMsg;
    bool isValid = true;
};

#endif
