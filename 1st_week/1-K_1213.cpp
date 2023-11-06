#include "./test.hpp"

// #include <bits/stdc++.h>
using namespace std;
int arr[26], num;
string str, pre, suf, mid, result;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		arr[str[i] - 'A']++;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] % 2 == 1)
		{
			mid = 'A' + i;
			num++;
		}
	}
	if (num > 1)
		cout << "I'm Sorry Hansoo";
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 0 && arr[i] % 2 == 0)
			{
				while (arr[i])
				{
					pre += char('A' + i);
					suf = char('A' + i) + suf;
					arr[i] -= 2;
				}
			}
			else if (arr[i] > 0 && arr[i] % 2 == 1)
			{
				while (arr[i] > 1)
				{
					pre += char('A' + i);
					suf = char('A' + i) + suf;
					arr[i] -= 2;
				}
			}
		}
		cout << pre + mid + suf;
	}
}