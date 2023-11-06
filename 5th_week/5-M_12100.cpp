#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int res, n;

int find_max(int arr[][20])
{
	int tmp = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > tmp)
				tmp = arr[i][j];
		}
	}
	return tmp;
}

void display_arr(int arr[][20])
{
	cout << "----------------arr---------------\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << "----------------end---------------\n";
	cout << '\n';
}

void move_u(int arr[][20])
{
	deque<int> d;
	deque<int> d2;
	int num = 0, tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d.size() == 0 && arr[j][i])
				d.push_back(arr[j][i]);
			else if (arr[j][i])
			{
				if (arr[j][i] == d.back())
				{
					d.back() = arr[j][i] * 2;
					while (d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
				}
				else
				{
					while(d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
					d.push_back(arr[j][i]);
				}
			}
		}
		while (d.size())
		{
			d2.push_back(d.front());
			d.pop_front();
		}
		int idx = 0;
		while (idx < n)
		{
			if (d2.size())
			{
				arr[idx][i] = d2.front();
				d2.pop_front(); 
			}
			else
				arr[idx][i] = 0;
			idx++;
		}
	}
}

void move_d(int arr[][20])
{
	deque<int> d;
	deque<int> d2;
	int num = 0, tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > -1; j--)
		{
			if (d.size() == 0 && arr[j][i])
				d.push_back(arr[j][i]);
			else if (arr[j][i])
			{
				if (arr[j][i] == d.back())
				{
					d.back() = arr[j][i] * 2;
					while (d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
				}
				else
				{
					while(d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
					d.push_back(arr[j][i]);
				}
			}
		}
		while (d.size())
		{
			d2.push_back(d.front());
			d.pop_front();
		}
		int idx = n - 1;
		while (idx > -1)
		{
			if (d2.size())
			{
				arr[idx][i] = d2.front();
				d2.pop_front();
			}
			else
				arr[idx][i] = 0;
			idx--; 
		}
	}
}

void move_r(int arr[][20])
{
	deque<int> d;
	deque<int> d2;
	int num = 0, tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > -1; j--)
		{
			if (d.size() == 0 && arr[i][j])
				d.push_back(arr[i][j]);
			else if (arr[i][j])
			{
				if (arr[i][j] == d.back())
				{
					d.back() = arr[i][j] * 2;
					while (d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
				}
				else
				{
					while(d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
					d.push_back(arr[i][j]);
				}
			}
		}
		while (d.size())
		{
			d2.push_back(d.front());
			d.pop_front();
		}
		int idx = n - 1;
		while (idx > -1)
		{
			if (d2.size())
			{
				arr[i][idx] = d2.front();
				d2.pop_front();
			}
			else
				arr[i][idx] = 0;
			idx--;
		}
	}
}

void move_l(int arr[][20])
{
	deque<int> d;
	deque<int> d2;
	int num = 0, tmp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d.size() == 0 && arr[i][j])
				d.push_back(arr[i][j]);
			else if (arr[i][j])
			{
				if (arr[i][j] == d.back())
				{
					d.back() = arr[i][j] * 2;
					while (d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
				}
				else
				{
					while(d.size())
					{
						d2.push_back(d.front());
						d.pop_front();
					}
					d.push_back(arr[i][j]);
				}
			}
		}
		while (d.size())
		{
			d2.push_back(d.front());
			d.pop_front();
		}
		int idx = 0;
		while (idx < n)
		{
			if (d2.size())
			{
				arr[i][idx] = d2.front();
				d2.pop_front();
			}
			else
				arr[i][idx] = 0;
			idx++; 
		}
	}
}


void move_all(int arr[][20], int num)
{
	if (num == 0)
		move_u(arr);
	else if (num == 1)
		move_d(arr);
	else if (num == 2)
		move_l(arr);
	else
		move_r(arr);
}

void dfs(int tmp)
{
	int max_n;
	int temp[20][20];

	if (tmp == 5)
	{
		max_n = find_max(arr);
		res = max(res, max_n);
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		memcpy(temp, arr, sizeof(arr));
		display_arr(arr);
		display_arr(temp);
		cout << endl << endl;
		move_all(arr, i);
		dfs(tmp + 1);
		memcpy(arr, temp, sizeof(temp));
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dfs(0);
	cout << res;
}
