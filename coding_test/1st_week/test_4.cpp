#include "test.hpp"
// 14503
/*
알고리즘 구현
    단순 구현 문제 문제를 꼼꼼히 읽자 -> 테두리는 모두 벽으로 되어있다.
    주변에 청소 할 곳이 있는경우 반 시계방향으로 회전
*/
//#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int r, c, d;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[50][50];

bool check(int y, int x) {
    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (arr[ny][nx] != 0) continue;
        return true;
    }
    return false;
}

void go() {
    int y, x, ny, nx, dir;
    y = r;
    x = c;
    dir = d;
    while(1) {
        if (arr[y][x] == 0) {
            arr[y][x] = -1;
            cnt++;
        }
        if (check(y, x) == false) {
            if (dir == 0) {
                ny = y + dy[2];
                nx = x + dx[2];
                if (arr[ny][nx] == 1) return;
                y = ny;
                x = nx;
            }
            else if (dir == 1) {
                ny = y + dy[3];
                nx = x + dx[3];
                if (arr[ny][nx] == 1) return;
                y = ny;
                x = nx;
            }
            else if (dir == 2) {
                ny = y + dy[0];
                nx = x + dx[0];
                if (arr[ny][nx] == 1) return;
                y = ny;
                x = nx;
            }
            else if (dir == 3) {
                ny = y + dy[1];
                nx = x + dx[1];
                if (arr[ny][nx] == 1) return;
                y = ny;
                x = nx;
            }
        }
        else {
            int idx = dir;
            for (int i = 0; i < 4; i++) {
                idx--;
                if (idx == -1)
                    idx = 3;
                ny = y + dy[idx];
                nx = x + dx[idx];
                if (arr[ny][nx] == 0) {
                    dir = idx;
                    y = ny;
                    x = nx;
                    break;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num;
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    go();
    cout << cnt << '\n';
}