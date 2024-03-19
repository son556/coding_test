#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> stair;
vector<int> arr;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        stair.push_back(x);
    }
    arr.push_back(stair[0]);
    if (n >= 2) arr.push_back(stair[0] + stair[1]);
    if (n >= 3) arr.push_back(max(stair[2] + stair[0], stair[1] + stair[2]));
    for (int i = 3; i < n; i++) {
        arr.push_back(max(arr[i - 2], stair[i - 1] + arr[i - 3]) + stair[i]);
    }
    cout << arr[n - 1] << endl;
}