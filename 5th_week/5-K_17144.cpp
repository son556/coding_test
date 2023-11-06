#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr, mmunzi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int res, r, c, t, mise;
vector<int> co;

void displayArr()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void go(int y, int x, vector<int> v)
{
	int ny, nx, cnt;

	cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0) continue;
		if (arr[ny][nx] == -1) continue;
		v.clear();
		v.push_back(ny);
		v.push_back(nx);
		v.push_back(arr[y][x] / 5);
		mmunzi.push_back(v);
		cnt++;
	}
	arr[y][x] = arr[y][x] - cnt * (arr[y][x] / 5);
}

void go_mise()
{
	queue<pair<int, int>> munzi;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] >= 5)
				munzi.push({i, j});
		}
	}
	mmunzi.clear();
	while (munzi.size())
	{
		vector<int> mun;
		go(munzi.front().first, munzi.front().second, mun);
		munzi.pop();
	}
	for (int i = 0; i < mmunzi.size(); i++)
		arr[mmunzi[i][0]][mmunzi[i][1]] += mmunzi[i][2];
}

void go_filter()
{
	int f_y, s_y, tmp, tmp2;
	f_y = co[0];
	s_y = co[2];
	
	for (int i = 0; i < c - 1; i++)
	{
		if (arr[f_y][i] == -1)
		{
			tmp = arr[f_y][i + 1];
			arr[f_y][i + 1] = 0;
			continue;
		}
		tmp2 = arr[f_y][i + 1];
		arr[f_y][i + 1] = tmp;
		tmp = tmp2;
	}
	for (int i = f_y; i > 0; i--)
	{
		tmp2 = arr[i - 1][c - 1];
		arr[i - 1][c - 1] = tmp;
		tmp = tmp2;
	}
	for (int i = c - 1; i > 0; i--)
	{
		tmp2 = arr[0][i - 1];
		arr[0][i - 1] = tmp;
		tmp = tmp2;
	}
	for (int i = 0; i < f_y; i++)
	{
		if (arr[i + 1][0] == -1)
		{
			tmp = 0;
			continue;
		}
		tmp2 = arr[i + 1][0];
		arr[i + 1][0] = tmp;
		tmp = tmp2;
	}

	for (int i = 0; i < c - 1; i++)
	{
		if (arr[s_y][i] == -1)
		{
			tmp = arr[s_y][i + 1];
			arr[s_y][i + 1] = 0;
			continue;
		}
		tmp2 = arr[s_y][i + 1];
		arr[s_y][i + 1] = tmp;
		tmp = tmp2;
	}
	for (int i = s_y; i < r - 1; i++)
	{
		tmp2 = arr[i + 1][c - 1];
		arr[i + 1][c - 1] = tmp;
		tmp = tmp2;
	}
	for (int i = c - 1; i > 0; i--)
	{
		tmp2 = arr[r - 1][i - 1];
		arr[r - 1][i - 1] = tmp;
		tmp = tmp2;
	}
	for (int i = r - 1; i > s_y; i--)
	{
		if (arr[i - 1][0] == -1)
		{
			tmp = 0;
			continue;
		}
		tmp2 = arr[i - 1][0];
		arr[i - 1][0] = tmp;
		tmp = tmp2;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> t;
	vector<int> b;
	for (int i = 0; i < r; i++)
	{
		b.clear();
		for (int j = 0; j < c; j++)
		{
			cin >> mise;
			if (mise == -1)
			{
				co.push_back(i);
				co.push_back(j);
			}
			b.push_back(mise);
		}
		arr.push_back(b);
	}
	int timer = 0;
	while (timer < t)
	{
		go_mise();
		go_filter();
		timer++;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == -1) continue;
			res += arr[i][j];
		}
	}
	cout << res << endl;
	return 0;
}