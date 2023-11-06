#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
int n, cnt, sw;
string str;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cnt = 0;
		sw = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				cnt++;
			else
				cnt--;
			if (cnt < 0)
			{
				cout << "NO\n";
				sw = 1;
				break;
			}
		}
		if (cnt != 0 && sw == 0)
			cout << "NO\n";
		else if (sw == 0)
			cout << "YES\n";
	}
}