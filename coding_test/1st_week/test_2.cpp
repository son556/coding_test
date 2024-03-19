#include "test.hpp"

// 2156
/*
알고리즘 dp -> 잔의 개수가 10000개인데 전부 탐색하는 경우 -> 2(마신다, 안마신다) 의 10000승이라 불가능
    dp 탐색 -> 해당 인덱스와 얼마나 연속이 되었는 지를 나타내는 2차원 배열을 만든다.

*/
//#include <bits/stdc++.h>

using namespace std;

int dp[10000][3], n;
vector<int> arr;

int go(int idx, int res) {
    if (idx == n) return 0;
    int &ret = dp[idx][res];
    if (ret != -1) return ret;
    ret = 0;
    if (res != 2) {
        ret = max(go(idx + 1, res + 1) + arr[idx], go(idx + 1, 0));
    }
    else
        ret = max(ret, go(idx + 1, 0));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << '\n';
}