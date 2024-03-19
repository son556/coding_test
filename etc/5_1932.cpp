#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<vector<int>> arr, dp;

void makeDp() {
    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (j == 0) dp[i][0] = dp[i - 1][0] + arr[i][0];
            else if (j == dp[i].size() - 1) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    vector<int> b, c;
    for (int i = 0; i < n; i++) {
        b.clear();
        c.clear();
        for (int j = 0; j < i + 1; j++) {
            cin >> x;
            b.push_back(x);
            c.push_back(0);
        }
        arr.push_back(b);
        dp.push_back(c);
    }
    makeDp();
    int res = -1;
    for (int i = 0; i < dp[n - 1].size(); i++) {
        if (res < dp[n - 1][i]) res = dp[n - 1][i];
    }
    cout << res << endl;
}