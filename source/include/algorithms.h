#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include <string>

struct Result {
    std::vector<int> positions;
    long long comparisons;
    double runningTime;
};

Result bruteForce(const std::vector<std::vector<char>>& text, const std::vector<std::string>& pattern);
Result rabinKarp(const std::vector<std::vector<char>>& text, const std::vector<std::string>& pattern);
Result KMP(const std::vector<std::vector<char>>& text, const std::vector<std::string>& pattern);
Result boyerMoore(const std::vector<std::vector<char>>& text, const std::vector<std::string>& pattern);
Result ahoCorasick(const std::vector<std::vector<char>>& text, const std::vector<std::string>& pattern);

#endif