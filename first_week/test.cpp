#include "test.hpp"

//제출 시  #include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	cout << dq.front() << "\n";
	cout << dq.back() << '\n';
	cout << "size: " << dq.size() << '\n';
	dq.pop_back();
	dq.pop_front();
	cout << dq.size() << dq.front() << "\n";
	return 0;
} // 100