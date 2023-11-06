#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int arr[100][100], visited[100][100], n, max_d, cnt, t_cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int i, int j, int d)
{
	int x, y, nx, ny;
	queue<pair<int, int>> q;
	q.push({i, j});
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= n || nx < 0 || arr[ny][nx] <= d) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ny, nx});
		}
	}
	
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
			if (arr[i][j] > max_d)
				max_d = arr[i][j];
		}
	}
	for (int i = 0; i < max_d; i++)
	{
		t_cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (arr[j][k] > i && visited[j][k] == 0)
				{
					visited[j][k] = 1;
					bfs(j, k, i);
					t_cnt++;
				}
			}
		}
		if (t_cnt > cnt)
			cnt = t_cnt;
	}
	cout << cnt;
}