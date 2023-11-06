#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int arr[1504][1504], visited[1504][1504], visited_ice[1504][1504];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>>water;
queue<pair<int, int>>position;
vector<pair<int, int>>swan;
string str;
int r, c, cnt, sw;

void melt_ice()
{
	int x, y, nx, ny, qsize;
	qsize = water.size();
	for (int i = 0; i < qsize; i++)
	{
		tie(y, x) = water.front();
		water.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0 || visited_ice[ny][nx]) continue;
			visited_ice[y][x] = 1;
			if (arr[ny][nx] == -1)
			{
				arr[ny][nx] = 0;
				water.push({ny, nx});
			}
		}
	}
}

void check_swan()
{
	int x, y, nx, ny, psize, idx;
	queue<pair<int, int>> q;
	psize = position.size();
	idx = 0;
	while (idx < psize)
	{
		tie(y, x) = position.front();
		position.pop();
		q.push({y, x});
		visited[y][x] = 1;
		while (q.size())
		{
			tie(y, x) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= r || ny < 0 || nx >= c || nx < 0 || visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				if (arr[ny][nx] == -1)
				{
					position.push({ny, nx});
					continue;
				}
				q.push({ny, nx});
				if (visited[swan[1].first][swan[1].second])
				{
					sw = 1;
					return;
				}
			}
		}
		idx++;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '.')
			{
				arr[i][j] = 0;
				water.push({i, j});
			}
			else if (str[j] == 'X')
				arr[i][j] = -1;
			else if (str[j] == 'L')
			{
				arr[i][j] = 0;
				water.push({i, j});
				swan.push_back({i, j});
			}
		}
	}
	position.push({swan[0].first, swan[0].second});
	visited[swan[0].first][swan[0].second] = 1;
	while (1)
	{
		check_swan();
		if (sw == 1)
			break;
		cnt++;
		melt_ice();
	}
	cout << cnt;
}