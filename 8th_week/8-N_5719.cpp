#include "test.hpp"

// 8-N_5719

/*

알고리즘 다익스트라

경로를 역 추적하는 것이 어려웠다. <- end 부터 시작해서 bfs로 추적

시간복잡도 Elog(v) -> 9만 정도

*/

//#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

int n, m, s, d, u, v, p;
int arr[500][500];
int dist[500], visited[500][500];
vector<int> route[500];

void go() {
    fill(dist, dist + 500, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    int here, to, offset, dis;
    dist[s] = 0;
    pque.push({0, s});
    while (pque.size()) {
        here = pque.top().second;
        offset = pque.top().first;
        pque.pop();
        if (dist[here] != offset) continue;
        for (int i = 0; i < n; i++) {
            if (arr[here][i] == 0) continue;
            to = i;
            dis = arr[here][i];
            if (dist[to] > offset + dis && visited[here][to] == 0) {
                dist[to] = offset + dis;
                pque.push({dist[to], to});
            }
        }
    }
}

void eraseEdge() {
    queue<int> que;
    que.push(d);
    int des;
    while (que.size()) {
        des = que.front();
        que.pop();
        for (int i = 0; i < n; i++) {
            if (dist[des] == dist[i] + arr[i][des] && arr[i][des] && visited[i][des] == 0) {
                visited[i][des] = 1;
                que.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cin >> s >> d;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            arr[u][v] = p;
        }
        go();
        eraseEdge();
        go();
        if (dist[d] == MAX)
            cout << -1 << '\n';
        else
            cout << dist[d] << '\n';
    }
}

// 다음 2-J_10709