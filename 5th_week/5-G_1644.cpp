#include "test.hpp"
// #include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<int> vec, tmp;
using namespace std;

int number = 4000000;
int primeNum[4000001];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
        primeNum[i] = i;

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
            vec.push_back(i);
    }
}

int main()
{
	cin >> n;
	primeNumberSieve();
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] <= n)
			tmp.push_back(vec[i]);
		else
			break;
	}
	int start = 0, end = 0;
	long long res;
	while (start <= end)
	{
		if (end >= tmp.size())
			break;
		res = 0;
		for (int i = start; i <= end; i++)
			res += tmp[i];
		if (res == n)
		{
			cnt++;
			start++;
		}
		else if(res < n)
			end++;
		else
			start++;
	}
	cout << cnt << endl;
}