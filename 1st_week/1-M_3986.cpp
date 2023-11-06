#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

string str;
int num, n, flag, idx;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		flag = 0;
		if (str.length() % 2 == 1)
			continue ;
        stack<char> sck;
        for(char i : str)
        {
            if (sck.size() && sck.top() == i)
                sck.pop();
            else
                sck.push(i);
        }
        if (sck.empty())
            num++;
	}
	cout << num;
}