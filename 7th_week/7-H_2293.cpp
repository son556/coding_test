#include "test.hpp"

//#include <bits/stdc++.h>
// 경우의 수 -> 더하기
using namespace std;
typedef long long ll;

// ll dp[10004];
// vector<ll> coins;
// int n, k;

// ll go(ll x) {
//     if (x < 0) return -1e10;
//     if (x == 0) return 1;
//     ll &ret = dp[x];
//     if (ret) return ret;
//     for (int i = 0; i < coins.size(); i++)
//         ret += max(ll(0), go(x - coins[i]));
//     return ret;
// }

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cin >> n >> k;
//     ll x;
//     for (int i = 0; i < n; i++) {
//         cin >> x;
//         coins.push_back(x);
//     }
//     ll answer = 0;
//     for (int i = 0; i < coins.size(); i++) {
//         if (k < coins[i]) continue;
//         answer += go(k - coins[i]);
//     }
//     cout << answer << endl;
// }

int dp[10001];  
int n, k, temp; 
int main(){
	scanf("%d %d",&n, &k);
    dp[0] = 1; 
	for(int i = 1; i <= n; i++){
        scanf("%d", &temp);  
        if(temp >= 10001) continue;  
        for(int j = temp; j <= k; j ++){  
            dp[j] += dp[j - temp]; 
        }
    };
    printf("%d\n", dp[k]);
    for (int i = 0; i <= k; i++) cout << dp[i] << ' ';
    cout << endl;
}