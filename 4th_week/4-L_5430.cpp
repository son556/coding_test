#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
string cmp[3] = {"pi", "ka", "chu"};
string str, tmp;

bool check(string s)
{
	for (int i = 0; i < 3; i++)
	{
		if (s.length() == cmp[i].length() && s.compare(cmp[i]) == 0)
			return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	tmp = "";
	for (int i = 0; i < str.length(); i++)
	{
		tmp += str[i];
		if (tmp.length() == 2 && tmp.compare("ch") && i < str.length() - 1)
		{
			if (check(tmp))
				tmp = "";
		}
		else if (tmp.length() == 3)
		{
			if (check(tmp))
				tmp = "";
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else if (tmp.length() && i == str.length() - 1)
		{
			if (check(tmp) == false)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if (str.length() < 2)
		cout << "NO";
	else
		cout << "YES";
}