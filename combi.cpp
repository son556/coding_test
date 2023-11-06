#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > v;
int n, m;

void combi(int start, vector<int>b)
{
	if (b.size() == m)
	{
		v.push_back(b);
		return ;
	}
	for (int i = start + 1; i < n; i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}

int main(void)
{
	cin >> n >> m;
	vector<int> b;
	combi(-1, b);
	cout << v.size();
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << ' ';
		cout << endl;
	}
}