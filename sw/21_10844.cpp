#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[101][10];
ll n, divn = 1e9;
ll go(ll x, ll depth) {
    if (x < 0 || x > 9) return 0;
    if (depth == 0) return 1;
    ll &ret = dp[depth][x];
    if (ret) return ret;
    if (x == 0)
        ret = go(x + 1, depth - 1);
    else if (x == 9)
        ret = go(x - 1, depth - 1);
    else
        ret = (go(x + 1, depth - 1) + go(x - 1, depth - 1)) % divn;
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    cin >> n;
    for (int i = 1; i < 10; i++) go(i, n);
    ll answer = 0;
    for (int i = 0; i < 10; i++) answer = (answer + dp[n][i]) % divn;
    if (n == 1) answer = 9;
    cout << answer % divn << endl;
}