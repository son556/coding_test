#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll s, c, pa;
ll st, mid, en, res;
vector<ll> pas;

bool check(ll n) {
    ll cnt = 0;
    for (int i = 0; i < s; i++) {
        cnt += pas[i] / n;
    }
    if (cnt >= c) return true;
    return false;
}

ll checkSum(ll num) {
    ll total = 0;
    ll cnt = 0;
    ll total_cnt = 0;
    int sw = 0;
    for (int i = 0; i < s; i++) {
        cnt = pas[i] / num;
        total_cnt += cnt;
        total += pas[i] - num * cnt;
        if (total_cnt >= c) {
            sw = i + 1;
            total += num * (total_cnt - c);
            break;
        }
    }
    if (sw) {
        for (int i = sw; i < s; i++) {
            total += pas[i];
        }
    }
    return total;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> c;
    for (int i = 0; i < s; i++) {
        cin >> pa;
        pas.push_back(pa);
        en = max(en, pa);
    }
    st = 1;
    while (st <= en) {
        mid = (st + en) / 2;
        if (check(mid)) {
            st = mid + 1;
            res = max(res, mid);
        }
        else en = mid - 1;
    }
    cout << checkSum(res) << endl;
}