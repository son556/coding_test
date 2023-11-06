#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int arr[100][100], visited[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, cnt, t, tmp_cnt;

int cnt_cheese()
{
	int cheese = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				cheese++;
		}
	}
	return (cheese);
}

void init_bfs()
{
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			visited[i][j] = 0;
}

void bfs()
{
	int x, y, nx, ny;
	queue<pair<int, int> >q;
	init_bfs();
	q.push({0, 0});
	visited[0][0] = 1;
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			if (arr[ny][nx] == 1)
			{
				arr[ny][nx] = 0;
				visited[ny][nx] = 1;
				continue;
			}
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;//여기서 방문처리 해줘야 중복안됨
			q.push({ny, nx});
		}
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
	while(1)
	{
		tmp_cnt = cnt_cheese();
		if (tmp_cnt > 0) cnt = tmp_cnt;
		else
			break;
		bfs();
		t++;
		
	}
	cout << t << '\n';
	cout << cnt;
}