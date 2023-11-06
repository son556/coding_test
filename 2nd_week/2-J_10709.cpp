#include "test.hpp"
//#include <bits/stdc++.h>
using namespace std;

int h, w, len;
string str, temp_str;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		cin >> str;
		len = str.length();
		for (int j = 0; j < w; j++)
		{
			temp_str = str.substr(0, len - (len - 1 - j));
			reverse(temp_str.begin(), temp_str.end());
			if (temp_str.find('c') != string::npos)
				cout << temp_str.find('c') << ' ';
			else
				cout << -1 << ' ';
		}
		cout << '\n';
	}
}
