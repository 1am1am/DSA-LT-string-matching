#include "executor.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

Result getAlgorithm(string Name, const vector<vector<char>>& text, const vector<string>& patterns) {
    Data data;
    data.R = text.size();
    data.C = text.empty() ? 0 : text[0].size();
    data.K = patterns.size();
    data.pattern = patterns;
    data.text = text;

    Result res;
    res.comparisons = 0;


    auto start = chrono::high_resolution_clock::now();


    if (Name == "bf") {
        res.positions = bruteForce(data, res.comparisons);
    }
    else if (Name == "rk") {
        res.positions = rabinKarp(data, res.comparisons);
    }
    else if (Name == "kmp") {
        res.positions = KMP(data, res.comparisons);
    }
    else if (Name == "bm") {
        res.positions = boyerMoore(data, res.comparisons);
    }
    else if (Name == "ac") {
        res.positions = ahoCorasick(data, res.comparisons); 
    }
    else {
        cout << "Error: Unknown algorithm name!" << endl;
        return res;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    res.runningTime = elapsed.count();

    return res;
}

void readFile(string inputFile, vector<vector<char>>& text, vector<string>& patterns) {
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cout << "Error opening input file!\n";
        exit(0);
    }
    int R, C;
    if (!(fin >> R >> C)) return;
    text.assign(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            fin >> text[i][j];
        }
    }
    int K;
    if (!(fin >> K)) return;
    patterns.assign(K, "");
    for (int i = 0; i < K; ++i) {
        fin >> patterns[i];
    }
    fin.close();
}