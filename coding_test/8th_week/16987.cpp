#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n;
int check[8];
int res;
vector<pair<int, int>> eggs;

void go(int idx, int cnt) {
    if (idx == n) {
        if (cnt > res)
            res = cnt;
        return;
    }
    int index;
    for (int i = 0; i < n; i++) {
        if (check[i] <= 0) continue;
        if (i == idx) continue;
        check[idx] -= eggs[i].second;
        check[i] -= eggs[idx].second;
        index = idx + 1;
        while (index < n) {
            if (check[index] > 0) break;
            index++;
        }
        if (check[idx] <= 0 && check[i] <= 0)
            go(index, cnt + 2);
        else if (check[idx] <= 0 || check[i] <= 0)
            go(index, cnt + 1);
        else
            go(index, cnt);
        check[idx] += eggs[i].second;
        check[i] += eggs[idx].second;
    }
    res = max(res, cnt);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int s, w;
    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        eggs.push_back({s, w});
        check[i] = s;
    }
    go(0, 0);
    cout << res << '\n';
}