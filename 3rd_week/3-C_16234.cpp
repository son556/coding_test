#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, l, r, cnt, flag;
int arr[54][54], visited[54][54];
int total;
vector< pair<int,int> >v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
	int ny, nx, g;
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
			if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
			if (visited[ny][nx]) continue;
			g = abs(arr[y][x] - arr[ny][nx]);
			if (g < l || g > r) continue;
			visited[ny][nx] = 1;
			v.push_back({ny, nx});
			q.push({ny, nx});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	flag = 1;
	while (flag)
	{
		flag = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				v.clear();
				if (visited[i][j] == 0)
					bfs(i, j);
				if (v.size())
				{
					flag = 1;
					v.push_back({i, j});
					total = 0;
					for (int k = 0; k < v.size(); k++)
						total += arr[v[k].first][v[k].second];
					total /= v.size();
					for (int k = 0; k < v.size(); k++)
						arr[v[k].first][v[k].second] = total;
				}
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt;
}