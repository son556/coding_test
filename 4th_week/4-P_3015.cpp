#include "test.hpp"
/*
문제점
	스택을 사용하여 n ^ 2 보다 줄이는 경우가 생각이 안남

tip) 쌍의 수, 짝짓기, 폭발 -> 스택을 사용해보자

오름차순으로만 혹은 내림차순으로만 이루어져 있는 경우 짝은 n - 1 개
모두가 크기가 같을 때 1 + 2 + ... + n - 1 개
예를 들어 크가가 4 3 2 1 6 ... 이렇게 들어온다면 6 앞의 쌍은 6뒤의 쌍에 영향을 못줌 (핵심)

1. 스택의 최상단 보다 큰 수가 온 경우: 스택에 들어있는 것들을 전부 제거 하며 cnt++
2. 스택의 최상단 수와 같은 수가 온 경우: 최상단 수를 cnt에 더해주고 넣는 수에 최상단의 수 + 1을 같이
	넣어줘서 누적시킴
3. 스택의 최상단 보다 작은 수가 온경우: 스택에 <크기, 1> 을 넣어줌 
4. 스택에 수가 남아있는 경우 cnt를 1 증가 (내림차순인 경우의 짝을 셈 전부 내림차순인 경우 1번인덱스 부터 cnt하기 때문에)
*/

//#include <bits/stdc++.h>
using namespace std;

long int n, arr[500000], cnt;
stack<pair<int ,int >>	stk;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 1;
		cin >> arr[i];
		while (stk.size() && stk.top().first <= arr[i])
		{
			cnt += stk.top().second;
			if (stk.top().first == arr[i])
				temp = stk.top().second + 1;
			else
				temp = 1;
			stk.pop();
		}
		if (stk.size())
			++cnt;
		stk.push(make_pair(arr[i], temp));
	}
	cout << cnt;
}