#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> arr;
int res[100000];
int offset[100000];
int n, m;
int st, num;

bool check() {
    memset(offset, 0, sizeof(offset));
    for (int i = 0; i < n; i++) {
        if (offset[res[i]]) return true;
        offset[res[i]] = 1;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        offset[i] = n - 1 - i;
    for (int i = 0; i < m; i++) {
        cin >> st >> num;
        offset[st - 1] -= 1;
        arr.push_back({st - 1, num - 1});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        res[i] = n - 1 - offset[i];
    for (int i = 0; i < m; i++)
        res[arr[i].second] -= 1;
    if (check())
        cout << -1 << '\n';
    else {
        for (int i = 0; i < n; i++)
            cout << res[i] + 1 << ' ';
        cout << '\n';
    }
}