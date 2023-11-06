#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
int n, num;
string str;

int main(void)
{
	cin >> n;
	num = 666;
	while (1)
	{
		str = to_string(num);
		for (int i = 0; i < str.length() - 2; i++)
		{
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				n--;
				break ;
			}
		}
		if (n == 0)
			break ;
		num++;
	}
	cout << num;
}