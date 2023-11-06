#include "./test.hpp"

// #include <bits/stdc++.h>

using namespace std;
long long a, b, c, num;

long long my_for(long long a, long long b, long long c)
{
	if (b == 1)
		return (a % c);
	long long ret = my_for(a, b / 2 , c);
	ret = ret * ret % c;
	if (b % 2 == 1)
		return ((ret * a) % c);
	return (ret);
}

int main(void)
{
	cin >> a >> b >> c;
	num = 1;
	cout << my_for(a, b, c);
	return (0);
}