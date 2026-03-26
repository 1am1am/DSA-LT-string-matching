#include <iostream>
#include <vector>
#include <string>
#include "algorithms.h"
#include "data_generator.h"

Result bruteForce(Data data) {
    Result result;
    for (std::string keyword : data.pattern) {
        for (int i = 0; i < data.R; ++i) {
            for (int j = 0; j < data.C - keyword.size(); ++j) {
                int k = 0;
                while (k < keyword.size() && data.text[i][j] == keyword[k]) {
                    if (data.text[i][j] != keyword[k]) break;
                    ++k;
                }
                if (k == keyword.size()) result.positions.push_back({i, j});
            }
        }
    }
}