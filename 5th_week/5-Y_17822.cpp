#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m, t, cnt;
vector<vector<int> > disk;
vector<vector<int> > rotVec;
int visited[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << disk[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void rotateDisk(int num, int r, int c) {
    if (r == 0)
        rotate(disk[num].begin(), disk[num].end() - c, disk[num].end());
    else
        rotate(disk[num].begin(), disk[num].begin() + c, disk[num].end());
}

void dfs(int y, int x, int start) {
    int ny, nx;

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny >= n || ny < 0) continue;
        if (nx == m) nx = 0;
        else if (nx == -1) nx = m - 1;
        if (disk[ny][nx] != start) continue;
        disk[ny][nx] = 0;
        cnt++;
        dfs(ny, nx, start);
    }
}

void makeDisk() {
    float res = 0, factors = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (disk[i][j] == 0) continue;
            res += disk[i][j];
            factors++;
        }
    }
    res /= factors;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (disk[i][j] == 0) continue;
            if (float(disk[i][j]) < res) disk[i][j] += 1;
            else if (float(disk[i][j]) > res) disk[i][j] -= 1;
        }
    }
}

void eraseDisk() {
    int sw = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (disk[i][j] == 0) continue;
            cnt = 0;
            dfs(i, j, disk[i][j]);
            if (cnt) disk[i][j] = 0;
            sw += cnt;
        }
    }
    if (sw == 0) makeDisk();
}

void checkDisk() {
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (disk[i][j]) cnt += disk[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    vector<int> b;
    int x;
    for (int i = 0; i < n; i++) {
        b.clear();
        for (int j = 0; j < m; j++) {
            cin >> x;
            b.push_back(x);
        }
        disk.push_back(b);
    }
    for (int i = 0; i < t; i++) {
        b.clear();
        for (int j = 0; j < 3; j++) {
            cin >> x;
            b.push_back(x);
        }
        rotVec.push_back(b);
    }
    int idx, bias;
    for (int i = 0; i < rotVec.size(); i++) {
        bias = 1;
        idx = rotVec[i][0];
        while (1)
        {
            idx = rotVec[i][0] * bias;
            if (idx > n) break;
            rotateDisk(idx - 1, rotVec[i][1], rotVec[i][2]);
            bias++;
        }
        eraseDisk();
    }
    checkDisk();
    cout << cnt << endl;
}
