#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vec;
int visited[1004];
int n, m, num, r;

void rot(int start, int ro)
{
	visited[start] = ro;
	int bs = start;
	int be = start;
	int s = start - 1;
	int e = start + 1;
	while (s >= 0 || e < n)
	{
		if (s >= 0)
		{
			if (vec[s][2] != vec[bs][6])
				visited[s] = -1 * visited[bs];
			bs = s;
			s--;
		}
		if (e < n)
		{
			if (vec[be][2] != vec[e][6])
				visited[e] = -1 * visited[be];
			be = e;
			e++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 1)
			rotate(vec[i].begin(), vec[i].end() - 1, vec[i].end());
		else if (visited[i] == -1)
			rotate(vec[i].begin(), vec[i].begin() + 1, vec[i].end());
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string tmp;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		b.clear();
		for (int j = 0; j < 8; j++)
			b.push_back(tmp[j] - '0');
		vec.push_back(b);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num >> r;
		memset(visited, 0, sizeof(visited));
		rot(num - 1, r);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if(vec[i][0]) cnt++;
	}
	cout << cnt;
}