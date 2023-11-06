#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, k, t , cnt, p, way;
int MAX = 2000000;
int visited[2000004];
int move[] = {-1, 1, 2};

void bfs(int start)
{
	queue<pair<int, int>> q;
	vector<int> bisit;
	int d, sw, s, pre_d;
	d = 0;
	pre_d = 0;
	q.push({start, d});
	visited[start] = 1;
	sw = 0;
	while (q.size())
	{
		tie(s, d) = q.front();
		q.pop();
		if (pre_d != d)
		{
			pre_d = d;
			for (int i = 0; i < bisit.size(); i++)
				visited[bisit[i]] = 1;
			bisit.clear();
		}
		if (s == k)
		{
			cnt = d;
			if (sw == 0)
				sw = 1;
			way++;
		}
		if (sw == 0)
		{
			d++;
			for (int i : {s - 1, s + 1, s * 2})
			{
				if (i >= 0 && i <= MAX)
				{
					if (visited[i] == 0)
					{
						bisit.push_back(i);
						q.push({i, d});
					}
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	p = n;
	if (n != k)
		bfs(p);
	cout << cnt << '\n';
	if (n != k)
		cout << way;
	else
		cout << 1;
}