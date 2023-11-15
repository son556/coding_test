#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll hi, low, mid, res = 1e18;
vector<int> jew;

bool check(ll mid) {
    int num = 0;
    for (int i = 0; i < jew.size(); i++) {
        num += jew[i] / mid;
        if (jew[i] % mid) num++;
    }
    return (n >= num);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        hi = max(ll(x), hi);
        jew.push_back(x);
    }
    low = 1;
    while (low <= hi) {
        mid = (hi + low) / 2;
        if (check(mid)) {
            res = min(res, mid);
            hi = mid - 1;
        }
        else low = mid + 1;
    }
    cout << res << endl;
    return 0;
}