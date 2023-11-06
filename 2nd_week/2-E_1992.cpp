#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

int n;
int arr[64][64];
string str;

void quad_tree(int i, int j, int s)
{
	int num = arr[i][j];
	int ni, nj;
	bool sw;
	if (s == 1)
	{
		cout << num;
		return;
	}
	sw = false;
	for (int a = i; a < i + s; a++)
	{
		for (int b = j; b < j + s; b++)
		{
			if (num != arr[a][b])
			{
				sw = true;
				break ;
			}
		}
		if (sw)
			break;
	}
	if (sw)
	{
		ni = i + s / 2;
		nj = j + s / 2;
		cout << '(';
		quad_tree(i, j, s / 2);
		quad_tree(i, j + s / 2, s / 2);
		quad_tree(i + s / 2, j, s / 2);
		quad_tree(i + s / 2, j + s / 2, s / 2);
		cout << ')';
	}
	else
		cout << num;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			arr[i][j] = str[j] - '0';
	}
	quad_tree(0, 0, n);
}