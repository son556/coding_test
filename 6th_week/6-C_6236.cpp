#include "test.hpp"

//#include <bits/stdc++.h>
// 이분탐색문제는 롱롱 기반으로 풀기

using namespace std;
typedef long long ll;

int n, m;
ll en, mi, st;
ll res;
vector<int> days;

bool checkM(ll p) {
    int cnt = 1;
    ll np = p;
    for (int i = 0; i < n; i++) {
        if (np >= days[i]) np -= days[i];
        else {
            np = p - days[i];
            cnt++;
        }
        if (cnt > m) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int pay;
    for (int i = 0; i < n; i++) {
        cin >> pay;
        en += pay;
        st = max(st, ll(pay));
        days.push_back(pay);
    }
    int flag;
    while (st <= en) {
        mi = (en + st) / 2;
        flag = checkM(mi);
        if (flag) {
            res = mi;
            en = mi - 1;
        }
        else st = mi + 1;
    }
    cout << res << endl;
}