#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> cards, dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int p;
    cards.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> p;
        cards.push_back(p);
        dp.push_back(0);
    }
    dp.push_back(0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
        }
    }
    cout << dp[n] << endl;
}