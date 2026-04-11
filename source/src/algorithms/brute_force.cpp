#include <iostream>
#include <vector>
#include <string>
#include "../../include/algorithms.h"
#include "../../include/data_generator.h"

std::vector<std::vector<Position>> bruteForce(Data data) {
    std::vector<std::vector<Position>> pos(data.K);
    for (int keywordIndex = 0; keywordIndex < data.K; ++keywordIndex) {
        std::string keyword = data.patterns[keywordIndex];
        for (int i = 0; i < data.R; ++i) {
            for (int j = 0; j <= data.C - keyword.size(); ++j) {
                int k = 0;
                bool isMatched = true;
                while (k < keyword.size()) {
                    if (data.text[i][j + k] != keyword[k]){
                        isMatched = false;
                    }
                    ++k;
                }
                if (isMatched) {
                    Position position({i, j}, {i, j + k - 1});
                    pos[keywordIndex].push_back(position);
                }
            }
        }
    }

    for (int keywordIndex = 0; keywordIndex < data.K; ++keywordIndex) {
        std::string keyword = data.patterns[keywordIndex];
        for (int i = 0; i < data.C; ++i) {
            for (int j = 0; j <= data.R - keyword.size(); ++j) {
                int k = 0;
                bool isMatched = true;
                while (k < keyword.size()) {
                    if (data.text[j + k][i] == keyword[k]) {
                        isMatched = false;
                    }
                    ++k;
                }
                if (isMatched) {
                    Position position({j, i}, {j + k - 1, i});
                    pos[keywordIndex].push_back(position);
                }
            }
        }
    }

    return pos;
}

std::vector<std::vector<Position>> bruteForce(Data data, long long& comparisons) {
    std::vector<std::vector<Position>> pos(data.K);
    for (int keywordIndex = 0; keywordIndex < data.K; ++keywordIndex) {
        std::string keyword = data.patterns[keywordIndex];
        for (int i = 0; i < data.R; ++i) {
            for (int j = 0; j <= data.C - keyword.size(); ++j) {
                int k = 0;
                bool isMatched = true;
                while (k < keyword.size()) {
                    if (++comparisons && data.text[i][j + k] == keyword[k]) {
                        isMatched = false;
                    }
                    ++k;
                }
                if (isMatched) {
                    Position position({i, j}, {i, j + k - 1});
                    pos[keywordIndex].push_back(position);
                }
            }
        }
    }

    for (int keywordIndex = 0; keywordIndex < data.K; ++keywordIndex) {
        std::string keyword = data.patterns[keywordIndex];
        for (int i = 0; i < data.C; ++i) {
            for (int j = 0; j <= data.R - keyword.size(); ++j) {
                int k = 0;
                bool isMatched = true;
                while (k < keyword.size()) {
                    if (++comparisons && data.text[j + k][i] == keyword[k]) {
                        isMatched = false;
                    }
                    ++k;
                }
                if (isMatched) {
                    Position position({j, i}, {j + k - 1, i});
                    pos[keywordIndex].push_back(position);
                }
            }
        }
    }

    return pos;
}
