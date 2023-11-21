#include "test.hpp"

//#include <bits/stdc++.h>
// lower_bound를 사용하자
using namespace std;

int n, a_size, b_size;
vector<int> a, b;

int check() {
    int s, e, m;
    int res = 0;
    for (int i = 0; i < b.size(); i++) {
        m = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (m >= a.size()) continue;
        if (a[m] == b[i])
        {
            while (a[m] == b[i])
                m++;
            res += a.size() - m;
        }
        else res += a.size() - m;
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a_size >>b_size;
        a.clear();
        b.clear();
        for (int j = 0; j < a_size; j++) {
            cin >> x;
            a.push_back(x);
        }
        for (int j = 0; j < b_size; j++) {
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        cout << check() << endl;
    }
}