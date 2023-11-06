#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = -1, tmp_cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[24][24], alp[26];
vector<string> vec;
string str;

void dfs(int y, int x)
{
	int ny, nx;
	cnt = max(cnt, tmp_cnt);
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx]) continue;
		if (alp[vec[ny][nx] - 'A']) continue;
		alp[vec[ny][nx] - 'A'] = 1;
		visited[ny][nx] = 1;
		tmp_cnt++;
		dfs(ny, nx);
		tmp_cnt--;
		visited[ny][nx] = 0;
		alp[vec[ny][nx] - 'A'] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		vec.push_back(str);
	}
	visited[0][0] = 1;
	alp[vec[0][0] - 'A'] = 1;
	tmp_cnt = 1;
	dfs(0, 0);
	cout << cnt;
}