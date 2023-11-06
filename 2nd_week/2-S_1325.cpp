#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, m_cnt, a, b;
vector<int> vec[10000];
int visited[10000];
vector<int> arr;

void dfs(int s)
{
	cnt++;
	visited[s] = 1;
	if (vec[s].size() == 0)
		return;
	for (int i = 0; i < vec[s].size(); i++)
	{
		if (visited[vec[s][i]]) continue; // 방문처리 중요!!
		dfs(vec[s][i]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i);
		arr.push_back(cnt);
		if (cnt > m_cnt)
			m_cnt = cnt;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == m_cnt)
			cout << i + 1 << ' ';
	}
}