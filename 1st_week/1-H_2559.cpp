#include "test.hpp"
// #include <bits/stdc++.h>

using namespace std;
int N, K, num, total, temp;

int main()
{
	N = 0; K = 0; num = 0; total = 0; temp = 0;
	// ios::sync_with_stdio(false); // 사용시 cin cout만 사용해야함
	// cin.tie(NULL);
	// cout.tie(NULL);
	cin >> N >> K;
	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < K; i++)
		num += arr[i];
	temp = num;
	if (N != K)
	{
		for (int i = 1; i < N; i++)
		{
			total = temp - arr[i - 1] + arr[i + K - 1];
			temp = total;
			if (total > num)
				num = total;
			if (i + K - 1 == N - 1)
				break ;
		}
	}
	cout << num;
}
