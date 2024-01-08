#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
int n, m, v;
vector<vector<int>> arr;
set<int> fa;
int visited[1003];

void goDFS(int st) {
    cout << st + 1 << ' ';
    for (int i = 0; i < arr[st].size(); i++) {
        if (visited[arr[st][i]]) continue;
        visited[arr[st][i]] = 1;
        goDFS(arr[st][i]);
    }
}

void goBFS(int st) {
    queue<int> q;
    q.push(st);
    while (q.size()) {
        st = q.front();
        cout << st + 1 << ' ';
        q.pop();
        for (int i = 0; i < arr[st].size(); i++) {
            if (visited[arr[st][i]]) continue;
            visited[arr[st][i]] = 1;
            q.push(arr[st][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> b;
    int x, y;
    cin >> n >> m >> v;
    for (int i = 0; i < n; i++) {
        arr.push_back(b);
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        fa.insert(x - 1);
        fa.insert(y - 1);
        arr[x - 1].push_back(y - 1);
        arr[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    visited[v - 1] = 1;
    goDFS(v - 1);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    visited[v - 1] = 1;
    goBFS(v - 1);
    cout << endl;
}