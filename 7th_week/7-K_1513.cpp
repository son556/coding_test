//7-K 1513

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m, c, divn = 1000007;
int dp[51][51][51][51], target;
int game[51][51];

int go(int y, int x, int idx, int cnt) {
    if (y > n || x > m) {return 0;}
    if (y == n && x == m) {
        if (cnt == target && game[y][x] == 0) { return 1;}
        if (cnt == target - 1 && game[y][x] > idx) { return 1;}
        return 0;
    }
    int &ret = dp[y][x][idx][cnt];
    if (ret != -1) return ret;
    ret = 0;
    if (game[y][x] > idx)
        ret = (go(y + 1, x, game[y][x], cnt + 1) + go(y, x + 1, game[y][x], cnt + 1)) % divn;
    else if (game[y][x] == 0)
        ret = (go(y + 1, x, idx, cnt) + go(y, x + 1, idx, cnt)) % divn;
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    int x, y;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        game[y][x] = i;
    }
    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= c; i++) {
        target = i;
        memset(dp, -1, sizeof(dp));
        cout << go(1, 1, 0, 0) << ' ';
    }
}
