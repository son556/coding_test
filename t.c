#include <bits/stdc++.h>
using namespace std;
int a[505], psum[505], dp[505][505];


int go(int s, int e) {
    if (s >= e) return 0;
    int& ret = dp[s][e];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int m = s; m <= e; m++) {
        ret = min(ret, go(s, m) + go(m + 1, e) + psum[e] - psum[s - 1]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << go(1, n) << '\n';
    }
}