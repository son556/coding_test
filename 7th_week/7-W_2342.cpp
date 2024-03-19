//7-W_2342

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int res;
pair<int, int> pos;
map<pair<int, int>, int> book;
vector<int> lo;
int dp[100001][5][5];

int go(int idx, int lf, int rf) {
    if (idx == lo.size()) return 0;
    int &ret = dp[idx][lf][rf];
    if (ret != -1) return ret;
    ret = 1e8;
    ret = min(ret, go(idx + 1, lo[idx], rf) + book[{lf, lo[idx]}]);
    ret = min(ret, go(idx + 1, lf, lo[idx]) + book[{rf, lo[idx]}]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pos = {0, 0};
    for (int i = 0; i < 5; i++) {
        book[{i, i}] = 1;
        if (i)
            book[{0, i}] = 2;
    }
    book[{1, 3}] = 4;
    book[{3, 1}] = 4;
    book[{2, 4}] = 4;
    book[{4, 2}] = 4;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (book.find({i, j}) != book.end()) continue;
            book[{i, j}] = 3;
        }
    }
    int x;
    while (1) {
        cin >> x;
        if (x == 0) break;
        lo.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) << endl;
}

