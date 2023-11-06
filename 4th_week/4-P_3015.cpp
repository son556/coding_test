#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

long int n, arr[500000], cnt;
stack<pair<int ,int >>	stk;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 1;
		cin >> arr[i];
		while (stk.size() && stk.top().first <= arr[i])
		{
			cnt += stk.top().second;
			if (stk.top().first == arr[i])
				temp = stk.top().second + 1;
			else
				temp = 1;
			stk.pop();
		}
		if (stk.size())
			++cnt;
		stk.push(make_pair(arr[i], temp));
	}
	cout << cnt;
}