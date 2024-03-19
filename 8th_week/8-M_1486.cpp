#include "test.hpp"

/*
초기화를 잘못함 
다익스트라와 플로이드 와샬 2가지로 풀 수 있음
*/

//#include <bits/stdc++.h>

// 다익스트라 풀이

using namespace std;

vector<pair<pair<int, int>, int>> vec;
string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
map<char, int> book;
int n, m, t, di;
int arr[25][25], visited[25][25];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go() {
    int ny, nx, hy, hx, d;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
    visited[0][0] = 0;
    pque.push({0, {0, 0}});
    while (pque.size()) {
        hy = pque.top().second.first;
        hx = pque.top().second.second;
        d = pque.top().first;
        pque.pop();
        if (visited[hy][hx] != d) continue;
        for (int i = 0; i < 4; i++) {
            ny = hy + dy[i];
            nx = hx + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            int diff = arr[ny][nx] - arr[hy][hx];
            if (diff < -t || diff > t) continue;
            if (diff <= 0) diff = 1;
            else diff = diff * diff;
            if (visited[ny][nx] > d + diff) {
                visited[ny][nx] = d + diff;
                pque.push({d + diff, {ny, nx}});
            }
        }
    }
}

bool cmp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2) {
    return arr[p1.first.first][p1.first.second] > arr[p2.first.first][p2.first.second];
}

bool check(int y, int x, int diff) {
    int target = di - diff;
    int ny, nx, dist1, dist2;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
    visited[y][x] = 0;
    pque.push({0, {y, x}});
    while(pque.size()) {
        y = pque.top().second.first;
        x = pque.top().second.second;
        dist1 = pque.top().first;
        pque.pop();
        if (visited[y][x] != dist1) continue;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            dist2 = arr[ny][nx] - arr[y][x];
            if (dist2 > t || dist2 < -t) continue;
            if (dist2 <= 0) dist2 = 1;
            else dist2 = dist2 * dist2;
            if (dist2 + dist1 > target) continue;
            if (visited[ny][nx] > dist1 + dist2) {
                visited[ny][nx] = dist1 + dist2;
                pque.push({visited[ny][nx], {ny, nx}});
            }
        }
    }
    if (visited[0][0] != INT_MAX) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < str.size(); i++)
        book[str[i]] = i;
    cin >> n >> m >> t >> di;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            arr[i][j] = book[str[j]];
    }
    fill(&visited[0][0], &visited[0][0] + 25 * 25, INT_MAX);
    go();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] < di && (i || j))
                vec.push_back({{i, j}, visited[i][j]});
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    int res = arr[0][0];
    for (int i = 0; i < vec.size(); i++) {
        fill(&visited[0][0], &visited[0][0] + 25 * 25, INT_MAX);
        if (check(vec[i].first.first, vec[i].first.second, vec[i].second)) {
            if (res < arr[vec[i].first.first][vec[i].first.second])
                res = arr[vec[i].first.first][vec[i].first.second];
        }
    }
    cout << res << '\n';
}

// 다음 2-G_2910