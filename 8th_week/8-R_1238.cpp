#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int dist[1000], n, m, x;
int dist2[1000];
int s, e, p;
vector<pair<int, int>> arr[1000];
int res;

void go(int st, int flag) {
    int here, to, offset, d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    if (flag == 0)
        dist[st] = 0;
    else
        dist2[st] = 0;
    pque.push({0, st});
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (flag == 0 && dist[here] != offset) continue;
        else if (flag && dist2[here] != offset) continue;
        for (int i = 0; i < arr[here].size(); i++) {
            to = arr[here][i].first;
            d = arr[here][i].second;
            if (flag == 0 && dist[to] > offset + d) {
                dist[to] = offset + d;
                pque.push({offset + d, to});
            }
            else if (flag && dist2[to] > offset + d) {
                dist2[to] = offset + d;
                pque.push({offset + d, to});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    x--;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> p;
        arr[s - 1].push_back({e - 1, p});
    }
    fill(dist, dist + 1000, INF);
    go(x, 0);
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        fill(dist2, dist2 + 1000, INF);
        go(i, 1);
        if (res < dist2[x] + dist[i])
            res = dist2[x] + dist[i];
    }
    cout << res << '\n';
}

