#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int dp[200][200];
int vi[200][200];
int n, m, a, b, c;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0], &dp[0][0] + 200 * 200, INF);
    for (int i = 0; i < 200; i++)
        dp[i][i] = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++)
            vi[i][j] = j;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dp[a - 1][b - 1] = c;
        dp[b - 1][a - 1] = c;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dp[j][k] > dp[j][i] + dp[i][k]) {
                    dp[j][k] = dp[j][i] + dp[i][k];
                    vi[j][k] = vi[j][i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || dp[i][j] == INF) {
                if (j == n - 1)
                    cout << '-' << '\n';
                else
                    cout << '-' << ' ';
            }
            else {
                if (j == n - 1)
                    cout << vi[i][j] + 1 << '\n';
                else
                    cout << vi[i][j] + 1 << ' ';
            }
        }
    }
}