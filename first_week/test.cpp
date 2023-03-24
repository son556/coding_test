#include "test.hpp"

//제출 시  #include <bits/stdc++.h>
using namespace std;
int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
void print_v(vector<int> b)
{
	for (int i : b)cout << i << " ";
	cout<< '\n';
}
void combi(int start, vector<int> b)
{
	if (b.size() == k)
	{
		print_v(b);
		return ;
	}
	for (int i = start + 1; i < n; i++)
	{
		b.push_back(a[i]);
		combi(i, b);
		b.pop_back();
	}
}

int main(void)
{
	vector<int> b;
	combi(-1, b);
	return (0); 
} //ㅈㅐ구ㅣ 외우기 순서상관없이 뽑는경우