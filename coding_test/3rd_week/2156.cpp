// 2156

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10000][3];
vector<int> po;

int go(int idx, int cnt) {
    if (idx == n)
        return 0;
    int &ret = dp[idx][cnt];
    if (ret != -1) return ret;
    if (cnt < 2)
        ret = max(go(idx + 1, cnt + 1) + po[idx], go(idx + 1, 0));
    else
        ret = max(ret, go(idx + 1, 0));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        po.push_back(num);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
}