#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<int> arr, res;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    res.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        x = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
        if (x == res.size()) res.push_back(arr[i]);
        else res[x] = arr[i];
    }
    cout << res.size() << endl;
}