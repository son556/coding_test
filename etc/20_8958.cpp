#include "test.hpp"

// #include <bits/stdc++.h>
using namespace std; 

int n, k;

int check(string str) {
	int res = 0, tmp = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'O') {
			tmp++;
			res += tmp;
		}
		else tmp = 0;
	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		cout << check(str) << endl;
	}
	return 0;
}