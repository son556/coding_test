#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

string str, refer = "0123456789";
vector<string> v;
int n, num, idx, len, sw, temp;

int find_real_idx(string str_r)
{
	int idx_t;
	idx_t = 0;
	for (int i = 0; i < str_r.length(); i++)
	{
		if (str_r[i] == '0' && str_r.length() > 1)
			idx_t++;
		else
			break;
		if (i == str_r.length() - 1 && str_r[i] == '0')
			idx_t--;
	}
	return (idx_t);
}

bool compare(string s1, string s2)
{
	if (s1.length() != s2.length())
		return (s1.length() < s2.length());
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
				return (s1[i] < s2[i]);
		}
	}
	return (s1 < s2);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		sw = 0;
		len = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (refer.find(str[j]) != string::npos)
			{
				if (sw == 0)
					idx = j;
				len++;
				sw = 1;
				if (j == str.length() - 1)
				{
					temp = find_real_idx(str.substr(idx, len));
					idx += temp;
					len -= temp;
					v.push_back(str.substr(idx, len));
				}

			}
			else
			{
				if (sw)
				{
					temp = find_real_idx(str.substr(idx, len));
					idx += temp;
					len -= temp;
					v.push_back(str.substr(idx, len));
				}
				sw = 0;
				len = 0;
			}
		}
	}
	sort(v.begin(), v.end(), compare);
	for (auto i : v) cout << i << '\n';
}