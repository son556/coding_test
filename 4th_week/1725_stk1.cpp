#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<pair<ll, ll>> stk;
ll n, m, tmp1, tmp2;
ll res;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		while (stk.size() && stk.top().first > m)
		{
			tie(tmp1, tmp2) = stk.top();
			stk.pop();
			if (stk.size() && tmp1 > stk.top().first)
			{
				res = max(res, tmp1 * tmp2);
				res = max(res, stk.top().first * (stk.top().second + tmp2));
			}
			else if (stk.size() == 0)
				res = max(res, tmp1 * tmp2);
			if (stk.size())
			{
				if (stk.top().first >= m)
					stk.top().second += tmp2;
				else
					stk.push({m, tmp2});
			}
			else
				stk.push({m, tmp2});
		}
		if (stk.size() && stk.top().first == m)
			stk.top().second += 1;
		else
			stk.push({m, 1});
	}
	while (stk.size())
	{
		tie(tmp1, tmp2) = stk.top();
		stk.pop();
		if (stk.size() && tmp1 > stk.top().first)
		{
			res = max(res, tmp1 * tmp2);
			res = max(res, stk.top().first * (stk.top().second + tmp2));
		}
		if (stk.size())
			stk.top().second += tmp2;
		else if (stk.size() == 0)
			res = max(res, tmp1 * tmp2);
	}
	cout << res;
}