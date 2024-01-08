#include "test.hpp"

// #include <bits/stdc++.h>
using namespace std; 

long long n, dp[2][31][31];

long long go(int a, int cnt1, int cnt2) {
	if (cnt1 == 0 && cnt2 == 0) return 1;
	long long &ret = dp[a][cnt1][cnt2];
	if (ret) return ret;
	if (cnt1 > 0 && cnt2 > 0)
		ret = go(1, cnt1 - 1, cnt2 + 1) + go(0, cnt1, cnt2 - 1);
	else if (cnt1 > 0 && cnt2 == 0)
		ret = go(1, cnt1 - 1, cnt2 + 1);
	else if (cnt1 == 0 && cnt2 > 0)
		ret = go(0, cnt1, cnt2 - 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	n = 1;
	while (n) {
		cin >> n;
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		cout << go(1, n, 0) << endl;
	}
}