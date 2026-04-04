#ifndef AHOCORASICK_H
#define AHOCORASICK_H
#include <string>
#include <vector>
struct Node{
    char pC;
    std::vector<int> pos;
    std::vector<Node*> nxt;
    std::vector<Node*> go;
    Node* link;
    Node* par;

    Node(){
        nxt.assign(26, nullptr);
        go.assign(26, nullptr);
        link = par = nullptr;
        pC = '\0';
    }
};
#endif