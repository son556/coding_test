#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int dp[1001][10];
int n;
int tmp;
int div_n = 10007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 0; j < 10; j++) {
            tmp = 0;
            for (int k = j; k < 10; k++) 
                tmp += dp[i - 1][k] % div_n;
            dp[i][j] = tmp % div_n;
        }
    }
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += dp[n][i] % div_n;
    }
    cout << answer % div_n << endl;
}

