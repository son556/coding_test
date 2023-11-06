#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
int arr;
int n, m;
string str;

void add_(int idx)
{
	if ((arr & (1 << idx)) == 0)
		arr |= (1 << idx);
}

void remove_(int idx)
{
	if (arr & (1 << idx))
		arr ^= (1 << idx);
}

int check_(int idx)
{
	if (arr & (1 << idx))
		return 1;
	return 0;
}

void toggle_(int idx)
{
	if (arr & (1 << idx))
		arr ^= (1 << idx);
	else
		arr |= (1 << idx);
}

void all_()
{
	arr = ~(1 << 20);
}

void empty_()
{
	arr = 0;
}

void cmd_check_()
{
	string tmp , tmp2;
	int sw = 0;
	tmp = "";
	tmp2 = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			sw = 1;
		if (sw == 0)
			tmp += str[i];
		else if (sw == 1 && str[i] != ' ')
			tmp2 += str[i];
	}
	str = tmp;
	if (tmp2.length() > 0)
		m = stoi(tmp2) - 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		cmd_check_();
		if (str.compare("add") == 0)
			add_(m);
		else if (str.compare("remove") == 0)
			remove_(m);
		else if (str.compare("check") == 0)
			cout << check_(m) << '\n';
		else if (str.compare("toggle") == 0)
			toggle_(m);
		else if (str.compare("all") == 0)
			all_();
		else if (str.compare("empty") == 0)
			empty_();
	}
	return 0;
}