#include "test.hpp"
// 11658
/*
알고리즘 (자료구조) 
    펜윅트리로 2차원 배열의 값을 누적하여 완성시킴
    구하는 구간 = 전체 구간 - 구하지 않는 구간


입력 10억 까지 -> int 범위 내
*/

// #include <bits/stdc++.h>

using namespace std;

int tree[1025][1025];
int arr[1025][1025];
int n, m;

void update(int y, int x, int diff) {
    while (y <= n) {
        int j = x;
        while (j <= n) {
            tree[y][j] += diff;
            j += (j & -j);
        }
        y += (y & -y);
    }
}

int sum(int y, int x) {
    int total = 0;
    while (y > 0) {
        int j = x;
        while (j > 0) {
            total += tree[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return total;
}

int query(int sy, int sx, int ey, int ex) {
    int res = sum(ey, ex) - sum(ey, sx - 1) - sum(sy - 1, ex) + sum(sy - 1, sx - 1);
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        if (w == 0) {
            int x, y, c;
            int diff;
            cin >> y >> x >> c;
            diff = c - arr[y][x];
            update(y, x, diff);
            arr[y][x] = c;
        }
        else {
            int sx, sy, ey, ex;
            cin >> sy >> sx >> ey >> ex;
            cout << query(sy, sx, ey, ex) << '\n';
        }
    }
}
