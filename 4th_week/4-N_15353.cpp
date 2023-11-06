#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

string n1, n2, res;
deque<int>num1, num2;
int len;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n1 >> n2;
	len = max(n1.length(), n2.length());
	for (int i = 0; i < len; i++)
	{
		if (i < n1.length())
			num1.push_back(n1[i] - '0');
		else
			num1.push_front(0);
		if (i < n2.length())
			num2.push_back(n2[i] - '0');
		else
			num2.push_front(0);
	}
	int n, s;
	res = "";
	s = 0;
	while (num1.size())
	{
		n = num1.back() + num2.back() + s;
		num1.pop_back();
		num2.pop_back();
		res = to_string(n % 10) + res;
		s = n / 10;
		if (num1.size() == 0 && s)
			res = to_string(s) + res;
	}
	cout << res;
}