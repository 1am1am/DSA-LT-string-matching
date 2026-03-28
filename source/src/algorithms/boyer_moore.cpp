#include <iostream>
#include "algorithms.h"
#include <string>
#include <vector>
using namespace std;

void badChar(string pattern , vector<int>& bad) {
    bad.assign(256,-1);
    for (int i = 0 ; i < pattern.size() ; i++) {
        bad[pattern[i]] = i;
    }
}

vector<Position> findPosRow(int row, string pattern, string text) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> bad;
    badChar(pattern, bad);
    int s = 0 ;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0 ) {
            Position pos;
            pair<int, int> start = {row, s};
            pair<int, int> end = {row, s + m -1};
            pos.startPos = start;
            pos.endPos = end;
            result.push_back(pos); 
            s+=1;
        }

        else {
            int shift = j - bad[text[s + j]];
            s+= max(1,shift);
        }

      
    }
      return result;

} 

vector<Position> findPosRowComp(int row, string pattern, string text, long long&comparisons) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> bad;
    badChar(pattern, bad);
    int s = 0 ;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0) {
            comparisons++;  

            if (pattern[j] == text[s + j]) {
                j--;
            } else break;
        }

        if (j < 0 ) {
            Position pos;
            pair<int, int> start = {row, s};
            pair<int, int> end = {row, s + m -1};
            pos.startPos = start;
            pos.endPos = end;
            result.push_back(pos); 
            s+=1;
        }

        else {
            int shift = j - bad[text[s + j]];
            s+= max(1,shift);
        }

      
    }
      return result;

} 


vector<Position> findPosCol(int col, const string&pattern, string text) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> bad;
    badChar(pattern, bad);
    int s = 0 ;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0 ) {
            Position pos;
            pair<int, int> start = {s, col};
            pair<int, int> end = {s + m -1, col};
            pos.startPos = start;
            pos.endPos = end;
            result.push_back(pos); 
            s+=1;
        }

        else {
            int shift = j - bad[text[s + j]];
            s+= max(1,shift);
        }

      
    }
      return result;

} 

vector<Position> findPosColComp(int col, const string&pattern, string text, long long& comparisons) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    vector<int> bad;
    badChar(pattern, bad);
    int s = 0 ;
    while (s <= n - m) {
        int j = m - 1;
        
        while (j >= 0) {
            comparisons++;  

            if (pattern[j] == text[s + j]) {
                j--;
            } else break;
        }

        if (j < 0 ) {
            Position pos;
            pair<int, int> start = {s, col};
            pair<int, int> end = {s + m -1, col};
            pos.startPos = start;
            pos.endPos = end;
            result.push_back(pos); 
            s+=1;
        }

        else {
            int shift = j - bad[text[s + j]];
            s+= max(1,shift);
        }

      
    }
      return result;

} 
std::vector<std::vector<Position>> boyerMoore(Data data) {
    vector<vector<Position>> positions;
    int r = data.R, c = data.C;
    int k = data.K;
    vector<string> pat = data.patterns;
    vector<vector<char>> matrix = data.text;
    for (int o = 0 ; o < k ;o++) {

        string pattern  =  pat[o];
        vector<Position> position;
        for (int i = 0 ; i < r ; i++) {
            string text = "";
            for (int j = 0 ; j < c ; j++) {
                text+= matrix[i][j];
            }
            vector<Position> res = findPosRow(i,pattern,text);
            for (auto x:res) {
                position.push_back(x);
            }


        }


        for (int i = 0 ; i < c ; i++) {
            string text ="";
            for (int j = 0 ; j < r ; j++  ) {
                text+=matrix[j][i];
            }
            vector<Position> res = findPosCol(i,pattern,text);
            for (auto x:res) {
                position.push_back(x);
            }

        }
        positions.push_back(position);
    }
    return positions;
}



std::vector<std::vector<Position>> boyerMoore(Data data, long long& comparisons) {
    vector<vector<Position>> positions;
    comparisons = 0;
    int r = data.R, c = data.C;
    int k = data.K;
    vector<string> pat = data.patterns;
    vector<vector<char>> matrix = data.text;
    for (int o = 0 ; o < k ;o++) {

        string pattern  =  pat[o];
        vector<Position> position;
        for (int i = 0 ; i < r ; i++) {
            string text = "";
            for (int j = 0 ; j < c ; j++) {
                text+= matrix[i][j];
            }
            vector<Position> res = findPosRowComp(i,pattern,text, comparisons);
            for (auto x:res) {
                position.push_back(x);
            }


        }


        for (int i = 0 ; i < c ; i++) {
            string text ="";
            for (int j = 0 ; j < r ; j++  ) {
                text+=matrix[j][i];
            }
            vector<Position> res = findPosColComp(i,pattern,text,comparisons);
            for (auto x:res) {
                position.push_back(x);
            }

        }
        positions.push_back(position);
    }
    return positions;
}










