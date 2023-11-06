#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int arr[100][100], visited[100][100], m, n, k, cnt;
int x_1, y_1, x_2, y_2;
vector<int> s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(int i, int j)
{
	int x, y, nx, ny, cnt_s;
	cnt_s = 1;
	q.push({i, j});
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny >= m || ny < 0 || nx >= n || nx < 0 || arr[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			cnt_s++;
			q.push({ny, nx});
		}
	}
	s.push_back(cnt_s);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int j = y_1; j < y_2; j++)
		{
			for (int l = x_1; l < x_2; l++)
				arr[m - j - 1][l] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	sort(s.begin(), s.end());
	for (auto i : s)
		cout << i << ' ';
}