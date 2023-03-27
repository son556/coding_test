#include "test.hpp"

//제출 시  #include <bits/stdc++.h>
using namespace std;
int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
vector<int> v;

void printV(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

void makePermutation(int n, int r, int depth)
{
	cout << n << " : " << r << " : " << depth << '\n';
	if (r == depth)
	{
		printV(v);
		return;
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
	for (int i = 1; i <=3; i++)v.push_back(i);
	// do
	// {
	// 	printV(v);
	// } while (next_permutation(v.begin(), v.end()));
	makePermutation(5, 3, 0);
	return (0);
} //ㅈㅐ구ㅣ 외우기 순서상관없이 뽑는경우