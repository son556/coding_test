#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maps;
int visited[100][100];
vector<pair<int, char>> moving;
int n, k, l;
int x, y, t_change, t, new_d;
char di;


void go()
{
	queue<pair<int, int>> snakes;

	new_d = 0;
	y = 0;
	x = 0;
	snakes.push({0, 0});
	visited[0][0] = 1;
	while (1)
	{
		if (maps[y][x] == 1)
			maps[y][x] = 0;
		else if (t != 0)
		{
			visited[snakes.front().first][snakes.front().second] = 0;
			snakes.pop();
		}
		if (moving.size() && t == moving[0].first)
		{
			if (new_d == 0)
			{
				if (moving[0].second == 'D')
					new_d = 1;
				else
					new_d = 3;
			}
			else if (new_d == 1)
			{
				if (moving[0].second == 'D')
					new_d = 2;
				else
					new_d = 0;
			}
			else if (new_d == 2)
			{
				if (moving[0].second == 'D')
					new_d = 3;
				else
					new_d = 1;
			}
			else
			{
				if (moving[0].second == 'D')
					new_d = 0;
				else
					new_d = 2;
			}
			moving.erase(moving.begin());
		}
		if (new_d == 0)
			x++;
		else if (new_d == 1)
			y++;
		else if (new_d == 2)
			x--;
		else
			y--;
		t++;
		if (y >= n || y < 0 || x >= n || x < 0) break;
		if (visited[y][x]) break;
		visited[y][x] = 1;
		snakes.push({y, x});
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> b;
	cin >> n;
	for (int i = 0; i < n; i++)
		b.push_back(0);
	for (int i = 0; i < n; i++)
		maps.push_back(b);
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;
		maps[y - 1][x - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> t_change >> di;
		moving.push_back({t_change, di});
	}
	go();
	cout << t << endl;
}