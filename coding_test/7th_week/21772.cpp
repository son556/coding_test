#include "test.hpp"
//#include <bits/stdc++.h>

using namespace std;
int r, c, t, sy, sx;
int arr[100][100];
int visited[100][100];
int res = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x, int cnt, int total) {
    if (cnt == t) {
        res = max(res, total);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= r || ny < 0 || nx >= c || nx < 0) continue;
        if (visited[ny][nx] || arr[ny][nx] == -1) continue;
        if (arr[ny][nx] == 1) {
            arr[ny][nx] = 0;
            go(ny, nx, cnt + 1, total + 1);
            arr[ny][nx] = 1;
        }
        else
            go(ny, nx, cnt + 1, total);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> t;
    string str;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'G') {
                sy = i;
                sx = j;
                arr[i][j] = 0;
            }
            else if (str[j] == 'S')
                arr[i][j] = 1;
            else if (str[j] == '#')
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
        }
    }
    go(sy, sx, 0, 0);
    cout << res << '\n';
}