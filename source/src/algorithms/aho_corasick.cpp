#include <iostream>
#include "kmp.h"
#include "algorithms.h"
#include "aho_corasick.h"
#include "data_generator.h"

using namespace std;

Node* root = nullptr;

void add(string S, Node* &root, int IDX){
    if(root == nullptr) root = new Node;
    Node* cur = root;
    for(auto c : S){
        int idx = c -'a';
        
        if(cur->nxt[idx] == nullptr) cur->nxt[idx] = new Node;

        cur->nxt[idx]->par = cur;
        cur = cur->nxt[idx];
        cur->pC = c;
    }
    cur->pos.push_back(IDX);
}

void removeTrie(Node* &root){
    if(root == nullptr) return;

    for(int i = 0; i < 26; ++i){
        removeTrie(root->nxt[i]);
    }

    delete root;
    root = nullptr;
}

Node* go(Node* u, char c);

Node* getLink(Node* u){
    if(u->link == nullptr){
        if(u == root || u->par == root) return u->link = root;
        else{
            return u->link = go(getLink(u->par), u->pC);
        }
    }
    return u->link;
}

Node* go(Node* u, char c){
    int idx = c - 'a';
    
    if(u->go[idx] == nullptr){
        if(u->nxt[idx] != nullptr){
            return u->go[idx] = u->nxt[idx];
        }
        else{
            return u->go[idx] = u == root ? u : go(getLink(u), c);
        }
    }

    return u->go[idx];
}

void Search(string S, Data data, vector<vector<Position>> &ans, int IDX){
    Node* cur = root;
    int lenS = (int)S.size();

    for(int i = 0; i < lenS; ++i){
        cur = go(cur, S[i]);
        Node* tmp = cur;

        while(tmp != root){
            int N = (int)tmp->pos.size();

            if(N > 0){
                for(auto idx : tmp->pos){
                    Position _pos;

                    if(IDX < data.R){
                        _pos.startPos.first = IDX;
                        _pos.startPos.second = i - (int)data.patterns[idx].size() + 1;
                        _pos.endPos.first = IDX;
                        _pos.endPos.second = i;
                    }
                    else{
                        _pos.startPos.first = i - (int)data.patterns[idx].size() + 1;
                        _pos.startPos.second = IDX - data.R;;
                        _pos.endPos.first = i;
                        _pos.endPos.second = IDX - data.R;;
                    }
                    
                    ans[idx].push_back(_pos);
                }
            }

            tmp = getLink(tmp);
        }
    }
}

std::vector<std::vector<Position>> ahoCorasick(Data data, long long& comparisons){
    
    vector<string> List_string;

    convertGridTextToString(data.text, List_string);

    vector<vector<Position>> pos((int)List_string.size());
    int N = (int)data.patterns.size();
    int M = (int)List_string.size();

    for(int i = 0; i < N; ++i){
        add(data.patterns[i], root, i);
    }

    for(int i = 0; i < M; ++i){
        Search(List_string[i], data, pos, i);
    }

    removeTrie(root);
    return pos;
}

std::vector<std::vector<Position>> ahoCorasick(Data data, long long& comparisons){
    comparisons = 0;
    return ahoCorasick(data);
}