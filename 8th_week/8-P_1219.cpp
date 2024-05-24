#include "test.hpp"

/*
알고리즘 벨만포드

시간복잡도 O(VE) -> 2500

내가 도착한 지점이 사이클에 포함되어있는지 확인 -> n번째에 갱신되는 정점을 큐에 넣고 bfs로 탐색하여 확인
*/

//#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const ll INF = 2*1e18;
ll n, sc, dc, m;
vector<pair<ll, ll>> arr[50];
ll pay[50];
ll dist[50];
int visited[50];

bool check(queue<ll> &que) {
    int st, next;
    visited[que.front()] = 1;
    while (que.size()) {
        st = que.front();
        que.pop();
        if (st == dc) return true;
        for (int i = 0; i < arr[st].size(); i++) {
            next = arr[st][i].first;
            if (visited[next]) continue;
            visited[next] = 1;
            que.push(next);
        }
    }
    return false;
}

ll belman() {
    fill(dist, dist + 50, INF);
    queue<ll> que;
    dist[sc] = -pay[sc];
    ll flag;
    for (ll i = 0; i < n; i++) {
        for (ll here = 0; here < n; here++) {
            for (auto there : arr[here]) {
                ll to = there.first;
                ll d = there.second - pay[to];
                if (dist[here] != INF && dist[here] + d < dist[to]) {
                    dist[to] = dist[here] + d;
                    if (i == n - 1)
                        que.push(to);
                }
            }
        }
    }
    if (dist[dc] == INF)
        return -1;
    if (que.size() && check(que))
        return 1;
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> sc >> dc >> m;
    ll s, e, p;
    for (ll i = 0; i < m; i++) {
        cin >> s >> e >> p;
        arr[s].push_back({e, p});
    }
    for (ll i = 0; i < n; i++)
        cin >> pay[i];
    ll flag = belman();
    if (flag == -1)
        cout << "gg" << '\n';
    else if (flag == 1)
        cout << "Gee" << '\n';
    else
        cout << -dist[dc] << '\n';
}


/*
5 0 4 5
0 1 0
1 2 0
2 3 0
3 1 0
0 4 0
1 1 1 1 1

답: 2

4 0 3 4
0 1 0
0 3 5
1 2 0
2 1 0
0 5 5 10

ans: 5

*/

