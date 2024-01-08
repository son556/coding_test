#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> maps;
int dp[16][16][3];

bool check(int y, int x, int d) {
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    if (d == 0 || d == 2) {
        if (maps[y][x] == 0) return true;
        return false;
    }
    if (maps[y][x] == 0 && maps[y - 1][x] == 0 && maps[y][x - 1] == 0) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[j];
        maps.push_back(b);
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }
    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << endl;
}