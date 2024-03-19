#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int visited[14][14];

bool check(int y, int x) {
    int nx, ny;
    for (int i = 0; i < n; i++) {
        if (i == y) continue;
        if (visited[i][x]) return false;
    }
    for (int i = 1; i < n; i++) {
        ny = y - i;
        nx = x - i;
        if (ny >= 0 && nx >= 0) {
            if (visited[ny][nx]) return false;
        }
        ny = y + i;
        nx = x + i;
        if (ny < n && nx < n) {
            if (visited[ny][nx]) return false;
        }
    }
    for (int i = 1; i < n; i++) {
        ny = y - i;
        nx = x + i;
        if (ny >=0 && nx < n) {
            if (visited[ny][nx]) return false;
        }
        ny = y + i;
        nx = x - i;
        if (ny < n && nx >= 0) {
            if (visited[ny][nx]) return false;
        }
    }
    return true;
}

void go(int depth) {
    if (depth == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(depth, i) == false) continue;
        visited[depth][i] = 1;
        go(depth + 1);
        visited[depth][i] = 0;
    }
}

int main() {
    cin >> n;
    go(0);
    cout << cnt << endl;
}