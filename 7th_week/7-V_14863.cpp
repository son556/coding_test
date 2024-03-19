#include "test.hpp"
// 보통 배열의 크기가 1000만정도 되면 잘 안되지만 생각나는게 없다면 시도해볼것
// #include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[101][100001][2];
vector<pair<pair<int, int>, pair<int, int>>> spot;

int go(int start, int dir, int time) {
    if (start == n) {
        if (time > k) return -1e9;
        return 0;
    }
    if (time > k) return -1e9;
    int &ret = dp[start][time][dir];
    if (ret != -1) return ret;
    ret = max(go(start + 1, 0, time + spot[start].first.first) + spot[start].first.second, \
        go(start + 1, 1, time + spot[start].second.first) + spot[start].second.second);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int w, x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> w >> x >> y >> z;
        spot.push_back({{w, x}, {y, z}});
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0) << endl;
}
