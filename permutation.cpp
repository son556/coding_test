#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[3] = {1, 2, 3};
vector<int> v;

void printV(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

void makePermutation(int n, int r, int depth)
{
	if (r == depth)
	{
		printV(v);
		return ;
	}
	for (int i = depth; i < n; i++)
	{
		swap(v[i], v[depth]);
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}
	return ;
}

int main(void)
{
	for (auto i : a) v.push_back(i);
	makePermutation(3, 3, 0);
}