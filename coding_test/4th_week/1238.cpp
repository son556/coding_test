#include "test.hpp"
// #include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr[1001];
int n, m, x;
int res;
int dist[1001];
int dist2[1001];
const int INF = 987654321;

void go(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    int here, offset, to, d;
    dist[st] = 0;
    pque.push({0, st});
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (dist[here] != offset) continue;
        for (int i = 0; i < arr[here].size(); i++) {
            tie(to, d) = arr[here][i];
            if (dist[to] > offset + d) {
                dist[to] = offset + d;
                pque.push({dist[to], to});
            }
        }
    }
}

void go2(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    fill(dist2, dist2 + 1001, INF);
    int here, offset, to, d;
    dist2[st] = 0;
    pque.push({0, st});
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (dist2[here] != offset) continue;
        for (int i = 0; i < arr[here].size(); i++) {
            tie(to, d) = arr[here][i];
            if (dist2[to] > offset + d) {
                dist2[to] = offset + d;
                pque.push({dist2[to], to});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }
    fill(dist, dist + 1001, INF);
    go(x);
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        go2(i);
        res = max(res, dist[i] + dist2[x]);
    }
    cout << res << '\n';
}