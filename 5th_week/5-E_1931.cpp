#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, s, e;
vector<pair<int, int>> v;
vector<pair<int, int>> res;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({s, e});
	}
	sort(v.begin(), v.end(), cmp);
	int end = -1;
	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= end)
		{
			end = v[i].second;
			res.push_back(v[i]);
		}
	}
	cout << res.size() << endl;
	return 0;
}