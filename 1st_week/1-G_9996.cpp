#include "./test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int N, k, flag;
string p, s, p1, p2, s2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> p;
	size_t idx = p.find("*");
	p1 = p.substr(0, idx);
	p2 = p.substr(idx + 1, p.length() - (idx + 1));
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		k = s.length() - 1;
		flag = 0;
		if (s.find(p1) == 0)
		{
			for (int j = p2.length() - 1; j >= 0; j--)
			{
				if (s[k] == p2[j] && k >= p1.length())
				{
					--k;
					flag = 1;
				}
				else
				{
					flag = -1;
					break ;
				}
			}
			if (flag == -1 || flag == 0)
				cout << "NE\n";
			else if (flag == 1)
				cout << "DA\n";
		}
		else
		{
			if (flag == 0)
				cout << "NE\n";
		}
	}
}