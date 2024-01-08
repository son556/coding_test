#include "test.hpp"

//#include <bits/stdc++.h>
// max 범위를 정할 때 범위 보다 3 ~ 4만큼 크게 주는 것이 좋다.
using namespace std;
typedef long long ll;
ll n, m, st, mid, en, res;
vector<ll> arr;

bool check(ll num) {
    ll total = 0;
    for (int i = 0; i < arr.size(); i++) {
        total += num / arr[i] + 1;
        if (total >= n) return true;
    }
    return false;
}

int findPosition(ll num) {
    ll total = 0;
    int idx;
    for (int i = 0; i < arr.size(); i++) {
        total += (num - 1) / arr[i] + 1;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (num % arr[i] == 0) {
            total++;
            if (total == n) {
                idx = i + 1;
                break;
            }
        }
    }
    return idx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        arr.push_back(x);
    }
    if (n <= m) {
        cout << n << endl;
        return 0;
    }
    st = 0;
    en = 2000000000LL * 1000000LL;
    res = 2000000000LL * 1000000LL;
    while (st <= en) {
        mid = (st + en) / 2;
        if (check(mid)) {
            res = min(res, mid);
            en = mid - 1;
        }
        else st = mid + 1;
    }
    cout << findPosition(res) << endl;
}