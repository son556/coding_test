#include "test.hpp"
// #include <bits/stdc++.h>

using namespace std;

int a[26], n;
string str, result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		++a[str[0] - 'a'];
	}
	n = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
		{
			cout << (char)(i + 'a');
			n++;
		}
	}
	if (n == 0)
		cout << "PREDAJA";
	return (0);
}
