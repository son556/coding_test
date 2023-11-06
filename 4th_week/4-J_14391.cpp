#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, m;
string arr[4], str;
int visited[4][4], ret, visited_[4][4];

int cnt_num(int y, int x)
{
	queue<pair<int, int>> q;
	int ny, nx, flag = 0;
	if (visited[y][x])
		flag = 1;
	q.push({y, x});
	while (q.size())
	{
		tie(y, x) = q.front();
		str += arr[y][x];
		q.pop();
		if (flag)
		{
			nx = x + 1;
			ny = y;
		}
		else
		{
			nx = x;
			ny = y + 1;
		}
		if (ny >= n || nx >= m || visited_[ny][nx]) continue;
		if (flag && visited[ny][nx] == 0) continue;
		if (flag == 0 && visited[ny][nx]) continue;
		visited_[ny][nx] = 1;
		q.push({ny, nx});
	}
	return stoi(str);
}

void cnt_total()
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited_[i][j] == 0)
			{
				str = "";
				visited_[i][j] = 1;
				total += cnt_num(i, j);
			}
		}
	}
	ret = max(total, ret);
	memset(visited_, 0, sizeof(visited_));
}

void visit_check(int cnt)
{
	if (cnt == n)
	{
		cnt_total();
		return ;
	}
	for (int i = 0; i < (1 << m); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
				visited[cnt][j] = 1;
		}
		visit_check(cnt + 1);
		for (int j = 0; j < m; j++) visited[cnt][j] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	visit_check(0);
	cout << ret;
}