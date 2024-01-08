#include "test.hpp"
// #include <bits/stdc++.h>
using namespace std; 

int n, k;
long long dp[10004];
vector<int> coins;

long long go(long long x) {
	if (x < 0) return 1e10;
	if (x == 0) return 0;
	long long &ret = dp[x];
	if (ret) return ret;
	ret = 1e10;
	for (int i = 0; i < coins.size(); i++) {
		ret = min(ret, go(x - coins[i]) + 1);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		coins.push_back(x);
	}
	long long answer = go(k);
	if (answer == 1e10) cout << -1 << endl;
	else cout << answer << endl;
	return 0;
}