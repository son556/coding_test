#include "./test.hpp"

// #include <bits/stdc++.h>
using namespace std;

map<string, int> m1;
map<int, string> m2;
//atoi() 함수 (1~) 0인 경우를 주의 할 것것
// 문자열이 숫자 혹은 문자로 들어오는 경우 atoi(str.c_str) 이용
string str;
int n, m, num;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		m1[str] = i + 1;
		m2[i + 1] = str;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if ((num = atoi(str.c_str())) != 0)
			cout << m2[num] << '\n';
		else
			cout << m1[str] << '\n';
	}
}