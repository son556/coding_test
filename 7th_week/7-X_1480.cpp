//7-X_1480
//생각 순서: 1.완탐 -> 상태값 배열에 담을수 있다(-> DP) -> 다른 알고리즘
#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> jewl;
int dp[11][21][1 << 13];

int go(int idx, int weight, int status) {
    if (idx == m) return 0;
    int &ret = dp[idx][weight][status];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < jewl.size(); i++) {
        if (status & (1 << i) || weight + jewl[i] > k) continue;
        ret = max(ret, go(idx, weight + jewl[i], status | (1 << i)) + 1);
    }
    ret = max(ret, go(idx + 1, 0, status));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        jewl.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0);
}