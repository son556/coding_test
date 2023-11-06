#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
char str[9];
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string str1, str2, res;
int num;

bool check(string res)
{
	int n;
	for (int i = 0; i < res.length(); i++)
	{
		if (i == 0)
			n = res[i] - '0';
		else
		{
			if (str[i - 1] == '<')
			{
				if (n > res[i] - '0')
					return (false);
				else
					n = res[i] - '0';
			}
			else if (str[i - 1] == '>')
			{
				if (n < res[i] - '0')
					return (false);
				else
					n = res[i] - '0';
			}
		}
	}
	return (true);
}

void permu(int n, int r, int depth)
{
	if (depth == r)
	{
		for (int i = 0; i < r; i++)
			res += arr[i] + '0';
		if (!check(res))
		{
			res = "";
			return;
		}
		str1 = max(str1, res);
		str2 = min(str2, res);
		res = "";
		return ;
	}
	for (int i = depth; i < n; i++)
	{
		swap(arr[i], arr[depth]);
		permu(n, r, depth + 1);
		swap(arr[i], arr[depth]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> str[i];
	res = "";
	str2 = "9999999999";
	permu(10, num + 1, 0);
	cout << str1 << '\n';
	cout << str2 << '\n';
}