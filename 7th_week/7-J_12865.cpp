//7-J 12865
#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int> > pack;
int dp[101][100004];

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.first == p2.first) return p1.second > p2.second;
	return p1.first < p2.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int w, v;
    for (int i = 0; i < n; i++) {
    	cin >> w >> v;
    	pack.push_back({w, v});
	}
	sort(pack.begin(), pack.end(), cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= pack[i - 1].first)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - pack[i - 1].first] + pack[i - 1].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k] << endl;
}
