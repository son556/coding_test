//7-L_1535

#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int dp[21][101]; // 안되는 코드 이유???
int n;
vector<int> piro, happy;

int go(int idx, int hp, int hppy) {
	if (hp <= 0) {return 0;}
	if (idx == n) {return hppy;}
	int &ret = dp[idx][hp];
	if (ret != -1) {return ret;}
	ret = max(go(idx + 1, hp, hppy), go(idx + 1, hp - piro[idx], hppy + happy[idx]));
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		piro.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		happy.push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 100, 0) << endl;
}


// int dp[21][101];
// int n;
// vector<int> piro, happy;

// int main(void) {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);
// 	cin >> n;
// 	int x;
// 	for (int i = 0; i < n; i++) {
// 		cin >> x;
// 		piro.push_back(x);
// 	}
// 	for (int i = 0; i < n; i++) {
// 		cin >> x;
// 		happy.push_back(x);
// 	}
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j <= 100; j++) {
// 			if (j <= piro[i - 1]) {
// 				dp[i][j] = dp[i - 1][j];
// 				continue;
// 			}
// 			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - piro[i - 1]] + happy[i - 1]);
// 		}
// 	}
// 	cout << dp[n][100] << endl;
// }