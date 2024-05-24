#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int res = INT_MAX;
int n, m;
vector<int> lec;

bool check(int t) {
    int idx = 0;
    int total = 0;
    int cnt = 0;
    while (1) {
        if (idx >= n)
            break;
        total += lec[idx];
        if (total > t) {
            total = 0;
            cnt++;
            if (cnt >= m) return false;
        }
        else
            idx++;
    }
    return true;
}

void go() {
    int st = 1;
    int ed = 1000000000;

    while (st <= ed) {
        int mid = (st + ed) / 2;
        if (check(mid)) {
            res = min(res, mid);
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lec.push_back(num);
    }
    go();
    cout << res << '\n';
}