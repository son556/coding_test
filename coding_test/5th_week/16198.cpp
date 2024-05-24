#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
int res, num;
vector<int> e;

vector<int> eraseIdx(vector<int> &v, int idx) {
    vector<int> tmp;
    for (int i = 0; i < v.size(); i++) {
        if (i == idx) continue;
        tmp.push_back(v[i]);
    }
    return tmp;
}

void go(vector<int> &v, int total) {
    if (v.size() == 2) {
        if (res < total)
            res = total;
        return;
    }
    vector<int> tmp;
    for (int i = 1; i < v.size() - 1; i++) {
        tmp = eraseIdx(v, i);
        go(tmp, total + v[i - 1] * v[i + 1]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        e.push_back(num);
    }
    go(e, 0);
    cout << res << '\n';
}