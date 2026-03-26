#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H
#include <string>
#include <vector>
#include "cli_parser.h"

struct Data {
    int R, C;
    std::vector<std::vector<char>> text;
    int K;
    std::vector<std::string> pattern;

    Data(){
        R = C = K = 0;
        return;
    }
    Data(int self_R, int self_C, std::vector<std::vector<char>> self_text, int self_K, std::vector<std::string> self_pattern) {
        R = self_R;
        C = self_C;
        text = self_text;
        K = self_K;
        pattern = self_pattern;
        return;
    }
};

void scenario1(Config config);
void scenario2(Config config);

#endif