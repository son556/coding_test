#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<int> arr[100000], brr[100000];
int visited[100000], bisited[100000];
int n, m, x;
int a, b, u, v;
int cnt1, cnt2;

void goArr() {
    int ny, y;
    queue<int> que;
    visited[x - 1] = 1;
    que.push(x - 1);
    while (que.size()) {
        y = que.front();
        que.pop();
        for (int i = 0; i < arr[y].size(); i++) {
            ny = arr[y][i];
            if (visited[ny]) continue;
            visited[ny] = 1;
            cnt1++;
            que.push(ny);
        }
    }
}

void goBrr() {
    int ny, y;
    queue<int> que;
    bisited[x - 1] = 1;
    que.push(x - 1);
    while (que.size()) {
        y = que.front();
        que.pop();
        for (int i = 0; i < brr[y].size(); i++) {
            ny = brr[y][i];
            if (bisited[ny]) continue;
            bisited[ny] = 1;
            cnt2++;
            que.push(ny);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a - 1].push_back(b - 1);
        brr[b - 1].push_back(a - 1);
    }
    goArr();
    goBrr();
    u = 1 + cnt2;
    v = u + (n - 1 - cnt1 - cnt2);
    cout << u << ' ' << v << '\n';
}