#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, cnt, x, y;
int arr[50][50], visited[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1}; 

void bfs(int i, int j)
{
	int t_x, t_y;
	queue<pair<int, int>> que;
	que.push({i, j});
	while (que.size())
	{
		tie(t_y, t_x) = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = t_y + dy[i];
			int nx = t_x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || arr[ny][nx] == 0)
				continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			que.push({ny, nx});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				arr[a][b] = 0;
				visited[a][b] = 0;
			}
		}
		cnt = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int l = 0; l < n; l++)
		{
			for (int p = 0; p < m; p++)
			{
				if (arr[l][p] == 1 && visited[l][p] == 0)
				{
					visited[l][p] = 1;
					bfs(l, p);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}