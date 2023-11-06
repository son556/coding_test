#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
int n, c, num, idx;
vector<pair<int, int>> arr;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (m[a.first] == m[b.first])
		return a.second < b.second;
	return m[a.first] > m[b.first];
	//return m[a] > m[b]; 얘만 사용 할 경우 같은 경우가 보장이 안됨
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (m.find(num) == m.end())
		{
			arr.push_back({num, idx});
			idx++;
		}
		m[num]++;
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < m[arr[i].first]; j++)
			cout << arr[i].first << ' ';
	}
}