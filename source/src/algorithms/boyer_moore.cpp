#include <iostream>
#include "algorithms.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void badChar(string pattern, vector<int>& bad) {
    bad.assign(256, -1);
    for (int i = 0; i < pattern.size(); i++) {
        bad[(unsigned char)pattern[i]] = i;
    }
}

void goodSuffix(const string& pattern, vector<int>& gs) {
    int m = pattern.size();
    gs.assign(m, m);

    if (m == 0) return;
    if (m == 1) {
        gs[0] = 1;
        return;
    }

    vector<int> suffix(m, 0);


    suffix[m - 1] = m;
    int g = m - 1, f = 0;

    for (int i = m - 2; i >= 0; --i) {
        if (i > g && suffix[i + m - 1 - f] < i - g) {
            suffix[i] = suffix[i + m - 1 - f];
        } else {
            if (i < g) g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f]) {
                g--;
            }
            suffix[i] = f - g;
        }
    }


    for (int i = 0; i < m; i++) {
        gs[i] = m;
    }

    int j = 0;
    for (int i = m - 1; i >= -1; --i) {
        if (i == -1 || suffix[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (gs[j] == m) {
                    gs[j] = m - 1 - i;
                }
            }
        }
    }


    for (int i = 0; i <= m - 2; ++i) {
        gs[m - 1 - suffix[i]] = m - 1 - i;
    }
}

vector<Position> findPosRow(int row, string pattern, string text, const vector<int>& bad, const vector<int>& gs) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            Position pos;
            pos.startPos = {row, s};
            pos.endPos = {row, s + m - 1};
            result.push_back(pos);
            s += gs[0];
        } else {
            s += max(gs[j], j - bad[(unsigned char)text[s + j]]);
        }
    }
    return result;
}

vector<Position> findPosRowComp(int row, string pattern, string text, const vector<int>& bad, const vector<int>& gs, long long& comparisons) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            comparisons++;
            if (pattern[j] == text[s + j]) j--;
            else break;
        }
        if (j < 0) {
            Position pos;
            pos.startPos = {row, s};
            pos.endPos = {row, s + m - 1};
            result.push_back(pos);
            s += gs[0];
        } else {
            s += max(gs[j], j - bad[(unsigned char)text[s + j]]);
        }
    }
    return result;
}

vector<Position> findPosCol(int col, string pattern, string text, const vector<int>& bad, const vector<int>& gs) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            Position pos;
            pos.startPos = {s, col};
            pos.endPos = {s + m - 1, col};
            result.push_back(pos);
            s += gs[0];
        } else {
            s += max(gs[j], j - bad[(unsigned char)text[s + j]]);
        }
    }
    return result;
}

vector<Position> findPosColComp(int col, string pattern, string text, const vector<int>& bad, const vector<int>& gs, long long& comparisons) {
    vector<Position> result;
    int n = text.size();
    int m = pattern.size();
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0) {
            comparisons++;
            if (pattern[j] == text[s + j]) j--;
            else break;
        }
        if (j < 0) {
            Position pos;
            pos.startPos = {s, col};
            pos.endPos = {s + m - 1, col};
            result.push_back(pos);
            s += gs[0];
        } else {
            s += max(gs[j], j - bad[(unsigned char)text[s + j]]);
        }
    }
    return result;
}

std::vector<std::vector<Position>> boyerMoore(Data data) {
    vector<vector<Position>> positions;
    int r = data.R, c = data.C, k = data.K;
    for (int o = 0; o < k; o++) {
        string pattern = data.patterns[o];
        vector<int> bad, gs;
        badChar(pattern, bad);
        goodSuffix(pattern, gs);
        vector<Position> position;
        for (int i = 0; i < r; i++) {
            string text = "";
            for (int j = 0; j < c; j++) text += data.text[i][j];
            vector<Position> res = findPosRow(i, pattern, text, bad, gs);
            position.insert(position.end(), res.begin(), res.end());
        }
        for (int i = 0; i < c; i++) {
            string text = "";
            for (int j = 0; j < r; j++) text += data.text[j][i];
            vector<Position> res = findPosCol(i, pattern, text, bad, gs);
            position.insert(position.end(), res.begin(), res.end());
        }
        positions.push_back(position);
    }
    return positions;
}

std::vector<std::vector<Position>> boyerMoore(Data data, long long& comparisons) {
    vector<vector<Position>> positions;
    comparisons = 0;
    int r = data.R, c = data.C, k = data.K;
    for (int o = 0; o < k; o++) {
        string pattern = data.patterns[o];
        vector<int> bad, gs;
        badChar(pattern, bad);
        goodSuffix(pattern, gs);
        vector<Position> position;
        for (int i = 0; i < r; i++) {
            string text = "";
            for (int j = 0; j < c; j++) text += data.text[i][j];
            vector<Position> res = findPosRowComp(i, pattern, text, bad, gs, comparisons);
            position.insert(position.end(), res.begin(), res.end());
        }
        for (int i = 0; i < c; i++) {
            string text = "";
            for (int j = 0; j < r; j++) text += data.text[j][i];
            vector<Position> res = findPosColComp(i, pattern, text, bad, gs, comparisons);
            position.insert(position.end(), res.begin(), res.end());
        }
        positions.push_back(position);
    }
    return positions;
}