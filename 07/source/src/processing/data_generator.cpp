#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <random>
#include "../../include/algorithms.h"

#include "../../include/data_generator.h"

const int RANDOM_CHAR = 'z' - 'a';
const int MAX_RANDOM_POS = 10; 

std::mt19937 rng(7405);

std::mt19937 rng2(std::chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return abs((int)rng() % (r - l + 1)) + l;
}

char createCharacter() {
    return rnd(0, RANDOM_CHAR) + 'a';
}

std::pair<int, int> createPos(int R, int C) {
    return {rnd(0, R - 1), rnd(0, C - 1)};
}

std::vector<std::vector<char>> getText(int R, int C, std::vector<std::string> patterns) {
    std::vector<std::vector<char>> text(R, std::vector<char>(C));

    for (std::string pattern : patterns) {
        int repeat = rnd(0, MAX_RANDOM_POS);
        for (int i = 0; i < repeat; ++i) {
            std::pair<int, int> pos = createPos(R, C);
            bool selectDirection = rnd(0, 1); //1 horizontal, 0 vertical

            if (selectDirection && pos.second + pattern.size() > C) continue;
            if (!selectDirection && pos.first + pattern.size() > R) continue;

            if (selectDirection) {
                for (int j = pos.second; j < pos.second + pattern.size(); ++j) {
                    text[pos.first][j] = pattern[j - pos.second];
                }
            }
            else {
                for (int j = pos.first; j < pos.first + pattern.size(); ++j) {
                    text[j][pos.second] = pattern[j - pos.first];
                }
            }
        }
    }
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (text[i][j] == '\0') text[i][j] = createCharacter();
        }
    }
    return text;
}

std::vector<std::string> getPatterns(int K, int R, int C) {
    std::vector<std::string> patterns;
    int maxSize = std::min(R, C);

    for (int i = 0; i < K; ++i) {
        int textSize = rnd(1, maxSize);
        std::string s;
        for (int j = 0; j < textSize; ++j) {
            s += createCharacter();
        }
        patterns.push_back(s);
    }
    return patterns;
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
        fout << data.patterns[i] << '\n';
    }

    fout.close();
}







void scenario1(Config config) {
    int patternsSize = 5;
    std::vector<std::pair<int, int>> matrixSize = {{10, 10}, {50, 50}, {100, 100}, {500, 500}};

    for (int i = 0; i < matrixSize.size(); ++i) {
        config.inputFile = "../../data/scenario1_" + std::to_string(i + 1) + ".txt";
        std::vector<std::string> patterns = getPatterns(patternsSize, matrixSize[i].first, matrixSize[i].second);
        Data data(
            matrixSize[i].first,
            matrixSize[i].second,
            getText(matrixSize[i].first, matrixSize[i].second, patterns),
            patternsSize,
            patterns
        );
        printInput(data, config);
    }
}

void scenario2(Config config) {
    std::pair<int, int> matrixSize = {100, 100};
    std::vector<int> patternsSize = {1, 10, 50, 100};
    for (int i = 0; i < patternsSize.size(); ++i) {
        config.inputFile = "../../data/scenario2_" + std::to_string(i + 1) + ".txt";
        std::vector<std::string> patterns = getPatterns(patternsSize[i], matrixSize.first, matrixSize.second);
        Data data(
            matrixSize.first,
            matrixSize.second,
            getText(matrixSize.first, matrixSize.second, patterns),
            patternsSize[i],
            patterns
        );
        printInput(data, config);
    }
}