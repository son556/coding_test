#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, d, r, res;
vector<vector<int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d >> r;
		b.push_back(d);
		b.push_back(r);
		vec.push_back(b);
		b.clear();
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		pq.push(vec[i][1]);
		if (pq.size() > vec[i][0])
			pq.pop();
	}
	while(pq.size())
	{
		res += pq.top();
		pq.pop();
	}
	cout << res << endl;
}
