#include "./test.hpp"

// #include <bits/stdc++.h>
// 경우의 수인 경우 long long 자료형을 쓸 것
using namespace std;

map<string, int> c;
int n, m, num;
string str, str2;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> str >> str2;
			c[str2]++;
		}
		num = 1;
		for (auto k : c)
			num *= (k.second + 1);
		cout << num - 1 << '\n';
		c.clear();
	}
}
