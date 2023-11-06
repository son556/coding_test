#include "test.hpp"
//#include<bits/stdc++.h>
using namespace std;
int x, e, cnt;
vector<int> stick;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> x;
	cnt = 0;
	stick.push_back(64);
	e = 0;
	int idx = 0;
	while (idx < 7)
	{
		if (x & (1 << idx))
			cnt++;
		idx++;
	}
	cout << cnt;
}