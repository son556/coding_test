#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<int> ga, se;
int gar[4] = {0, 0, 0, 0};
int ser[4] = {0, 0, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int n, m, x, y, k;
int arr[20][20];

void moveS() {
    rotate(se.begin(), se.begin() + 1, se.end());
    ga[3] = se[3];
    ga[1] = se[1];
}

void moveN() {
    rotate(se.begin(), se.end() - 1, se.end());
    ga[3] = se[3];
    ga[1] = se[1];
}

void moveE() {
    rotate(ga.begin(), ga.end() - 1, ga.end());
    se[3] = ga[3];
    se[1] = ga[1];
}

void moveW() {
    rotate(ga.begin(), ga.begin() + 1, ga.end());
    se[3] = ga[3];
    se[1] = ga[1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 4; i++) {
        ga.push_back(gar[i]);
        se.push_back(ser[i]);
    }
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int cmd, ny, nx;
    for (int i = 0; i < k; i++) {
        cin >> cmd;
        nx = x + dy[cmd - 1];
        ny = y + dx[cmd - 1];
        if (nx >= n || nx < 0 || ny >= m || ny < 0)
            continue;
        if (cmd == 1)
            moveE();
        else if (cmd == 2)
            moveW();
        else if (cmd == 3)
            moveN();
        else
            moveS();
        if (arr[nx][ny] == 0) {
            arr[nx][ny] = ga[3];
        }
        else {
            ga[3] = arr[nx][ny];
            se[3] = arr[nx][ny];
            arr[nx][ny] = 0;
        }
        cout << ga[1] << '\n';
        x = nx;
        y = ny;
    }
}