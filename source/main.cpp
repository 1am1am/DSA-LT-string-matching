#include <iostream>
#include "all_headers.h"

int main() {
    //g++ -I source/include source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o source/07.exe -std=c++17
    Config config;

    scenario1(config);
    scenario2(config);
    return 0;
}