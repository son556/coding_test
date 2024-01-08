//7-M 16235

#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n, m, k;
deque<int> tree[14][14];
vector<vector<int> > arr;
int bat[10][10];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void springSummer() {
	deque<int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp.clear();
			int die = 0;
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (bat[i][j] >= tree[i][j][k]) {
					bat[i][j] -= tree[i][j][k];
					temp.push_back(tree[i][j][k] + 1);
				}
				else die += tree[i][j][k] / 2;
			}
			tree[i][j] = temp;
			bat[i][j] += die;
		}
	}
}


void fall() {
	int ny, nx, si;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			si = tree[i][j].size();
			for (int k = 0; k < si; k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int h = 0; h < 8; h++) {
						ny = i + dy[h];
						nx = j + dx[h];
						if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
						tree[ny][nx].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) bat[i][j] += arr[i][j];
	}
}

void go() {
	int cnt = 0;
	int year = 0;
	while (year != k) {
		springSummer();
		fall();
		winter();
		year++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cnt += tree[i][j].size();
	}
	cout << cnt << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	vector<int> b;
	int x, y, z;
	for (int i = 0; i < n; i++) {
		b.clear();
		for (int j = 0; j < n; j++) {
			cin >> x;
			b.push_back(x);
		}
		arr.push_back(b);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) bat[i][j] = 5;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
		sort(tree[x - 1][y - 1].begin(), tree[x - 1][y - 1].end());
	}
	go();
}