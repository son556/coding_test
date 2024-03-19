#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;

bool check(vector<int> &v) {
    int tmp = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (tmp > v[i]) return false;
        tmp = v[i];
    }
    return true;
}

void go(vector<int> &v) {
    if (v.size() == m) {
        if (check(v)) {
            for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
            cout << endl;
        }
        return ;
    }
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
        go(v);
        v.pop_back();
    }
}

int main(void) {
    cin >> n >> m;
    vector<int> b;
    go(b);
}