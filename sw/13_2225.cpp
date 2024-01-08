#include "test.hpp"
// #include <bits/stdc++.h> 
using namespace std;

int n, k, div_n = 1000000000;
vector<vector<int>> dp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    vector<int> a;
    int tmp;
    for (int i = 0; i <= n; i++) a.push_back(0);
    for (int i = 0; i <= k; i++) dp.push_back(a);
    for (int i = 0; i <=n; i++) dp[1][i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            tmp = 0;
            for (int x = 0; x <= j; x++) {
                tmp = (tmp + dp[i - 1][x]) % div_n;
            }
            dp[i][j] = tmp;
        }
    }
    cout << dp[k][n] << endl;
}