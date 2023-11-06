#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vec;
int n, m, num;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[500][500];
int res;

int go(int y, int x)
{
	int ny, nx;
	if (y == n - 1 && x == m - 1)
		return 1;
	if (visited[y][x] != -1)
		return visited[y][x];
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
		if (vec[ny][nx] >= vec[y][x]) continue;
		visited[y][x] += go(ny, nx);
	}
	return visited[y][x];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			v.push_back(num);
		}
		vec.push_back(v);
	}
	memset(visited, -1, sizeof(visited));
	visited[n - 1][m - 1] = 1;
	cout << go(0, 0);
	return 0;
}