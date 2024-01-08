#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000004];
vector<int> road;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second < p2.second;
}

void makeroad(int x) {
    if (x == 1) return;
    vector<pair<int, int>> b;
    if (x % 3 == 0) b.push_back({x / 3, dp[x / 3]});
    if (x % 2 == 0) b.push_back({x / 2, dp[x / 2]});
    b.push_back({x - 1, dp[x - 1]});
    sort (b.begin(), b.end(), cmp);
    road.push_back(b[0].first);
    makeroad(b[0].first);
}

int go(int x) {
    if (x == 1) return 0;
    int &ret = dp[x];
    if (ret) return ret;
    ret = 1e9;
    if (x % 3 == 0)
        ret = min(ret, go(x / 3) + 1);
    if (x % 2 == 0)
        ret = min(ret, go(x / 2) + 1);
    ret = min(ret, go(x - 1) + 1);
    return ret;
}

int main(void) {
    cin >> n;
    cout << go(n) << endl;
    road.push_back(n);
    makeroad(n);
    for (int i = 0; i < road.size(); i++) cout << road[i] << ' ';
    cout << endl;
}