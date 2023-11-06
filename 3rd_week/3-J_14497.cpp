#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, m, x_1, y_1, x_2, y_2;
int arr[304][304], visited[304][304];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string str;

void bfs(int y, int x)
{
	int nx, ny;
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({y, x});
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx])continue;
			visited[ny][nx] = 1;
			if (arr[ny][nx] == -1)
			{
				arr[ny][nx] = 1;
				continue;
			}
			arr[ny][nx]++;
			q.push({ny, nx});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	x_1--;
	y_1--;
	x_2--;
	y_2--;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '1')
				arr[i][j] = -1;
			else if (str[j] == '*')
				arr[i][j] = 3;
			else
				arr[i][j] = 0;
		}
	}
	int cnt = 0;
	while (arr[x_2][y_2] == 0)
	{
		cnt++;
		memset(visited, 0, sizeof(visited));
		bfs(x_1, y_1);
	}
	cout << cnt;
}