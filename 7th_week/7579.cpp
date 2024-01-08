//7579

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int dp[10000001];
int n, m;
vector<int> mem, pay;

int n, m, a, c, res;
vector<int> mem, pay;
int dp[101][10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mem.push_back(a);
	}
	for (int j = 0; j < n; j++) {
		cin >> c;
		pay.push_back(c);
	}
	for (int i = 1; i <= pay.size(); i++) {
		for (int j = 0; j < 10001; j++) {
			if (j < pay[i - 1]) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - pay[i - 1]] + mem[i - 1]);
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (dp[n][i] >= m) {
			cout << i << endl;
			break;
		}
	}
}