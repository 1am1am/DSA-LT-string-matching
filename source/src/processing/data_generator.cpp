#include "include/data_generator.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <fstream>

const int RANDOM_CHAR = 26;

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

    while (--K) {
        int textSize = rnd(1, maxSize);
        std::string s;
        while (--textSize) {
            s += createCharacter();
        }
        pattern.push_back(s);
    }
    return pattern;
}

void scenario1() {
    int K = 5;
    std::vector<std::pair<int, int>> matrixSize = {{10, 10}, {50, 50}, {100, 100}, {500, 500}};

    for (int i = 0; i < matrixSize.size(); ++i) {
        RandomData data(
            matrixSize[i].first,
            matrixSize[i].second,
            getText(matrixSize[i].first, matrixSize[i].second),
            getPattern(K, matrixSize[i].first, matrixSize[i].second)
        );
        printInput(data);
    }
}

void scenario2() {
    std::pair<int, int> matrixSize = {100, 100};
    std::vector<int> patternSize = {1, 10, 50, 100};
    for (int i = 0; i < patternSize.size(); ++i) {
        RandomData data(
            matrixSize.first,
            matrixSize.second,
            getText(matrixSize.first, matrixSize.second),
            getPattern(patternSize[i], matrixSize.first, matrixSize.second)
        );
        printInput(data);
    }
}

void printInput(RandomData data) {
    std::string filename = "input.txt";
    std::ofstream fout(filename);
    
    fout << data.R << ' ' << data.C;
    for (int i = 0; i < data.R; ++i) {
        for (int j = 0; j < data.C; ++j) {
            fout << data.text[i][j] << ' ';
        }
        fout << '\n';
    }
    fout << data.K;
    for (int i = 0; i < data.K; ++i) {
        fout << data.pattern[i] << '\n';
    }

    fout.close();
}