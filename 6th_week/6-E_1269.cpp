#include "test.hpp"

//#include <bits/stdc++.h>
// count -> map or array
using namespace std;

int n, m;
vector<int> a, b;
vector<int> res;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int j = 0; j < m; j++) {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (x == b.size() || b[x] != a[i]) res.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        x = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (x == a.size() || a[x] != b[i]) res.push_back(b[i]);
    }
    cout << res.size() << endl;
}