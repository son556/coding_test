//7 - I 4781

#include "test.hpp"

//#include <bits/stdc++.h>
// 무한한 개수 -> , 유한 <-
// 무한 1차원 왼쪽 ,유한 2차원 위쪽(abcd d를 포함시키는 경우, 안시키는 경우)
using namespace std;

float m;
int n;
vector<pair<int, float>> candy;
int dp[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    float b;
    int a;
    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            candy.push_back({a, b});
        }
        for (int i = 0; i < candy.size(); i++) {
            for (int j = 0; j <= int(m * 100 + 0.5); j++) {
                if (j < int(candy[i].second * 100 + 0.5)) continue;
                dp[j] = max(dp[j], dp[j - int(candy[i].second * 100 + 0.5)] + candy[i].first);
            }
        }
        cout << dp[int(m * 100 + 0.5)] << endl;
        candy.clear();
        memset(dp, 0, sizeof(dp));
    }
}