#include "test.hpp"
// 1. 전치행렬을 만들어 같은 로직을 두번 사용하게 한다.
// 2. 값이 차이 나는 부분을 알맞게 초기화.
//#include <bits/stdc++.h>
using namespace std;
int arr[104][104], t_arr[104][104], ret;
int cnt;
int n, l;

void solve(int a[104][104])
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1])cnt++;
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return ;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			t_arr[j][i] = arr[i][j];
		}
	}
	solve(arr);
	solve(t_arr);
	cout << ret;
	return 0;
}
