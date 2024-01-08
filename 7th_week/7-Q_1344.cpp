#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int arr[100];
double p1, p2;
double dp[20][20][20];

double go(int x, int y, int cnt) {
	if (cnt == 18) {
		if (arr[x] == 0 || arr[y] == 0) return 1.0;
		return 0.0;
	}
	double &ret = dp[cnt][x][y];
	if (ret > -0.5) return ret;
	ret = 0.0;
	ret += go(x + 1, y, cnt + 1) * p1 * (1 - p2);
	ret += go(x, y + 1, cnt + 1) * (1 - p1) * p2;
	ret += go(x + 1, y + 1, cnt + 1) * p1 * p2;
	ret += go(x, y, cnt + 1) * (1 - p1) * (1- p2);
	return ret; 
}

void eratos(int num) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i * i <= num; i++) {
		for (int k = i * i; k <= num; k += i)
			arr[k] = 1;
	}
}

int main() {
	cin >> p1 >> p2;
	p1 /= 100.0;
	p2 /= 100.0;
	eratos(20);
	memset(dp, -1, sizeof(dp));
	cout.precision(6);
	cout << go(0, 0, 0) << endl;
    return 0;
}