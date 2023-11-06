#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, cnt, n5, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		n5 = m / 5;
		cnt = n5;
		while (n5)
		{
			n5 /= 5;
			cnt += n5;
		}
		cout << cnt << '\n';
	}
}

