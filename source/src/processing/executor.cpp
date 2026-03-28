#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "executor.h"

using namespace std;

Result getAlgorithm(string Name, Data data) {
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

void readFile(string inputFile, Data& data) {
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cout << "Error opening input file: " << inputFile << "!\n";
        exit(0);
    }
    if (!(fin >> data.R >> data.C)) return;
    
    data.text.assign(data.R, vector<char>(data.C));
    for (int i = 0; i < data.R; ++i) {
        for (int j = 0; j < data.C; ++j) {
            fin >> data.text[i][j];
        }
    }
    if (!(fin >> data.K)) return;
    
    data.patterns.assign(data.K, "");
    for (int i = 0; i < data.K; ++i) {
        fin >> data.patterns[i];
    }
    
    fin.close();
}

void writeOutputFile(const string& outputFile, const string& algName, const Data& data, const Result& result) {
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cout << "Error opening output file: " << outputFile << endl;
        return;
    }

    for (int i = 0; i < data.K; ++i) {
        fout << data.patterns[i] << ": ";
        
        if (result.positions[i].empty()) {
            fout << "not found\n";
        } else {
            for (size_t j = 0; j < result.positions[i].size(); ++j) {
                fout << "(" << result.positions[i][j].startPos.first << "," 
                     << result.positions[i][j].startPos.second << ") -> (" 
                     << result.positions[i][j].endPos.first << "," 
                     << result.positions[i][j].endPos.second << ");";
                
                if (j < result.positions[i].size() - 1) {
                    fout << " ";
                }
            }
            fout << "\n";
        }
    }
    fout << "-------------------------\n";

    string fullAlgName = "";
    if (algName == "bf") fullAlgName = "Brute Force";
    else if (algName == "rk") fullAlgName = "Rabin-Karp";
    else if (algName == "kmp") fullAlgName = "KMP";
    else if (algName == "bm") fullAlgName = "Boyer-Moore";
    else if (algName == "ac") fullAlgName = "Aho-Corasick";
    else fullAlgName = "Unknown";

    fout << "Algorithm: " << fullAlgName << "\n";
    fout << "Comparisons: " << result.comparisons << "\n";
    fout << "Execution Time: " << fixed << setprecision(2) << result.runningTime << " ms.\n";

    fout.close();
}