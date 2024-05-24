#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<pair<int, int>> arr[100004];
int visited[100004];
int a, b, c;
int res;
priority_queue<int, vector<int>, less<int>> ans;

void go() {
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push({0, 1});
    int here, offset;
    while (pque.size()) {
        tie(offset, here) = pque.top();
        pque.pop();
        if (visited[here]) continue;
        visited[here] = 1;
        ans.push(offset);
        res += offset;
        for (int i = 0; i < arr[here].size(); i++) {
            if (visited[arr[here][i].second]) continue;
            pque.push(arr[here][i]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        arr[a].push_back({c, b});
        arr[b].push_back({c, a});
    }
    go();
    ans.pop();
    long long total = 0;
    while (ans.size()) {
        total += ans.top();
        ans.pop();
    }
    cout << total << endl;
}