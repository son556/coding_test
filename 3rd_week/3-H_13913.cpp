#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, flag;
int MAX = 2000000;
int visited[2000004];
int way[2000004]; // way라는 배열에 직접 업데이트

void bfs(int start, int depth)
{
	queue<pair<int, int>> q;
	vector<int>bisit;
	int d, sw, s;
	q.push({start, depth});
	way[start] = -1;
	visited[start] = 1;
	d = depth;
	sw = 0;
	while (q.size())
	{
		tie(s, d) = q.front();
		q.pop();
		if (s == k)
		{
			if (sw == 0)
				sw = 1;
			cnt = d;
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
						visited[i] = 1;
						q.push({i, d});
						way[i] = s;
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
	bfs(n, 0);
	cout << cnt << '\n';
	int s = k;
	stack<int> box;
	while (1)
	{
		if (way[s] == -1)
			break;
		box.push(s);
		s = way[s];
	}
	box.push(n);
	while (box.size())
	{
		s = box.top();
		box.pop();
		cout << s << ' ';
	}
}