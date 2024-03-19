#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int su, si;
int visited[200005];

void go(int n) {
    queue<pair<int, int>> q;
    int nx, cnt, ncnt;
    q.push({n, 0});
    visited[n] = 1;
    while (q.size()) {
        tie(n, cnt) = q.front();
        q.pop();
        if (n == si) {
            cout << cnt;
            return;
        }
        nx = n - 1;
        ncnt = cnt + 1;
        if (nx > -1 && visited[nx] == 0) {
            q.push({nx, ncnt});
            visited[nx] = 1;
        }
        nx = n + 1;
        if (nx < 200005 && visited[nx] == 0) {
            q.push({nx, ncnt});
            visited[nx] = 1;
        }
        nx = 2 * n;
        if (nx < 200005 && visited[nx] == 0) {
            q.push({nx, ncnt});
            visited[nx] = 1;
        }
    }
}

int main(void) {
    cin >> su >> si;
    go(su);
}