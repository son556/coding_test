#include "./test.hpp"
// #include <bits/stdc++.h>
using namespace std;

string str;
int i, len;

int main(void)
{
	cin >> str;
	len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			cout << 0;
			len = -1;
			break ;
		}
	}
	if (len != -1)
		cout << 1;
	return (0);
}