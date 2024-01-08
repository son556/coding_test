//7-P_17837

#include "test.hpp"
// #include <bits/stdc++.h>

using namespace std;

int a, b, ta, tb;
int res = INT_MAX;
map<pair<int, int>, int> book;

void fillBottle(int &t, int idx) {
	if (idx == 0) t = a;
	else t = b;
}

void emptyBottle(int &t) {
	t = 0;
}

void moveBottle(int &t, int &d, int d_idx) {
	int g;
	if (d_idx == 0) g = a - d;
	else g = b - d;
	if (g >= t) {
		d += t;
		t = 0;
	}
	else {
		t -= g;
		if (d_idx == 0) d = a;
		else d = b;
	}
}

void go(int x, int y, int cnt) {
	queue<vector<int> > q;
	vector<int> b, tmp;
	book[{0, 0}] = 1;
	q.push(vector<int>(3, 0));
	while (q.size()) {
		b = q.front();
		q.pop();
		if (b[0] == ta && b[1] == tb) {
			res = b[2];
			return;
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		fillBottle(tmp[0], 0);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		fillBottle(tmp[1], 1);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		emptyBottle(tmp[0]);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		emptyBottle(tmp[1]);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		moveBottle(tmp[0], tmp[1], 1);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
		tmp = b;
		tmp[2] = b[2] + 1;
		moveBottle(tmp[1], tmp[0], 0);
		if (book.find({tmp[0], tmp[1]}) == book.end()) {
			book[{tmp[0], tmp[1]}] = 1;
			q.push(tmp);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> ta >> tb;
	go(0, 0, 0);
	if (res == INT_MAX) res = -1;
	cout << res << endl;
}