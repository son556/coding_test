#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> arr;
vector<vector<int>> res;

void permu(int depth) {
    if (depth == m) {
        vector<int> b;
        for (int i = 0; i < m; i++) b.push_back(arr[i]);
        res.push_back(b);
        return;
    }
    for (int i = depth; i < n; i++) {
        swap(arr[i], arr[depth]);
        permu(depth + 1);
        swap(arr[i], arr[depth]);
    }
}

bool cmp(vector<int> &v1, vector<int> &v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == v2[i]) continue;
        return v1[i] < v2[i];
    }
    return v1[v1.size() - 1] < v2[v2.size() - 1];
}

int main() {
    cin >> n >> m;
    vector<int> b;
    for (int i = 1; i <= n; i++) arr.push_back(i);
    permu(0);
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << ' ';
        cout << endl;
    }
}
