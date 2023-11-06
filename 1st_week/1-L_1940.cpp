#include "test.hpp"

// #include <bits/stdc++.h>
using namespace std;

int n, m, num;
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	num = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vec[i] + vec[j] == m)
				num++;
		}
	}
	cout << num;
}