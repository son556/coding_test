#include "./test.hpp"

// #include <bits/stdc++.h>
using namespace std;
int idx, total, a, b, c, arr[101];

vector<int> time_in;
vector<int> time_out;
vector<int> fee;

int main(void)
{
	cin >> a >> b >> c;
	fee.push_back(a);
	fee.push_back(b);
	fee.push_back(c);
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		time_in.push_back(a);
		time_out.push_back(b);
	}
	total = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i >= time_in[0] && i < time_out[0])
			arr[i] += 1;
		if (i >= time_in[1] && i < time_out[1])
			arr[i] += 1;
		if (i >= time_in[2] && i < time_out[2])
			arr[i] += 1;
	}
	for (int i = 1; i < 101; i++)
	{
		total += arr[i] * fee[arr[i] - 1];
	}
	cout << total;
}