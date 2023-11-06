#include "test.hpp"

//#include <bits/stdc++.h> bfs 시작점이 여러개인 경우
using namespace std;
int r, c, sx, sy, cnt, flag;
string str;
int arr[1004][1004], visited[1004][1004], visitedf[1004][1004];
int farr[1004][1004], res[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> f;

void bfs(int y, int x)
{
	int ny, nx;
	queue<pair<int, int>> q;
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
			if (ny >= r || ny < 0 || nx >= c || nx < 0) continue;
			if (arr[ny][nx] != 0 || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			arr[ny][nx] = arr[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

void fire_bfs()
{
	int ny, nx, y, x;
	while (f.size())
	{
		tie(y, x) = f.front();
		f.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >=r || ny < 0 || nx >= c || nx < 0 || farr[ny][nx] != 0) continue;
			if (visitedf[ny][nx]) continue;
			visitedf[ny][nx] = 1;
			farr[ny][nx] = farr[y][x] + 1;
			f.push({ny, nx});
		}
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
			if (str[j] == '#')
			{
				arr[i][j] = -2;
				farr[i][j] = -2;
			}
			else if (str[j] == '.')
			{
				arr[i][j] = 0;
				farr[i][j] = 0;
			}
			else if (str[j] == 'J')
			{
				arr[i][j] = 1;
				sy = i;
				sx = j;
			}
			else
			{
				arr[i][j] = -1;
				farr[i][j] = 1;
				visitedf[i][j] = 1;
				f.push({i, j});
			}
		}
	}
	bfs(sy, sx);
	fire_bfs();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] > 0)
			{
				if (farr[i][j] > 0)
					res[i][j] = farr[i][j] - arr[i][j];
				else
					res[i][j] = arr[i][j];
			}
			else
				res[i][j] = arr[i][j];
		}
	}
	cnt = INT_MAX;
	for (int i = 0; i < r; i++)
	{
		if (res[i][0] > 0)
		{
			if (cnt > arr[i][0])
				cnt = arr[i][0];
		}
		if (res[i][c - 1] > 0)
		{
			if (cnt > arr[i][c - 1])
				cnt = arr[i][c - 1];
		}
	}
	for (int i = 0; i < c; i++)
	{
		if (res[0][i] > 0)
		{
			if (cnt > arr[0][i])
				cnt = arr[0][i];
		}
		if (res[r - 1][i] > 0)
		{
			if (cnt > arr[r - 1][i])
				cnt = arr[r - 1][i];
		}
	}
	if (cnt == INT_MAX)
		cout << "IMPOSSIBLE";
	else
		cout << cnt;
}