#include <iostream>
#include "all_headers.h"

void test(std::vector<std::vector<Position>> (*func)(Data)) {
    Data data;
    data.R = 10;
    data.C = 10;
    data.K = 5;
    data.patterns = {"hkq", "oq", "xsnthd", "jgojl", "wnaezm"};
    data.text = {
    {'s', 'n', 'x', 'o', 'y', 'g', 'u', 'b', 'f', 'h'},
    {'h', 'l', 'r', 'f', 'm', 't', 'o', 'q', 'w', 'f'},
    {'r', 'o', 'y', 'y', 'f', 'k', 'i', 'j', 't', 'm'},
    {'o', 'q', 'h', 'w', 's', 'g', 's', 'n', 'f', 'n'},
    {'j', 'x', 'j', 'h', 'k', 'q', 'e', 'g', 'p', 'j'},
    {'t', 't', 'h', 'v', 'v', 'o', 'h', 'k', 'q', 'l'},
    {'m', 'l', 'j', 'v', 'v', 'j', 'h', 's', 'u', 'n'},
    {'m', 'j', 'o', 'q', 'u', 'n', 'n', 'f', 'j', 'o'},
    {'y', 't', 'n', 'y', 'z', 'y', 'r', 'w', 'm', 'h'},
    {'n', 'o', 'q', 't', 'r', 'n', 'b', 'k', 'e', 'z'}
    };

    std::vector<std::vector<Position>> ans = func(data);

    for (int i = 0; i < data.K; ++i) {
        std::cout << "Tu khoa '" << data.patterns[i] << "': ";
        
        if (ans[i].empty()) {
            std::cout << "Khong tim thay!";
        } else {
            for (size_t j = 0; j < ans[i].size(); ++j) {
                std::cout << "(" << ans[i][j].startPos.first << ", " << ans[i][j].startPos.second << ") -> (" << ans[i][j].endPos.first << ", " << ans[i][j].endPos.second << "); ";
            }
        }
        std::cout << "\n";
    }

    //Ket qua dung la:
    // Tu khoa 'hkq': (4, 3) -> (4, 6); (5, 6) -> (5, 9);
    // Tu khoa 'oq': (1, 6) -> (1, 8); (3, 0) -> (3, 2); (7, 2) -> (7, 4); (9, 1) -> (9, 3); (2, 1) -> (4, 1);
    // Tu khoa 'xsnthd': Khong tim thay!
    // Tu khoa 'jgojl': Khong tim thay!
    // Tu khoa 'wnaezm': Khong tim thay!
}

int main() {
    //g++ -I source/include source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o source/07.exe -std=c++17
    Config config;

    scenario1(config);
    scenario2(config);

    // test(bruteForce);

    return 0;
}