#include "test.hpp"

//#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[54][54], visited[54][54], origin[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char c;

void bfs(int y, int x)
{
	int nx, ny;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			arr[ny][nx] = arr[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

void copy_map()
{
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = origin[i][j];
}

int find_max()
{
	int val = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > val)
				val = arr[i][j];
		}
	}
	return (val);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'L')
				origin[i][j] = 1;
			else
				origin[i][j] = 0;
		}
	}
	t = INT_MIN;
	int val;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			copy_map();
			bfs(i, j);
			val = find_max();
			if (val > t)
				t = val;
		}
	}
	cout << t - 1;
}