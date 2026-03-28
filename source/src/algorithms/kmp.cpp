#include <iostream>
#include <string>
#include <vector>

using namespace std;

void convertGridTextToString(vector<vector<char>>Text, vector<string> &ans){
    int R = (int)Text.size();
    int C = (int)Text[0].size();

    string tmpString;
    vector<string> ans;

    //row
    for(int i = 0; i < R; ++i){
        tmpString = "";
        for(int j = 0; j < C; ++j){
            tmpString += Text[i][j];
        }
        ans.push_back(tmpString);
    }

    //column
    for(int j = 0; j < C; ++j){
        tmpString = "";
        for(int i = 0; i < R; ++i){
            tmpString += Text[i][j];
        }
        ans.push_back(tmpString);
    }

    return;
}

void makeKMP(string ans){
    int N = (int)ans.size();
    vector<int> pi(N, 0);

    for(int i = 0; i < N; ++i){
        int j = pi[i - 1];
        while(j >= 0 && ans[j + 1] != ans[i]){
            j = pi[j];
        }
        if(ans[j + 1] == ans[i]) ++j;
        pi[i] = j;
    }
}

void KMP(vector<vector<char>>Text, vector<string> K){
    
    vector<string> List_string;

    convertGridTextToString(Text, List_string);

    int N = (int)List_string.size(); //Size of list string
    int M = (int)K.size();

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            makeKMP(K[j] + '#' + List_string[i] );
        }
    }

    return;
}