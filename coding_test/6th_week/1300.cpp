#include "test.hpp"

#include "test.hpp"

//#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
ll num = 1e10;

ll n, k;
ll res;

ll cntNum(ll nu) {
    
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
        cnt += min(nu / i, n);
    return cnt;
}

void findNum() {
    ll st = 1;
    ll ed = num;
    while (st <= ed) {
        ll mid = (st + ed) / 2;
        if (cntNum(mid) >= k) {
            res = mid;
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    findNum();
    cout << res << '\n';
}
