#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
string str;
int arr[20], n;
int ret = 987654321;

void go(int start)
{
	if (start == n)
	{
		int sum = 0;
		for (int i = 1; i < (1 << n); i *= 2)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (arr[j] & i)
					cnt++;
			sum += min(cnt, n - cnt);
		}
		ret = min(ret, sum);
		return ;
	}
	go(start + 1);
	arr[start] = ~arr[start];
	go(start + 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int val = 1;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'T')
				arr[i] |= val;
			val *= 2;
		}
	}
	go(0);
	cout << ret << '\n';
	return 0;
}
