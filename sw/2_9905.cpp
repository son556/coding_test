#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int t, n, cnt;
int arr[12];

void go(vector<int> &v, int total, int target) {
    if (total >= target) {
        if (total == target) cnt++;
        return;
    }
    for (int i = 1; i < 4; i++) {
        v.push_back(i);
        go(v, total + i, target);
        v.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    for (int i = 1; i < 12; i++) {
        v.clear();
        cnt = 0;
        go(v, 0, i);
        arr[i] = cnt;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n] << endl;
    }
}