#include <iostream>
#include "all_headers.h"
#include "cli_parser.h"

bool test(Data data) {
   /* Data data;
    data.R = R;
    data.C = C;
    data.K = K;
    data.patterns = getPatterns(K, R, C);
    data.text = getText(R, C, data.patterns);
    */
    cout << "Data(K, R, C): " << data.K << ' ' << data.R << ' ' << data.C << endl;
    Result ans = getAlgorithm("bf",  data);
    cout << "Brute_force\n" << "Time ms: " << ans.runningTime << "\nComparisons: " << ans.comparisons << '\n';
    ans = getAlgorithm("kmp",  data);
    cout << "KMP\n" << "Time ms: " << ans.runningTime << "\nComparisons: " << ans.comparisons << '\n';
    ans = getAlgorithm("rk",  data);
    cout << "Rabin_karp\n" << "Time ms: " << ans.runningTime << "\nComparisons: " << ans.comparisons << '\n';
    ans = getAlgorithm("bm",  data);
    cout << "Boyer_moore\n" << "Time ms: " << ans.runningTime << "\nComparisons: " << ans.comparisons << '\n';
    ans = getAlgorithm("ac",  data);
    cout << "Aho_corasick\n" << "Time ms: " << ans.runningTime << "\nComparisons: " << ans.comparisons << '\n';
    /*data.patterns = {
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
    };*/
    /*
    std::vector<std::vector<Position>> ans[5];
    ans[0] = bruteForce(data);
    cout << "bruteforce done!\n";
    ans[1] = boyerMoore(data);
    cout << "boyer done!\n";
    ans[2] = rabinKarp(data);
    cout << "hash done!\n";
    ans[3] = ahoCorasick(data);
    cout << "aho done!\n";
    ans[4] = KMP(data);
    cout << "kmp done!\n";
    cout << K << ' ' << R << ' ' << C << endl;
    for (int i = 0; i < data.K; ++i) {
        for(int j = 1; j < 5; ++j){
            if(ans[0][i].size() != ans[j][i].size()){
                cout << "Thuat thu " << j << " co van de!\n";
                return 0;
            }
            else{
                for(int k = 0; k < ans[0][i].size(); ++k){
                    if(ans[0][i][k].startPos.first != ans[j][i][k].startPos.first)
                    {
                        cout << "Thuat thu " << j << " co van de!\n";
                        return 0;
                    }
                    if(ans[0][i][k].startPos.second != ans[j][i][k].startPos.second)
                    {
                        cout << "Thuat thu " << j << " co van de!\n";
                        return 0;
                    }
                    if(ans[0][i][k].endPos.first != ans[j][i][k].endPos.first)
                    {
                        cout << "Thuat thu " << j << " co van de!\n";
                        return 0;
                    }
                    if(ans[0][i][k].endPos.second != ans[j][i][k].endPos.second)
                    {
                        cout << "Thuat thu " << j << " co van de!\n";
                        return 0;
                    }
                }
            }
        }
        
    }
    //cout << "Moi thuat ok!\n";*/
    return 1;
    //Ket qua dung la:
    // Tu khoa 'dz': (3, 3) -> (3, 4); (1, 1) -> (2, 1); (4, 8) -> (5, 8); 
    // Tu khoa 'kyumiusbn': Khong tim thay!
    // Tu khoa 'xsnthd': (1, 3) -> (1, 8);
    // Tu khoa 'jgojl': Khong tim thay!
    // Tu khoa 'wnaezm': (9, 3) -> (9, 8);
}


int main(int argc, char* argv[]) {
    //g++ -I source/include source/src/algorithms/*.cpp source/src/processing/*.cpp source/main.cpp -o source/07.exe -std=c++17
   /* Config config = getCommand(argc, argv);
    Data data;
    readFile(config.inputFile, data);
    Result result = getAlgorithm(config.algorithm, data);
    writeOutputFile(config.outputFile, config.algorithm, data, result);*/

    //crossword.exe -a bf -i source/data/scenario1_1.txt -o output.txt --> command de chay

 
    // scenario1(config);
    // scenario2(config);
    // Test moi thuat
    /*
    int K = 1, R = 0, C = 0;
    int ArraySizeRC [] = {10, 50, 100, 500};
    int ArraySizeK [] = {1, 10, 50, 100};
    int n = (int)sizeof(ArraySizeRC) / sizeof(ArraySizeRC[0]);
    int m = (int)sizeof(ArraySizeK) / sizeof(ArraySizeK[0]);
    int cnt = 0;
    bool flag = 1;
    //cout << "tESTT\n";
    //while(cnt < 100 && flag == 1){
       // for(int i = 0; i < n; ++i){
      //      R = C = ArraySizeRC[i];
      //      flag &= test(K, R, C);
      //  }
        
     //   R = C = 100;

     //   for(int i = 0; i < m; ++i){
    //        K = ArraySizeK[i];
    //        flag &= test(K, R, C);
     //   }
        //if(flag) cout << "Test lan thu " << cnt << " dung!\n";
        //else cout << "Test lan thu " << cnt << " sai!\n";
        //cout << cnt << ' ' << flag << endl;
        //++cnt;
    //}
    */
    Data data;
    Config config;
    string S = "source/data/scenario";
    for(int i = 1; i <= 4; ++i){
        config.inputFile = S + to_string(1) + '_' + to_string(i) + ".txt";
        readFile(config.inputFile, data);
        test(data);
    }
    for(int i = 1; i <= 4; ++i){
        config.inputFile = S + to_string(2) + '_' + to_string(i) + ".txt";
        readFile(config.inputFile, data);
        test(data);
    }

    return 0;
}