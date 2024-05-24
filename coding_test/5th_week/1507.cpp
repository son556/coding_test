#include "test.hpp"

/*
다익스트라 최단경로를 다른 경로로 갈 수 있으면 st -> ed를 지워준다.
*/

/*
플로이드 워셜로 하면 쉬움
*/

//#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
int arr[20][20];
int dist[20];
vector<pair<pair<int, int>, int>> g[20];

int go(int st, int ed) {
    fill(&dist[0], &dist[0] + 20, INF);
    int here, offset, to, d;
    int stnd = arr[st][ed];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    dist[st] = 0;
    pque.push({0, st});
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (dist[here] != offset) continue;
        for (int i = 0; i < g[here].size(); i++) {
            if (g[here][i].second == 0) 
                continue;
            to = g[here][i].first.second;
            if ((here == st && to == ed) || (here == ed && to == st))
                d = INF;
            else
                d = g[here][i].first.first;
            if (dist[to] > d + offset) {
                dist[to] = d + offset;
                pque.push({d + offset, to});
            }
        }
    }
    if (dist[ed] == stnd) {
        for (int i = 0; i < g[st].size(); i++) {
            if (g[st][i].first.second == ed) {
                g[st][i].second = 0;
                break;
            }
        }
        for (int i = 0; i < g[ed].size(); i++) {
            if (g[ed][i].first.second == st) {
                g[ed][i].second = 0;
                break;
            }
        }
    }
    if (dist[ed] < stnd)
        return 1;
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) continue;
            g[i].push_back({{arr[i][j], j}, 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (go(i, j)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j].second) {
                res += g[i][j].first.first;
            }
        }
    }
    cout << res / 2 << '\n';
}