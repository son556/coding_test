// 7-N 17136
#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int arr[10][10];
int visited[10][10];
vector<int> paper;
vector<vector<int>> vec;
int res = INT_MAX;

bool fillCube (int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (i >= 10 || j >= 10 || arr[i][j] == 0 || visited[i][j]) return false;
		}
	}
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			visited[i][j] = 1;
		}
	}
	return true;
}

void detachCube(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			visited[i][j] = 0;
		}
	}
}

bool checkCube() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] && visited[i][j] == 0) 
				return false;
		}
	}
	return true;
}

pair<int, int> findCube() {
	pair<int, int> p;
	p.first = -1;
	p.second = -1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] && visited[i][j] == 0) {
				p.first = i;
				p.second = j;
				return p;
			}
		}
	}
	return p;
}

void go(vector<int> &v, int cnt) {
	if (v[1] > 5 || v[2] > 5 || v[3] > 5 || v[4] > 5 || v[5] > 5) return;
	if (checkCube()) {
		res = min(res, cnt);
		return;
	}
	pair<int, int> p;
	p = findCube();
	for (int i = 1; i < 6; i++) {
		if (fillCube(p.first, p.second, i) == false) continue;
		v[i]++;
		go(v, cnt + 1);
		v[i]--;
		detachCube(p.first, p.second, i);

	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	}
	vector<int> b(6, 0);
	go(b, 0);
	if (res == INT_MAX) res = -1;
	cout << res << endl;
}