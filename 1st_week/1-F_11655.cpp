#include "./test.hpp"
// #include <bits/stdc++.h>
using namespace std;
string str;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, str);
	for (auto i : str)
	{
		if (i >= 'A' && i <= 'Z')
			cout << (char)(alphabet[(i - 'A' + 13) % 26] - 32);
		else if (i >= 'a' && i <= 'z')
			cout << alphabet[(i - 'a' + 13) % 26];
		else
			cout << i;
	}
	return (0);
}