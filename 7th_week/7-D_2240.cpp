#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int t, w;
vector<int> jadu;
int dp[1000][31][2];

int go(int x, int mov, int idx) {
    if (mov > w) return -1e9;
    if (idx == t) return 0;
    int &ret = dp[idx][mov][x];
    if (ret != -1) return ret;
    ret = 0;
    if (jadu[idx] == x)
        ret = max(go(x^1, mov + 1, idx + 1), go(x, mov, idx + 1)) + 1;
    else
        ret = max(go(x^1, mov + 1, idx + 1), go(x, mov, idx + 1));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t >> w;
    int x;
    for (int i = 0; i < t; i++) {
        cin >> x;
        jadu.push_back(x - 1);
    }
    memset(dp, -1, sizeof(dp));
    int answer = go(0, 0, 0);
    memset(dp, -1, sizeof(dp));
    answer = max(answer, go(1, 1, 0));
    cout << answer << endl;
}