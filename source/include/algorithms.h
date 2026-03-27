#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include <string>
#include "data_generator.h"

struct Position {
    std::pair<int, int> startPos;
    std::pair<int, int> endPos;
    Position() {
        return;
    };
    Position(std::pair<int, int> self_startPos, std::pair<int, int> self_endPos) {
        startPos = self_startPos;
        endPos = self_endPos;
    }
};

struct Result {
    std::vector<std::vector<Position>> positions;
    long long comparisons;
    double runningTime;
};

std::vector<std::vector<Position>> bruteForce(Data data);
std::vector<std::vector<Position>> bruteForce(Data data, long long& comparisons);

std::vector<std::vector<Position>> rabinKarp(Data data);
std::vector<std::vector<Position>> rabinKarp(Data data, long long& comparisons);

std::vector<std::vector<Position>> KMP(Data data);
std::vector<std::vector<Position>> KMP(Data data, long long& comparisons);

std::vector<std::vector<Position>> boyerMoore(Data data);
std::vector<std::vector<Position>> boyerMoore(Data data, long long& comparisons);

std::vector<std::vector<Position>> ahoCorasick(Data data);
std::vector<std::vector<Position>> ahoCorasick(Data data, long long& comparisons);

#endif