#include "test.hpp"
/*
해결책
	투포인터
	내 시작위치 끝 위치를 지정 한 후 중복이 없을 때 까지 끝 위치를 이동
	중복된 수를 만나면 현재 만든 수열 중 시작위치를 항상 포함하는 수열의 부분 
	집합 개수를 cnt ex)수열의 길이가 5라면 첫번째 를 항상 포함하는 부분 수열의
	수 = 5 이다. cnt를 더해준다.
	마지막에 남은 수열의 길이를 1개부터 마지막 남은 수열의 길이 까지 전부 cnt해서
	최종 결과에 더해준다.

실마리 => 문제에서 요구하는 수열의 총 합 = 특정원소(가장 앞의 원소) 를 포함하는 수열의 수 + 특정원소를 포함하지 않는 수열의 수
*/

// #include <bits/stdc++.h>
using namespace std;

long long cnt;
int s, e;
int n, m, visited[100004];
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vec.push_back(m);
	}
	while(e < n)
	{
		if(visited[vec[e]] == 0)
		{
			visited[vec[e]]++;
			e++;
		}
		else
		{
			cnt += (e - s);
			visited[vec[s]] = 0;
			s++;
		}
    }
	cnt += (long long)(e - s) * (e - s + 1) / 2;
	cout << cnt;
}