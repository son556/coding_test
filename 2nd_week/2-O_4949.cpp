#include "test.hpp"

//#include <bits/stdc++.h> //문자열 짝 맞추는 문제는 스택을 이용하자
using namespace std;

string str;
int sw, cnt1, cnt2;
int s, e, mod, tmp_cnt;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		getline(cin, str);
		if (str.compare(".") == 0)
			break;
		stack<char> box;
		for (int i = 0; i < str.length(); i++)
		{
			if (box.size() == 0)
			{
				if (str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] == ']')
					box.push(str[i]);
			}
			else if (str[i] == '(')
				box.push(str[i]);
			else if (str[i] == ')')
			{
				if (box.top() == '(')
					box.pop();
				else
					box.push(str[i]);
			}
			else if (str[i] == '[')
				box.push(str[i]);
			else if (str[i] == ']')
			{
				if (box.top() == '[')
					box.pop();
				else
					box.push(str[i]);
			}
		}
		if (box.size() > 0)
			cout << "no\n";
		else
			cout << "yes\n";
	}
}