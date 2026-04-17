#include <iostream>
#include "../../include/algorithms.h"
#include "../../include/data_generator.h"

using namespace std;

void convertGridTextToString(vector<vector<char>>Text, vector<string> &ans){
    int R = (int)Text.size();
    int C = (int)Text[0].size();

    string tmpString;

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

Position calPos(int indexOfList_string, int lenOfPattern, Data data, int idx){
    Position _pos;

    if(indexOfList_string < data.R){
        //row
        _pos.startPos.first = indexOfList_string;
        _pos.startPos.second = idx - 2 * lenOfPattern; 
        //calculate the pos of idx in grid 

        _pos.endPos.first = indexOfList_string;
        _pos.endPos.second = idx - lenOfPattern - 1;
    }
    else{
        //column
        _pos.startPos.first = idx - 2 * lenOfPattern;
        _pos.startPos.second =  indexOfList_string - data.R; 
        //calculate the pos of idx in grid 

        _pos.endPos.first = idx - lenOfPattern - 1;
        _pos.endPos.second = indexOfList_string - data.R;
    }

    return _pos;
}

std::vector<std::vector<Position>> KMP(Data data){
    
    vector<vector<Position>> pos(data.K);
    vector<string> List_string;

    convertGridTextToString(data.text, List_string);

    int N = (int)List_string.size(); //Size of list string
    int M = (int)data.K;
    vector<int> pi;

    for(int indexOfList_string = 0; indexOfList_string < N; ++indexOfList_string){
        for(int indexOfPattern = 0; indexOfPattern < M; ++indexOfPattern){

            string kmp = data.patterns[indexOfPattern] + '#' + List_string[indexOfList_string];
            int lenOfkmp = (int)kmp.size();
            int lenOfPattern = (int)data.patterns[indexOfPattern].size();
            pi.assign(lenOfkmp, 0);

            for(int i = 1; i < lenOfkmp; ++i){
                int j = pi[i - 1];

                while(j > 0 && kmp[j] != kmp[i]){
                    j = pi[j - 1];
                }

                if(kmp[j] == kmp[i]) ++j;
                pi[i] = j;
                
                if(pi[i] == lenOfPattern){
                    Position _pos = calPos(indexOfList_string, lenOfPattern, data, i);
                    pos[indexOfPattern].push_back(_pos);
                }
            }
        }
    }

    return pos;
}

std::vector<std::vector<Position>> KMP(Data data, long long& comparisons){
    
    vector<vector<Position>> pos(data.K);
    vector<string> List_string;

    convertGridTextToString(data.text, List_string);

    int N = (int)List_string.size(); //Size of list string
    int M = (int)data.K;
    vector<int> pi;

    for(int indexOfList_string = 0; indexOfList_string < N; ++indexOfList_string){
        for(int indexOfPattern = 0; indexOfPattern < M; ++indexOfPattern){

            string kmp = data.patterns[indexOfPattern] + '#' + List_string[indexOfList_string];
            int lenOfkmp = (int)kmp.size();
            int lenOfPattern = (int)data.patterns[indexOfPattern].size();
            pi.assign(lenOfkmp, 0);

            for(int i = 1; i < lenOfkmp; ++i){
                int j = pi[i - 1];

                while(++comparisons && j > 0 && kmp[j] != kmp[i]){
                    j = pi[j - 1];
                }

                if(++comparisons && kmp[j] == kmp[i]) ++j;
                pi[i] = j;
                
                if(pi[i] == lenOfPattern){
                    Position _pos = calPos(indexOfList_string, lenOfPattern, data, i);
                    pos[indexOfPattern].push_back(_pos);
                }
            }
        }
    }

    return pos;
}