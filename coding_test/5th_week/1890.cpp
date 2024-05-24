#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dy[2] = {0, 1};
ll dx[2] = {1, 0};
int n;
ll dp[100][100];
ll arr[100][100];

ll go(int y, int x) {
    if (y == n - 1 && x == n - 1)
        return 1;
    ll &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i] * arr[y][x];
        int nx = x + dx[i] * arr[y][x];
        if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        ret += go(ny, nx);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
}