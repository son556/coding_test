#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll x, y, z, res = INT_MAX;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z = y * 100 / x;
    ll s = 1, e = x, m;
    ll tmp;
    if (y == x) {
        cout << -1 << endl;
        return 0;
    }
    while (s <= e) {
        m = (s + e) / 2;
        tmp = (m + y) * 100 / (m + x);
        if (tmp != z) {
            res = min(res, m);
            e = m - 1;
        }
        else s = m + 1;
    }
    if (res == INT_MAX) res = -1;
    cout << res << endl;
}