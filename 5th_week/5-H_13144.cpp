#include "test.hpp"
// #include <bits/stdc++.h>
using namespace std;

long long cnt;
int s, e;
int n, m, visited[100004];
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vec.push_back(m);
	}
	while(e < n)
	{
		if(visited[vec[e]] == 0)
		{
			visited[vec[e]]++;
			e++;
		}
		else
		{
			cnt += (e - s);
			visited[vec[s]] = 0;
			s++;
		}
    }
	cnt += (long long)(e - s) * (e - s + 1) / 2;
	cout << cnt;
}