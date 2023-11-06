#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;
string str;
int **arr;
queue<pair<int, int>> site;

void bfs(int ue, int ve, int **arr, int cnt)
{
	pair<int ,int> temp;

	while (site.size())
	{
		temp.first = site.front().first;
		temp.second = site.front().second;
		site.pop(); 
		if (temp.first + 1 < ue && arr[temp.first + 1][temp.second] == 1)
		{
			arr[temp.first + 1][temp.second] = arr[temp.first][temp.second] + 1;
			site.push(make_pair(temp.first + 1, temp.second));
		}
		if (temp.first - 1 > -1 && arr[temp.first - 1][temp.second] == 1)
		{
			arr[temp.first - 1][temp.second] = arr[temp.first][temp.second] + 1;
			site.push(make_pair(temp.first - 1, temp.second));
		}
		if (temp.second + 1 < ve && arr[temp.first][temp.second + 1] == 1)
		{
			arr[temp.first][temp.second + 1] = arr[temp.first][temp.second] + 1;
			site.push(make_pair(temp.first, temp.second + 1));
		}
		if (temp.second - 1 > -1 && arr[temp.first][temp.second - 1] == 1)
		{
			arr[temp.first][temp.second - 1] = arr[temp.first][temp.second] + 1;
			site.push(make_pair(temp.first, temp.second - 1));
		}
	}
}

int main()
{
	cin >> n >> m;
	arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == '1')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	site.push(make_pair(0, 0));
	bfs(n, m, arr, 0);
	cout << arr[n - 1][m - 1];
}