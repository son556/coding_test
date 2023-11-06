#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m, k, cnt;
vector<int> vec, con;
int res, idx, sw;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		vec.push_back(k);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (con.size() < n)
		{
			idx = 0;
			for (int j = 0; j < con.size(); j++)
			{
				if (con[j] == vec[i])
				{
					idx = 1;
					break;
				}
			}
			if (idx) continue;
			con.push_back(vec[i]);
		}
		else
		{
			idx = 0;
			for (int j = 0; j < con.size(); j++)
			{
				if (con[j] == vec[i])
				{
					idx = -1;
					break;
				}
			}
			if (idx == -1)
				continue;
			cnt = -1;
			for (int j = 0; j < con.size(); j++)
			{
				sw = 0;
				for (int k = i + 1; k < vec.size(); k++)
				{
					if (vec[k] == con[j])
					{
						sw = 1;
						if (k > cnt)
						{
							cnt = k;
							idx = j;
						}
						break;
					}
				}
				if (sw == 0)
				{
					idx = j;
					break;
				}
			}
			con[idx] = vec[i];
			res++;
		}
	}
	cout << res << endl;
}