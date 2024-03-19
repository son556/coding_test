#include "test.hpp"
// 1926
/*
알고리즘 bfs
*/

//#include <bits/stdc++.h> 

using namespace std;

int n, m;
int arr[501][501], visited[501][501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> vec;

void go(int y, int x) {
    queue<pair<int, int>> que;
    int ny, nx;
    int total = 1;
    visited[y][x] = 1;
    que.push({y, x});
    while (que.size()) {
        y = que.front().first;
        x = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (visited[ny][nx] || arr[ny][nx] == 0) continue;
            visited[ny][nx] = 1;
            total++;
            que.push({ny, nx});
        } 
    }
    vec.push_back(total);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && visited[i][j] == 0) {
                cnt++;
                go(i, j);
            }
        }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    cout << cnt << '\n';
    if (cnt)
        cout << vec[0] << '\n';
    else
        cout << 0 << '\n';
}



