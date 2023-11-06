#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int r, c, k, cnt;
string str;
int arr[5][5], visited[5][5];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
	if (arr[0][c - 1])
	{
		if (arr[0][c - 1] == k)
			cnt++;
		arr[0][c - 1] = 0;
		return;
	}
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0 || arr[ny][nx]) continue;
		arr[ny][nx] = arr[y][x] + 1;
		dfs(ny, nx);
		arr[ny][nx] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'T')
				arr[i][j] = -1;
			else
				arr[i][j] = 0;
		}
	}
	arr[r - 1][0] = 1;
	dfs(r - 1, 0);
	cout << cnt;
}