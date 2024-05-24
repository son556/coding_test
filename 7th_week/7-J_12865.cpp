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


/*
1개만 사용가능한 경우 동전과 다르게 거꾸로 가야함
이유 동전은 현재 있는 돈으로 예를들어 (k + 동전 == m) 인 경우 k 원에 동전을 더한 경우와 동전을 더하지 않은 경우로
나눌 수 있는데 이는 동전의 가치는 정해져 있지만 동일한 가치가 있는 동전의 수가 무한하다는 가정
아래와 같은 배낭문제는 물건의 개수가 1개 이므로 현재 k 까지 만든것에 현재 물건의 가치를 더하는 것이 아닌 과거에 k까지 만든
것에 현재 물건의 가치를 더해야 하기 때문에 뒤에서 부터 시작해야 함
*/

/*

//#include <bits/stdc++.h>

using namespace std;

int dp[100004];
int n, k;
vector<pair<int, int>> val;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        val.push_back(p);
    }
    sort(val.begin(), val.end());
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j < val[i].first) continue;
            dp[j] = max(dp[j], dp[j - val[i].first] + val[i].second);
        }
    }
    cout << dp[k] << '\n';
}
*/