#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
string str;
string refer;
int sw;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	refer = "aeiou";
	while (1)
	{
		cin >> str;
		if (str.compare("end") == 0)
			break ;
		if (str.find("a") == string::npos && str.find("e") == string::npos && \
			str.find("i") == string::npos && str.find("o") == string::npos && \
			str.find("u") == string::npos) {
				cout << '<' << str << "> is not acceptable.\n";
				continue;
		}
		sw = 0;
		stack<char> box;
		for (auto i : str)
		{
			if (refer.find(i) != string::npos)
			{
				if (sw < 0)
					sw = 0;
				sw++;
			}
			else
			{
				if (sw > 0)
					sw = 0;
				sw--;
			}
			if (sw == 3 || sw == -3)
				break ;
			if (box.size() == 0)
				box.push(i);
			else
			{
				if (box.top() == i && i != 'e' && i != 'o')
				{
					sw = -1000;
					break;
				}
				else
					box.push(i);
			}
		}
		if (sw == 3 || sw == -3 || sw == -1000)
		{
			cout << '<' << str << "> is not acceptable.\n";
			continue;
		}
		else
			cout << '<' << str << "> is acceptable.\n";
	}
}