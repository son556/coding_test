#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int arr[8][8], i_map[8][8], visited[8][8];
int n, m, cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<vector<int>> v;
vector<vector<int>> wall;

void bfs(int i, int j)
{
	int x, y, nx, ny;
	queue<pair<int, int>>q;
	q.push({i, j});
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		i_map[y][x] = 2;
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || i_map[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			q.push({ny, nx});
		}
	}
}

void copy_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			i_map[i][j] = arr[i][j];
			visited[i][j] = 0;
		}
	}
}

void cnt_map()
{
	int tmp_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i_map[i][j] == 0)
				tmp_cnt++;
		}
	}
	if (cnt < tmp_cnt)
		cnt = tmp_cnt;
}

void find_safe_zone()
{
	for (int i = 0; i < v.size() - 2; i++)
	{
		for (int j = i + 1; j < v.size() - 1; j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				vector<int> w;
				w.push_back(i);
				w.push_back(j);
				w.push_back(k);
				wall.push_back(w);
			}
		}
	}
	for (int i = 0; i < wall.size(); i++)
	{
		i_map[v[wall[i][0]][0]][v[wall[i][0]][1]] = 1;
		i_map[v[wall[i][1]][0]][v[wall[i][1]][1]] = 1;
		i_map[v[wall[i][2]][0]][v[wall[i][2]][1]] = 1;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (i_map[j][k] == 2 && visited[j][k] == 0)
				{	
					bfs(j, k);
				}
			}
		}
		cnt_map();
		copy_map();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				vector<int>v2;
				v2.push_back(i);
				v2.push_back(j);
				v.push_back(v2);
			}
		}
	}
	copy_map();
	find_safe_zone();
	cout << cnt;
}