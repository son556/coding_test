#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;
int arr[1000][1000], visited[1000];

void dfs(int a)
{
	int nx, ny;
	for (int i = 0; i < n; i++)
	{
		if (arr[a][i] && visited[i] == 0)
		{
			arr[a][i] = 0;
			arr[i][a] = 0;
			visited[i] = 1;
			dfs(i);
		}
	}
}

void check_tree()
{
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			cout << "graph\n";
			return ;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j])
			{
				cout << "graph\n";
				return ;
			}
		}
	}
	cout << "tree\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	int sw;
	int start;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		sw = 0;
		start = -1;
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < m; j++)
		{
			cin >> y >> x;
			if (start == -1)
				start = y - 1;
			arr[y - 1][x - 1]++;
			arr[x - 1][y - 1]++;
			if (arr[y - 1][x- 1] > 1 || arr[y - 1][x - 1] > 1)
				sw = 1;
		}
		if (sw)
		{
			cout << "graph\n";
			continue;
		}
		else
		{
			visited[start] = 1;
			dfs(start);
			check_tree();
		}
	}
}