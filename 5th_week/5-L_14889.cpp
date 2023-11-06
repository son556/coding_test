#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int t_start, t_link, n, m, res = INT_MAX;
vector<vector<int>> start, link, arr;
int visited[20];

void combi(int s, int r, vector<int> v)
{
	if (v.size() == r)
	{
		start.push_back(v);
		return ;
	}
	for (int i = s + 1; i < n; i++)
	{
		v.push_back(i);
		combi(i, r, v);
		v.pop_back();
	}
}

void totalFInd()
{
	for (int i = 0; i < start.size(); i++)
	{
		t_start = 0;
		for (int j = 0; j < start[i].size(); j++)
		{
			for (int k = 0; k < start[i].size(); k++)
				t_start += arr[start[i][j]][start[i][k]];
		}
		t_link = 0;
		for (int j = 0; j < link[i].size(); j++)
		{
			for (int k = 0; k < link[i].size(); k++)
				t_link += arr[link[i][j]][link[i][k]];
		}
		if (abs(t_start - t_link) < res)
			res = abs(t_start - t_link);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> m;
			v.push_back(m);
		}
		arr.push_back(v);
	}
	v.clear();
	combi(-1, n / 2, v);
	for (int i = 0; i < start.size(); i++)
	{
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < start[i].size(); j++)
			visited[start[i][j]] = 1;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			if (visited[j]) continue;
			v.push_back(j);
		}
		link.push_back(v);
	}
	totalFInd();
	cout << res << endl;
}