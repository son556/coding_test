#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
vector<int> arr;
int n, m;

void combi(int start, vector<int> v) {
    if (v.size() == m) {
        for (int i = 0; i < m; i++) cout << v[i] << ' ';
        cout << endl;
        return ;
    }
    for (int i = start + 1; i < n; i++) {
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr.push_back(i);
    vector<int> b;
    combi(-1, b);
}