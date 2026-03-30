#include <iostream>
#include "all_headers.h"
#include "cli_parser.h"

void test(std::vector<std::vector<Position>> (*func)(Data)) {
    Data data;
    data.R = 10;
    data.C = 10;
    data.K = 5;
    data.patterns = {
        "dz",
        "kyumiusbn",
        "xsnthd",
        "jgojl",
        "wnaezm"
    };
    data.text = {
        {'u', 'n', 'm', 'j', 'o', 'q', 'u', 'n', 'n', 'f'},
        {'j', 'd', 'o', 'x', 's', 'n', 't', 'h', 'd', 'y'},
        {'t', 'z', 'n', 'y', 'z', 'y', 'r', 'w', 'm', 'h'},
        {'n', 'i', 'w', 'd', 'z', 't', 'r', 'n', 'b', 'k'},
        {'e', 'z', 's', 's', 'z', 'u', 'o', 'r', 'd', 'i'},
        {'s', 'p', 'n', 't', 'o', 'x', 'p', 'i', 'z', 'r'},
        {'h', 'j', 'g', 'i', 'e', 'b', 'e', 'm', 'p', 'm'},
        {'t', 'o', 'k', 'x', 's', 'b', 't', 'a', 'p', 'd'},
        {'y', 'r', 'q', 'p', 'b', 'u', 'u', 'c', 'x', 'e'},
        {'m', 'x', 's', 'w', 'n', 'a', 'e', 'z', 'm', 'a'}
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
    // Tu khoa 'dz': (3, 3) -> (3, 4); (1, 1) -> (2, 1); (4, 8) -> (5, 8); 
    // Tu khoa 'kyumiusbn': Khong tim thay!
    // Tu khoa 'xsnthd': (1, 3) -> (1, 8);
    // Tu khoa 'jgojl': Khong tim thay!
    // Tu khoa 'wnaezm': (9, 3) -> (9, 8);
}

int main(int argc, char* argv[]) {
    //g++ -I source/include source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o source/07.exe -std=c++17
    Config config = getCommand(argc, argv);
    Data data;
    readFile(config.inputFile, data);
    Result result = getAlgorithm(config.algorithm, data);
    writeOutputFile(config.outputFile, config.algorithm, data, result);


    // scenario1(config);
    // scenario2(config);

    

    return 0;
}