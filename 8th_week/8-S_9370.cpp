#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int T, n, m, t, s, g, h, a, b, d;
int num;
int dist1[2001], dist2[2001], dist3[2001];
vector<int> candi, res;
vector<pair<int, int>> arr[2001];

void go(int st) {
    int here, offset, to, d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push({0, st});
    dist1[st] = 0;
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (dist1[here] != offset) continue;
        for (int i = 0; i < arr[here].size(); i++) {
            tie(d, to) = arr[here][i];
            if (dist1[to] > offset + d) {
                dist1[to] = offset + d;
                pque.push({offset + d, to});
            }
        }
    }
}

void go1(int st, int off, int dir) {
    int here, offset, to, d;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push({off, st});
    if (dir == 0)
        dist2[st] = off;
    else
        dist3[st] = off;
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (dir == 0 && dist2[here] != offset) continue;
        if (dir && dist3[here] != offset) continue;
        for (int i = 0; i < arr[here].size(); i++) {
            tie(d, to) = arr[here][i];
            if (dir == 0 && dist2[to] > offset + d) {
                dist2[to] = offset + d;
                pque.push({dist2[to], to});
            }
            if (dir && dist3[to] > offset + d) {
                dist3[to] = offset + d;
                pque.push({dist3[to], to});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int td;
    while (T) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        candi.clear();
        for (int i = 0; i < 2001; i++)
            arr[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            arr[a].push_back({d, b});
            arr[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g))
                td = d;
        }
        for (int i = 0; i < t; i++) {
            cin >> num;
            candi.push_back(num);
        }
        fill(dist1, dist1 + 2001, INF);
        fill(dist2, dist2 + 2001, INF);
        fill(dist3, dist3 + 2001, INF);
        go(s);
        go1(g, dist1[h] + td, 0);
        go1(h, dist1[g] + td, 1);
        res.clear();
        for (int i = 0; i < t; i++) {
            if (dist1[candi[i]] == dist2[candi[i]] || dist1[candi[i]] == dist3[candi[i]]) {
                if (dist1[candi[i]] != INF)
                    res.push_back(candi[i]);
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            if (i != res.size() - 1)
                cout << res[i] << ' ';
            else
                cout << res[i] << '\n';
        }
        T--;
    }
}





// 다음 2-N_9012