#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<int> res;
vector<pair<int, int>> arr;
int n, max_idx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back({x, 0});
    }
    res.push_back(arr[0].first);
    for (int i = 1; i < n; i++) {
        x = lower_bound(res.begin(), res.end(), arr[i].first) - res.begin();
        if (x == res.size()) {
            arr[i].second = res.size();
            res.push_back(arr[i].first);
            max_idx = max(max_idx, arr[i].second);
        }
        else {
            res[x] = arr[i].first;
            arr[i].second = x;
        }
    }
    cout << res.size() << endl;
    res.clear();
    for (int i = arr.size() - 1; i > -1; i--) {
        if (arr[i].second == max_idx) {
            res.push_back(arr[i].first);
            max_idx--;
        }
        if (max_idx < 0) break;
    }
    for (int i = res.size() - 1; i > -1; i--)
        cout << res[i] << ' ';
    cout << endl;
}