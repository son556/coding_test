#include "test.hpp"
// #include <bits/stdc++.h>
#include <cstring>
using namespace std;

int N, s, e;
vector<int> arr;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> N;
		arr.push_back(N);
	}
	sort(arr.begin(), arr.end());
	N = accumulate(arr.begin(), arr.end(), 0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (N - arr[i] - arr[j] == 100)
			{
				s = i;
				e = j;
				break ;
			}
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (i == s || i == e)
			continue ;
		cout << arr[i] << '\n';
	}
	return (0);
}
/* 435123 12345 */