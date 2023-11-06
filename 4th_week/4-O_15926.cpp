#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

string str, tmp;
int ret = -1, n, d[200001], cnt;
stack<char> box;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin.ignore();
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(') box.push(i);
		else if (box.size())
		{
			d[i] = d[box.top()] = 1;
			box.pop();
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (d[i])
		{
			cnt++;
			ret = max(ret, cnt);
		}
		else
			cnt = 0;
	}
	cout << ret;
}