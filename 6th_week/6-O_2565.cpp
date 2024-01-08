#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> res;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pair<int, int> p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end(), cmp);
    res.push_back(arr[0].second);
    int idx;
    for (int i = 0; i < arr.size(); i++) {
        idx = lower_bound(res.begin(), res.end(), arr[i].second) - res.begin();
        if (idx == res.size()) res.push_back(arr[i].second);
        else res[idx] = arr[i].second;
    }
    cout << n - res.size() << endl;
}