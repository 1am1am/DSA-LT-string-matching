#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <random>
#include "include\algorithms.h"


#include "data_generator.h"

const int RANDOM_CHAR = 'z' - 'a';

std::mt19937 rng(7405);

std::mt19937 rng2(std::chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return abs((int)rng() % (r - l + 1)) + l;
}

char createCharacter() {
    return rnd(0, RANDOM_CHAR) + 'a';
}

std::vector<std::vector<char>> getText(int R, int C) {
    std::vector<std::vector<char>> text(R, std::vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            text[i][j] = createCharacter();
        }
    }
    return text;
}

std::vector<std::string> getPattern(int K, int R, int C) {
    std::vector<std::string> pattern;
    int maxSize = std::min(R, C);

    for (int i = 0; i < K; ++i) {
        int textSize = rnd(1, maxSize);
        std::string s;
        for (int j = 0; j < textSize; ++j) {
            s += createCharacter();
        }
        pattern.push_back(s);
    }
    return pattern;
}

void printInput(Data data, Config config) {
    std::string filename = config.inputFile;
    std::ofstream fout(filename);
    
    fout << data.R << ' ' << data.C << '\n';
    for (int i = 0; i < data.R; ++i) {
        for (int j = 0; j < data.C; ++j) {
            fout << data.text[i][j] << ' ';
        }
        fout << '\n';
    }
    fout << data.K << '\n';
    for (int i = 0; i < data.K; ++i) {
        fout << data.pattern[i] << '\n';
    }

    fout.close();
}


void printOutput(Result result, Config config) {

    std::string filename = config.inputFile;
    std::ofstream fout(filename);
    


}




void scenario1(Config config) {
    int patternSize = 5;
    std::vector<std::pair<int, int>> matrixSize = {{10, 10}, {50, 50}, {100, 100}, {500, 500}};

    for (int i = 0; i < matrixSize.size(); ++i) {
        config.inputFile = "./source/data/scenario1_" + std::to_string(i + 1) + ".txt";
        Data data(
            matrixSize[i].first,
            matrixSize[i].second,
            getText(matrixSize[i].first, matrixSize[i].second),
            patternSize,
            getPattern(patternSize, matrixSize[i].first, matrixSize[i].second)
        );
        printInput(data, config);
    }
}

void scenario2(Config config) {
    std::pair<int, int> matrixSize = {100, 100};
    std::vector<int> patternSize = {1, 10, 50, 100};
    for (int i = 0; i < patternSize.size(); ++i) {
        config.inputFile = "./source/data/scenario2_" + std::to_string(i + 1) + ".txt";
        Data data(
            matrixSize.first,
            matrixSize.second,
            getText(matrixSize.first, matrixSize.second),
            patternSize[i],
            getPattern(patternSize[i], matrixSize.first, matrixSize.second)
        );
        printInput(data, config);
    }
}