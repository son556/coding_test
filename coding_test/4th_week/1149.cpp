#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int dp[1000][3];
int n, arr[1000][3];

int go(int idx, int num) {
    if (idx == n) {
        return 0;
    }
    int &ret = dp[idx][num];
    if (ret != INF) return ret;
    for (int i = 0; i < 3; i++) {
        if (num == i && idx) continue;
        ret = min(ret, go(idx + 1, i) + arr[idx][i]);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    fill(&dp[0][0], &dp[0][0] + 1000 * 3, INF);
    cout << go(0, 0) << '\n';
}