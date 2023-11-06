#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int a[1000004];
int ret[1000004];

int n, m, idx, sw, num;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		while (s.size() && a[i] > a[s.top()])
		{
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << ' ';
}