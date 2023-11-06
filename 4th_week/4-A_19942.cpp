#include "test.hpp"
//시간복잡도에 대해 생각하기
//#include <bits/stdc++.h>
using namespace std;

int arr[15][5], target[4];
int n, p, s;
vector<string> vec;

void regi_vec(int num)
{
	string res;
	res = "";
	for (int idx = 0; idx < n; idx++)
	{
		if (num & (1 << idx))
			res += to_string(idx + 1) + ' ';
	}
	vec.push_back(res);
}

bool check_val(int val[5])
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (val[i] < target[i])
			return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> target[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	
	p = INT_MAX;
	for (int i = 0; i < (1 << n); i++)
	{
		int val[5] = {0, 0, 0, 0, 0};
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				for (int k = 0; k < 5; k++)
					val[k] += arr[j][k];
			}
		}
		if (check_val(val))
		{
			if (p >= val[4])
			{
				if (p == val[4])
					regi_vec(i);
				else
				{
					vec.clear();
					regi_vec(i);
				}
				p = val[4];
			}
		}
	}
	if (p == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << p << '\n';
	sort(vec.begin(), vec.end());
	cout << vec[0];
}