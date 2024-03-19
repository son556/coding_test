// 8-A_2618

#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n, m, total;
vector<pair<int, int>> incidents;
stack<int> res, enp;
int min_dis, flag;
int dp[1002][1002];
vector<int> answer;

int dist(pair<int, int> &p1, pair<int, int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int go(int idx1, int idx2) {
    int nidx = max(idx1, idx2) + 1;
    if (nidx == incidents.size()) {
        return 0;
    }
    int &ret = dp[idx1][idx2];
    if (ret) return ret;
    ret = min(go(nidx, idx2) + dist(incidents[nidx], incidents[idx1]), go(idx1, nidx) + dist(incidents[nidx], incidents[idx2]));
    return ret;
}

void findLoad() {
    int sx, sy, next, diff, depth;
    pair<pair<int, int>, pair<int, int>> here, there;
    queue<pair<int, int>> que;
    que.push({0, 1});
    while (que.size()) {
        sx = que.front().first;
        sy = que.front().second;
        que.pop();
        here = {incidents[sx], incidents[sy]};
        if (sx > sy)
            next = sx + 1;
        else
            next = sy + 1;
        
        if (next >= incidents.size())
            continue;
        diff = dist(here.first, incidents[next]);
        if (dp[sx][sy] - diff == dp[next][sy])
        {
            que.push({next, sy});
            answer.push_back(1);
            continue;
        }
        diff = dist(here.second, incidents[next]);
        if (dp[sx][sy] - diff == dp[sx][next])
        {
            que.push({sx, next});
            answer.push_back(2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    pair<int, int> c;
    incidents.push_back({1, 1});
    incidents.push_back({n, n});
    for (int i = 0; i < m; i++) {
        cin >> c.first >> c.second;
        incidents.push_back(c);
    }
    cout << go(0, 1) << '\n';
	findLoad();
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}
