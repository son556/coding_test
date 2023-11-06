#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res, num;
vector <ll> vec;
int n;

ll check(int start, int end)
{
	int l, r, mid = (start + end) / 2;
	ll tmp = 9876543210, tmp2 = 0;
	r = l = mid;
	while (1)
	{
		tmp = min(tmp, min(vec[l], vec[r]));
		tmp2 = max(tmp2, tmp * (r - l + 1));
		if (l == start && r == end) break;
		else if (l == start) r++;
		else if (r == end) l--;
		else
		{
			if (vec[l - 1] > vec[r + 1]) l--;
			else r++;
		}
	}
	return tmp2;
}

ll go(int start, int end)
{
	if (start == end)
		return vec[start];
	if (start < end)
	{
		int mid = (start + end) / 2;
		res = max(go(start, mid), go(mid + 1, end));
		res = max(res, check(start, end));
	}
	return res;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	cout << go(0, n - 1);
}