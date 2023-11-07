#include "test.hpp"

//#include<bits/stdc++.h>
// 모듈러 연산은 0부터 시작하는 것이 좋다.
// 0 -> 1 => 00 ^ 01 1 -> 0 => 01 ^ 01
// 2 -> 3 => 10 ^ 01 3 -> 2 => 11 ^ 01
using namespace std;

int r, c, m, x, y, s, d, z;
vector<vector<int> > maps, sharks;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int box;

void display() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << maps[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void moveShark(int idx) {
    int speed = sharks[idx][0];
    int dir = sharks[idx][1];
    int ny = sharks[idx][3];
    int nx = sharks[idx][4];

    if (dir == 0) {
        nx = speed - ny;
        if (nx < 0) ny = sharks[idx][3] + dy[dir] * speed;
        else {
            if (nx / (r - 1)) {
                if (nx / (r - 1) % 2){
                    ny = r - 1 - nx % (r - 1);
                    dir = 0;
                }
                else {
                    ny = nx % (r - 1);
                    dir = 1;
                }
            }
            else {
                ny = nx % (r - 1);
                dir = 1;
            }
        }
        if (ny == 0) dir = 1;
        else if (ny == r - 1) dir = 0;
        nx = sharks[idx][4];
    }
    else if (dir == 1) {
        nx = speed - (r - 1 - ny);
        if (nx < 0) ny = sharks[idx][3] + dy[dir] * speed;
        else {
            if (nx / (r - 1)) {
                if (nx / (r - 1) % 2) {
                    ny = nx % (r - 1);
                    dir = 1;
                }
                else {
                    ny = r - 1 - nx % (r - 1);
                    dir = 0;
                }
            }
            else {
                ny = r - 1 - nx % (r - 1);
                dir = 0;
            }
        }
        if (ny == 0) dir = 1;
        else if (ny == r - 1) dir = 0;
        nx = sharks[idx][4];
    }
    else if (dir == 2) {
        ny = speed - (c - 1 - nx);
        if (ny < 0) nx = sharks[idx][4] + dx[dir] * speed;
        else {
            if (ny / (c - 1)) {
                if (ny / (c - 1) % 2) {
                    dir = 2;
                    nx = ny % (c - 1);
                }
                else {
                    nx = c - 1 - ny % (c - 1);
                    dir = 3;
                }
            }
            else {
                nx = c - 1 - ny % (c - 1);
                dir = 3;
            }
        }
        if (nx == 0) dir = 2;
        else if (nx == c - 1) dir = 3;
        ny = sharks[idx][3];
    }
    else if (dir == 3) {
        ny = speed - nx;
        if (ny < 0) nx = sharks[idx][4] + dx[dir] * speed;
        else {
            if (ny / (c - 1)) {
                if (ny / (c - 1) % 2) {
                    dir = 3;
                    nx = c - 1 - ny % (c - 1);
                }
                else {
                    nx = ny % (c - 1);
                    dir = 2;
                }
            }
            else {
                nx = ny % (c - 1);
                dir = 2;
            }
        }
        if (nx == 0) dir = 2;
        else if (nx == c - 1) dir = 3;
        ny = sharks[idx][3];
    }
    sharks[idx][1] = dir;
    sharks[idx][3] = ny;
    sharks[idx][4] = nx;
}

void drawSharks() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            maps[i][j] = -1;
    }
    int idx;
    for (int i = 0; i < sharks.size(); i++) {
        if (sharks[i][0] == -1) continue;
        idx = maps[sharks[i][3]][sharks[i][4]];
        if (idx != -1) {
            if (sharks[idx][2] > sharks[i][2]) sharks[i][0] = -1;
            else {
                sharks[idx][0] = -1;
                maps[sharks[i][3]][sharks[i][4]] = i;
            }
        }
        else
            maps[sharks[i][3]][sharks[i][4]] = i;
    }
}

void catchShark(int x) {
    for (int i = 0; i < r; i++) {
        if (maps[i][x] != -1) {
            box += sharks[maps[i][x]][2];
            sharks[maps[i][x]][0] = -1;
            maps[i][x] = -1;
            return ;
        }
    }
}

void fishingStart() {
    int fishMan = 0;

    while (fishMan < c) {
        catchShark(fishMan);
        for (int i = 0; i < sharks.size(); i++) {
            if (sharks[i][0] == -1) continue;
            moveShark(i);
        }
        drawSharks();
        fishMan++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> m;
    if (m == 0) {
        cout << box << endl;
        return 0;
    }
    vector<int> b;
    for (int i = 0; i < r; i++) {
        b.clear();
        for (int j = 0; j < c; j++)
            b.push_back(-1);
        maps.push_back(b);
    }
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> s >> d >> z;
        b.clear();
        maps[y - 1][x - 1] = i;
        b.push_back(s);
        b.push_back(d - 1);
        b.push_back(z);
        b.push_back(y - 1);
        b.push_back(x - 1);
        sharks.push_back(b);
    }
    fishingStart();
    cout << box << endl;
}