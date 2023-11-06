#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n;
int res = 987654321;
vector<vector<int>>vec;
vector<pair<int, int>> put;
int arr[10][10], visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void combi(int start, vector<int>b)
{
	if (b.size() == 3)
	{
		vec.push_back(b);
		return ;
	}
	for (int i = start + 1; i < put.size(); i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}

bool flower(int s)
{
	int x, y, nx, ny, total;
	total = 0;
	for (int i = 0; i < 3; i++)
	{
		tie(y, x) = put[vec[s][i]];
		total += arr[y][x];
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx])
				return (false);
			total += arr[ny][nx];
			visited[ny][nx] = 1;
		}
	}
	res = min(res, total);
	return (true);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			put.push_back({i, j});
		}
	}
	vector<int> b;
	combi(-1, b);
	for (int i = 0; i < vec.size(); i++)
	{
		memset(visited, 0, sizeof(visited));
		flower(i);
	}
	cout << res;
}