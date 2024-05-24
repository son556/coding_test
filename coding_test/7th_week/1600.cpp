#include "test.hpp"

//2-R_1068
//#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ddy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ddx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int k, w, h;
int arr[200][200];
int visited[200][200][31];
int answer = INF;

void go() {
    queue<pair<pair<int, int>, pair<int, int>>> que;
    int ny, nx, y, x, cnt, offset;
    que.push({{0, 0}, {0, 0}});
    visited[0][0][0] = 0;
    while (que.size()) {
        tie(offset, cnt) = que.front().second;
        tie(y, x) = que.front().first;
        que.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;
            if (arr[ny][nx] || offset + 1 >= visited[ny][nx][cnt]) continue;
            visited[ny][nx][cnt] = offset + 1;
            que.push({{ny, nx}, {offset + 1, cnt}});
        }
        if (cnt < k) {
            for (int i = 0; i < 8; i++) {
                ny = y + ddy[i];
                nx = x + ddx[i];
                if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;
                if (arr[ny][nx] || offset + 1 >= visited[ny][nx][cnt + 1]) continue;
                visited[ny][nx][cnt + 1] = offset + 1;
                que.push({{ny, nx}, {offset + 1, cnt + 1}});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> arr[i][j];
    }
    fill(&visited[0][0][0], &visited[0][0][0] + 200 * 200 * 31, INF);
    go();
    answer = INF;
    for (int i = 0; i <= k; i++)
        answer = min(answer, visited[h - 1][w - 1][i]);
    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
}
