#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int r, c, cnt;
int spell[26];
char arr[24][24];
string str;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void dfs(int y, int x)
{
	int ny, nx;
	if (y == 0 && x == 0)
		spell[arr[y][x] - 'A'] = 1;
	cnt = max(cnt, spell[arr[y][x] - 'A']);
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0 || spell[arr[ny][nx] - 'A']) continue;
		spell[arr[ny][nx] - 'A'] = spell[arr[y][x] - 'A'] + 1;
		dfs(ny, nx);
		spell[arr[ny][nx] - 'A'] = 0;
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
			arr[i][j] = str[j];
	}
	dfs(0, 0);
	cout << cnt;
}