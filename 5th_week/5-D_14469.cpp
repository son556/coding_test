#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<pair<int, int>> cows;

bool cmp(pair<int, int>c1, pair<int, int>c2)
{
	if (c1.first == c2.first)
		return c1.second < c2.second;
	return c1.first < c2.first;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cows.push_back({a, b});
	}
	sort(cows.begin(), cows.end(), cmp);
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (t < cows[i].first)
			t = cows[i].first + cows[i].second;
		else
			t += cows[i].second;
	}
	cout << t << endl;
	return 0;
}