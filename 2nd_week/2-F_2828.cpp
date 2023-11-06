#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, m, a, num, mov, tmp_m;
int s, e;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin >> a;
	s = 0;
	e = s + (m - 1);
	for(int i = 0; i < a; i++)
	{
		cin >> num;
		--num;
		if (num >= s && num <= e) continue;
		else
		{
			if (num > e)
			{
				tmp_m = num - e;
				mov += tmp_m;
				e += tmp_m;
				s += tmp_m;
			}
			else
			{
				tmp_m = s - num;
				mov += tmp_m;
				e -= tmp_m;
				s -= tmp_m;
			}
		}
	}
	cout << mov;
}