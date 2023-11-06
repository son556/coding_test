#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std; 
vector<int>arr;
vector<int>lev[14];
int n;

void inorder(int s, int e, int level)
{
	if (s > e)
		return;
	if (s == e)
	{
		lev[level].push_back(arr[s]);
		return ;
	}
	int mid = (s + e) / 2;
	lev[level].push_back(arr[mid]);
	inorder(s, mid - 1, level + 1);
	inorder(mid + 1, e, level + 1);
	
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int end = pow(2, n) - 1;
	int num;
	for (int i = 0; i < end; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	inorder(0, end, 1);
	for(int i = 1; i <= n; i++)
	{
        for(int j : lev[i])
		{
            cout << j << " ";
        }
        cout << "\n";
    }
}