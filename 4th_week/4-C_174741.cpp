#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> site;
int arr[11], visited[11];
int n, m, cnt = 987654321, num;
vector<vector<int>> vec;
vector<int> a, b;

bool check_site(int s1)
{
	int idx = 1;
	a.clear();
	b.clear();
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i < (1 << n); i *= 2)
	{
		if (s1 & i)
			a.push_back(idx);
		else
			b.push_back(idx);
		idx++;
	}
	int start;
	for (int i = 0; i < b.size(); i++)
		visited[b[i]] = 1;
	start = a[0];
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (q.size())
	{
		start = q.front();
		q.pop();
		for (int i = 0; i < site[start].size(); i++)
		{
			if (visited[site[start][i]]) continue;
			visited[site[start][i]] = 1;
			q.push(site[start][i]);
		}
	}
	for (int i = 0; i < a.size(); i++)
		if (visited[a[i]] == 0)
			return (false);
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < a.size(); i++)
		visited[a[i]] = 1;
	start = b[0];
	q.push(start);
	visited[start] = 1;
	while (q.size())
	{
		start = q.front();
		q.pop();
		for (int i = 0; i < site[start].size(); i++)
		{
			if (visited[site[start][i]]) continue;
			visited[site[start][i]] = 1;
			q.push(site[start][i]);
		}
	}
	for (int i = 0; i < b.size(); i++)
		if (visited[b[i]] == 0)
			return (false);
	return (true);
}

void popul_num()
{
	int total1 = 0, total2 = 0;
	for (int i = 0; i < a.size(); i++)
		total1 += arr[a[i]];
	for (int i = 0; i < b.size(); i++)
		total2 += arr[b[i]];
	cnt = min(cnt, abs(total1 - total2));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<int>b;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	b.push_back(-1);
	site.push_back(b);
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		b.clear();
		for (int j = 1; j <= m; j++)
		{
			cin >> num;
			b.push_back(num);
		}
		site.push_back(b);
	}
	for (int i = 1; i < (1 << n) - 1; i++)
	{
		if (check_site(i))
			popul_num();
	}
	if (cnt == 987654321)
		cout << -1;
	else
		cout << cnt;
}