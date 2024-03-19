#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std; 
int n, div_n = 9901;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i <= n; i++) dp.push_back(0);
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] * 2) % div_n + dp[i - 2] % div_n;
    cout << dp[n] % div_n << endl;
}