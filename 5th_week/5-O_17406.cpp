#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> arr, cpy;
vector<vector<int>> rot, rotCase;
int visited[100][100];

void rotArr(vector<int> perm)
{
	int s_x, s_y, e_x, e_y, tmp1, tmp2;

	for (int i = 0; i < perm.size(); i++)
	{
		s_y = rot[perm[i]][0] - 1 - rot[perm[i]][2];
		s_x = rot[perm[i]][1] - 1 - rot[perm[i]][2];
		e_y = rot[perm[i]][0] - 1 + rot[perm[i]][2];
		e_x = rot[perm[i]][1] - 1 + rot[perm[i]][2];
		memset(visited, 0, sizeof(visited));
		while (1)
		{
			if (s_y == e_y && s_x == e_x) break;
			if (visited[s_y][s_x] || visited[e_y][e_x]) break;
			tmp2 = arr[s_y][s_x];
			visited[s_y][s_x] = 1;
			for (int i = s_x; i < e_x; i++)
			{
				tmp1 = arr[s_y][i + 1];
				arr[s_y][i + 1] = tmp2;
				visited[s_y][i + 1] = 1;
				tmp2 = tmp1;
			}
			for (int i = s_y; i < e_y; i++)
			{
				tmp1 = arr[i + 1][e_x];
				arr[i + 1][e_x] = tmp2;
				visited[i + 1][e_x] = 1;
				tmp2 = tmp1;
			}
			for (int i = e_x; i > s_x; i--)
			{
				tmp1 = arr[e_y][i - 1];
				arr[e_y][i - 1] = tmp2;
				tmp2 = tmp1;
				visited[e_y][i - 1] = 1;
			}
			for (int i = e_y; i > s_y; i--)
			{
				tmp1 = arr[i - 1][s_x];
				arr[i - 1][s_x] = tmp2;
				visited[i - 1][s_x] = 1;
				tmp2 = tmp1;
			}
			s_x++;
			s_y++;
			e_x--;
			e_y--;
		}
	}
}

void permut(int n, int r, int depth, vector<int> v)
{
	if (depth == r)
	{
		rotCase.push_back(v);
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(v[i], v[depth]);
		permut(n, r, depth + 1, v);
		swap(v[i], v[depth]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	int num;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		b.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			b.push_back(num);
		}
		arr.push_back(b);
	}
	for (int i = 0; i < k; i++)
	{
		b.clear();
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			b.push_back(num);
		}
		rot.push_back(b);
	}
	cpy = arr;
	b.clear();
	for (int i = 0; i < rot.size(); i++)
		b.push_back(i);
	permut(rot.size(), rot.size(), 0, b);
	int res = INT_MAX;
	for (int i = 0; i < rotCase.size(); i++)
	{
		arr = cpy;
		rotArr(rotCase[i]);
		for (int i = 0; i < arr.size(); i++)
		{
			n = 0;
			for (int j = 0; j < arr[i].size(); j++)
				n += arr[i][j];
			if (res > n)
				res = n;
		}
	}
	cout << res << endl;
}