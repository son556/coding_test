/*
합치면서 가려고 했으나 연속하지 않은 부분이 생김
예) 1 2 3 4 5 6 이렇게 있는 경우 1 2 를 합치고 5 6 합치는 경우를 표현할 수 없음
거꾸로 쪼개면서 가야한다
*/

#include<iostream>
#include<algorithm>

using namespace std;

int t, n;
int files[501];
int dp[501][501];
int preSum[501];

int go(int st, int ed) {
    if (st >= ed)
        return 0;
    int &ret = dp[st][ed];
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i = st; i <= ed; i++) {
        ret = min(ret, go(st, i) + go(i + 1, ed) + preSum[ed] - preSum[st - 1]);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        memset(files, 0, sizeof(files));
        memset(preSum, 0, sizeof(preSum));
        for (int i = 1; i <= n; i++) {
            cin >> files[i];
            preSum[i] = preSum[i - 1] + files[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << go(1, n) << endl;
    }
}

/*
1
4
40 30 30 50
*/
