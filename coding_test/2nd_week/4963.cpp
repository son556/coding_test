#include "test.hpp"

// 4963

/*
알고리즘 bfs
*/

//#include <bits/stdc++.h>

using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int h, w;

int arr[50][50];
int visited[50][50];
int cnt;

void go(int y, int x) {
    int ny, nx;
    queue<pair<int, int>> que;
    visited[y][x] = 1;
    que.push({y, x});
    while (que.size()) {
        y = que.front().first;
        x = que.front().second;
        que.pop();
        for (int i = 0; i < 8; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= h || nx >= w || ny < 0 || nx < 0) continue;
            if (visited[ny][nx] || arr[ny][nx] == 0) continue;
            visited[ny][nx] = 1;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cin >> arr[i][j];
        }
        cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j] == 0 && arr[i][j]) {
                    cnt++;
                    go(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
}