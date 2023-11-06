#include "./test.hpp"

// #include <bits/stdc++.h>

using namespace std;
long long a, cnt, num;

int main(void)
{
	ios::sync_with_stdio(false); // 사용시 cin cout만 사용해야함
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> a)
	{
		num = 1;
		cnt = 1;
		while (1)
		{
			if (num % a == 0)
				break ;
			num *= 10;
			num += 1;
			num %= a;
			cnt++;
		}
		cout << cnt << '\n';
	}
}
