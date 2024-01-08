//7-R_10942

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> vec;
int s, e;
int dp[2001][2001];

int go(int st, int en) {
	if (st == en) {
		if (vec[en] == vec[st]) {
			dp[en][st] = 1;
			return 1;
		}
		dp[en][st] = 0;
		return 0;
	}
	int &ret = dp[st][en];
	if (ret != -1) return ret;
	ret = 0;
	if (vec[st] == vec[en]) {
		if (st + 1 <= en - 1) ret = go(st + 1, en - 1);
		else ret = 1;
	}
	go(st + 1, en);
	go(st, en - 1);
	return ret;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		vec.push_back(m);
	}
	memset(dp, -1, sizeof(dp));
	go(0, vec.size() - 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		s--; e--;
		cout << dp[s][e] << '\n';
	}
	return 0;
}