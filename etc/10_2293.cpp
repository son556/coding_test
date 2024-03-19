#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int dp[10004];
vector<int> coins;
int n, k;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        coins.push_back(x);
    }
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++)
            dp[j] = dp[j] + dp[j - coins[i]];
    }
    cout << dp[k] << endl;
}