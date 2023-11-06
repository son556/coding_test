#include "./test.hpp"
// #include <bits/stdc++.h>
using namespace std;

int arr[26], idx;
std::string str;

int main()
{
	for (int i = 0; i < 26; i++)
		arr[i] = 0;
	cin >> str;
	idx = -1;
	while (str[++idx])
		arr[str[idx] - 97]++;
	for (int i = 0; i < 26; i++)
		cout << arr[i] << ' ';
}