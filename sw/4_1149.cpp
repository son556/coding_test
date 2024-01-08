#include "test.hpp"

//#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> home;
vector<vector<int>> dp;

void makeDp() {
    dp[0][0] = home[0][0];
    dp[0][1] = home[0][1];
    dp[0][2] = home[0][2];
    vector<int> b;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            b.clear();
            for (int k = 0; k < 3; k++) {
                if (k == j) continue;
                b.push_back(dp[i - 1][k]);
            }
            dp[i][j] = min(b[0], b[1]) + home[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x;
    vector<int> b, c;
    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    for (int i = 0; i < n; i++) {
        b.clear();
        for (int j = 0; j < 3; j++) {
            cin >> x;
            b.push_back(x);
        }
        home.push_back(b);
        dp.push_back(c);
    }
    makeDp();
    int res = INT_MAX;
    for (int i = 0; i < 3; i++) {
        if (res > dp[n - 1][i]) res = dp[n - 1][i];
    }
    cout << res << endl;
}