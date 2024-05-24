// 빵집
#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int dy[3] = {-1, 0, 1};
int dx[3] = {1, 1, 1};
int n, m;
int arr[10000][500];
int visited[10000][500];
char c;
int res;
bool go(int y, int x) {
    visited[y][x] = 1;
    if (x == m - 1) {
        res++;
        return true;
    }
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if (arr[ny][nx] || visited[ny][nx]) continue;
        if (go(ny, nx))
            return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == 'x')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0)
            go(i, 0);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i][m - 1])
            cnt++;
    }
    cout << cnt << '\n';
}