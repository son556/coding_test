#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> vec;
int dp[504][504];

int calcur(int st, int mid, int ed) {
    pair<int, int> p1 = {vec[st].first, vec[mid - 1].second};
    pair<int, int> p2 = {vec[mid].first, vec[ed - 1].second};
    return p1.first * p1.second * p2.second;
}

int go(int st, int ed) {
    if (st + 2 == ed) {
        return vec[st].first * vec[st].second * vec[ed - 1].second;
    }
    if (ed - st == 1) return 0;
    int &ret = dp[st][ed];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i = st + 1; i < ed; i++) {
        ret = min(go(st, i) + go(i, ed) + calcur(st, i, ed), ret);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vec.push_back({x, y});
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, n) << endl;
}

/*
4
5 4
4 3
3 2
2 1

38
*/