#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100][100], visited[100][100], cnt[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j])
                return false;
        }
    }
    return true;
}

void resetArr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cnt[i][j] >= 2)
                arr[i][j] = 0;
        }
    }
}

void bfs() {
    queue<pair<int, int>> que;
    visited[0][0] = 1;
    int y, x, ny, nx;
    que.push({0, 0});
    while (que.size()) {
        tie(y, x) = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] == 1) {
                cnt[ny][nx]++;
                continue;
            }
            visited[ny][nx] = 1;
            que.push({ny, nx});
        }
    }
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int t = 0;
    if (check()) {
        cout << 0 << '\n';
        return 0;
    }
    while (1) {
        t++;
        memset(visited, 0, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));
        bfs();
        resetArr();
        if (check())
            break;
    }
    cout << t << '\n';
}