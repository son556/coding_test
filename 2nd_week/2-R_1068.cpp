#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vec;
vector<int> tmp;
int n, m, d, cnt, r;

void dfs(int idx)
{
	int sw = 0;
	for (int i = 0; i < vec[idx].size(); i++)
	{	
		if (vec[idx][i] > -1)
		{
			sw = 1;
			break ;
		}
	}
	if (sw == 0)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < vec[idx].size(); i++)
	{
		if (vec[idx][i] > -1)
			dfs(vec[idx][i]);
	}
		
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vector<int>v;
		v.push_back(-1);
		vec.push_back(v);
		tmp.push_back(m);
		if (m == -1)
			r = i;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != -1)
			vec[tmp[i]].push_back(i);
	}
	cin >> d;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == d)
				vec[i].erase(vec[i].begin() + j);
		}
	}
	dfs(r);
	if (d != r)
		cout << cnt;
	if (d == r)
		cout << 0;
}