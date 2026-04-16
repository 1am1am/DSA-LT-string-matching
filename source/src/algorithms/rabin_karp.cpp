#include "../../include/algorithms.h"
using namespace std;

vector<vector<Position>> rabinKarp(Data data, long long& comparisons) {
    int R = data.R;
    int C = data.C;
    int K = data.K;
    

    vector<vector<Position>> result(K);
    

    long long d = 256;
    long long q = 1000000007;

    for (int p_idx = 0; p_idx < K; ++p_idx) {
        const std::string& pat = data.patterns[p_idx];
        int M = pat.length();
        if (M == 0) continue;

        long long h = 1;
        for (int i = 0; i < M - 1; ++i) {
            h = (h * d) % q;
        }

        long long p_hash = 0;
        for (int i = 0; i < M; ++i) {
            p_hash = (d * p_hash + pat[i]) % q;
        }


        if (M <= C) {
            for (int r = 0; r < R; ++r) {
                long long t_hash = 0;

                for (int i = 0; i < M; ++i) {
                    t_hash = (d * t_hash + data.text[r][i]) % q;
                }

                for (int c = 0; c <= C - M; ++c) {
                    if (p_hash == t_hash) {
                        bool match = true;
                        for (int j = 0; j < M; ++j) {
                            comparisons++;
                            if (data.text[r][c + j] != pat[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            result[p_idx].push_back(Position({r, c}, {r, c + M - 1}));
                        }
                    }

                    if (c < C - M) {
                        t_hash = (d * (t_hash - data.text[r][c] * h) + data.text[r][c + M]) % q;
                        if (t_hash < 0) t_hash += q; 
                    }
                }
            }
        }


        if (M <= R) {
            for (int c = 0; c < C; ++c) {
                long long t_hash = 0;

                for (int i = 0; i < M; ++i) {
                    t_hash = (d * t_hash + data.text[i][c]) % q;
                }

                for (int r = 0; r <= R - M; ++r) {
                    if (p_hash == t_hash) {
                        bool match = true;
                        for (int j = 0; j < M; ++j) {
                            comparisons++;
                            if (data.text[r + j][c] != pat[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            result[p_idx].push_back(Position({r, c}, {r + M - 1, c}));
                        }
                    }

                    if (r < R - M) {
                        t_hash = (d * (t_hash - data.text[r][c] * h) + data.text[r + M][c]) % q;
                        if (t_hash < 0) t_hash += q;
                    }
                }
            }
        }
    }
    return result;
}
vector<vector<Position>> rabinKarp(Data data) {
    long long dummy_comparisons = 0;
    return rabinKarp(data, dummy_comparisons);
}