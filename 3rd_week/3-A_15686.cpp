#include "test.hpp"

//#include<bits/stdc++.h>

using namespace std;

int n, m, h_cnt, c_cnt;
int arr[54][54];
int home[54][2], chicken[54][2];
vector<vector<int>> v;
int r = INT_MAX;

void combi(int start, vector<int>b)
{
	if (b.size() == m)
	{
		v.push_back(b);
		return ;
	}
	for (int i = start + 1; i < c_cnt; i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return ;
}

void r_check()
{
	int total, total2, rr;
	for (int i = 0; i < v.size(); i++)
	{
		total = 0;
		for (int j = 0; j < h_cnt; j++)
		{
			total2 = INT_MAX;
			for (int k = 0; k < m; k++)
			{
				rr = abs(home[j][0] - chicken[v[i][k]][0]) + abs(home[j][1] - chicken[v[i][k]][1]);
				if (total2 > rr)
					total2 = rr;
			}
			total += total2;
		}
		if (r > total)
			r = total;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				home[h_cnt][0] = i;
				home[h_cnt][1] = j;
				h_cnt++;
			}
			else if (arr[i][j] == 2)
			{
				chicken[c_cnt][0] = i;
				chicken[c_cnt][1] = j;
				c_cnt++;
			}
		}
	}
	vector<int> b;
	combi(-1, b);
	r_check();
	cout << r;
}