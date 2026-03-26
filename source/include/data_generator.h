#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H
#include <string>
#include <vector>

struct RandomData {
    int R, C;
    std::vector<std::vector<char>> text;
    int K;
    std::vector<std::string> pattern;

    RandomData(){
        R = C = K = 0;
        return;
    }
    RandomData(int self_R, int self_C, std::vector<std::vector<char>> self_text, std::vector<std::string> self_pattern) {
        R = self_R;
        C = self_C;
        text = self_text;
        pattern = self_pattern;
        return;
    }
};

void scenario1();
void scenario2();

#endif