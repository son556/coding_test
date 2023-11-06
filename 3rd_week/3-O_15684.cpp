#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> put;
vector<vector<int>> vec;
int n, m, h, cnt;
int t1, t2;
int arr[30][9], visited[30][9], cp[30][9];

bool move(int point, int start)
{
	int level = 0, sw, state;
	while (level < h)
	{
		sw = 0;
		state = level;
		for (int i = state; i < h; i++)
		{
			if (point < n - 1 && cp[i][point])
			{
				level = i + 1;
				point++;
				sw = 1;
				break;
			}
			else if ( point > 0 && cp[i][point - 1])
			{
				level = i + 1;
				point--;
				sw = 1;
				break;
			}
		}
		if (sw == 0)
			level = h;
	}
	if (point == start)
		return true;
	return false;
}

void combi(int start, vector<int>b, int r)
{
	if (b.size() == r)
	{
		vec.push_back(b);
		return ;
	}
	for (int i = start + 1; i < put.size(); i++)
	{
		b.push_back(i);
		combi(i, b, r);
		b.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		arr[t1 - 1][t2 - 1] = 1;
	}
	copy(&arr[0][0], &arr[0][0] + 30 * 9, &cp[0][0]);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[i][j] == 0)
				put.push_back({i, j});
		}
	}
	int flag;
	flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (move(i, i) == false)
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 0)
	{
		cout << cnt;
		return 0;
	}
	int x, y;
	for (int i = 1; i <= 3; i++)
	{
		vector<int>b;
		cnt = i;
		combi(-1, b, i);
		for (int j = 0; j < vec.size(); j++)
		{
			copy(&arr[0][0], &arr[0][0] + 30 * 9, &cp[0][0]);
			for (int k = 0; k < vec[j].size(); k++)
			{
				tie(y, x) = put[vec[j][k]];
				if (x > 0 && cp[y][x - 1] == 1) continue;
				if (x < n - 2 && cp[y][x + 1] == 1) continue;
				cp[y][x] = 1;
			}
			flag = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (move(i, i) == false)
				{
					flag = 1;
					break ;
				}
			}
			if (flag == 0)
			{
				cout << cnt;
				return 0;
			}
		}
	}
	cout << -1;
}