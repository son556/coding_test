#include "test.hpp"
// cctv 표현은 범위를 벗어난 숫자로 표기 할 것

//#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int> > maps, vec;
vector<vector<int> > pp;
int visited[8][8];
int res = INT_MAX;


int camRight(int y, int x) {
	int cnt = 0;
	for (int i = x; i < m; i++) {
		if (maps[y][i] == 6) break;
		cnt++;
		visited[y][i] = 1;
	}
	return cnt;
}

int camLeft(int y, int x) {
	int cnt = 0;
	for (int i = x; i > -1; i--) {
		if (maps[y][i] == 6) break;
		cnt++;
		visited[y][i] = 1;
	}
	return cnt;
}

int camUp(int y, int x) {
	int cnt = 0;
	for (int i = y; i > -1; i--) {
		if (maps[i][x] == 6) break;
		cnt++;
		visited[i][x] = 1;
	}
	return cnt;
}

int camDown(int y, int x) {
	int cnt = 0;
	for (int i = y; i < n; i++) {
		if (maps[i][x] == 6) break;
		cnt++;
		visited[i][x] = 1;
	}
	return cnt;
}

int cam1(int y, int x, int dir) {
	int cnt;
	if (dir == 0)
		cnt = camRight(y, x);
	else if (dir == 1)
		cnt = camDown(y, x);
	else if (dir == 2)
		cnt = camLeft(y, x);
	else
		cnt = camUp(y, x);
	return cnt;
}

int cam2(int y, int x, int dir) {
	int cnt;
	if (dir % 2 == 0)
		cnt = camLeft(y, x) + camRight(y, x);
	else
		cnt = camUp(y, x) + camDown(y, x);
	return cnt;
}

int cam3(int y, int x, int dir) {
	int cnt;

	if (dir == 0)
		cnt = camUp(y, x) + camRight(y, x);
	else if (dir == 1)
		cnt = camRight(y, x) + camDown(y, x);
	else if (dir == 2)
		cnt = camDown(y, x) + camLeft(y, x);
	else
		cnt = camLeft(y, x) + camUp(y, x);
	return cnt;
}

int cam5(int y, int x, int dir) {
	return camUp(y, x) + camDown(y, x) + camLeft(y, x) + camRight(y, x);
}

int cam4(int y, int x, int dir) {
	int cnt = 0;
	if (dir == 0)
		cnt = camUp(y, x) + camRight(y, x) + camLeft(y, x);
	else if (dir == 1)
		cnt = camUp(y, x) + camRight(y, x) + camDown(y, x);
	else if (dir == 2)
		cnt = camRight(y, x) + camLeft(y, x) + camDown(y, x);
	else
		cnt = camLeft(y, x) + camUp(y, x) + camDown(y, x);
	return cnt;
}

void viMemset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			visited[i][j] = 0;
	}
}

int cntVisit() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && maps[i][j] != 6) cnt++;
		}
	}
	return cnt;
}

void dfs(vector<int> v, int cnt) {
	if (v.size() == cnt) {
		pp.push_back(v);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		dfs(v, cnt);
		v.pop_back();
	}
}

void go(vector<int (*)(int, int, int)> v) {
	int cnt;

	for (int i = 0; i < pp.size(); i++) {
		viMemset();
		for (int j = 0; j < vec.size(); j++)
			v[vec[j][0] - 1](vec[j][1], vec[j][2], pp[i][j]);
		cnt = cntVisit();
		if (res > cnt) res = cnt;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<int> b;
	int x;
	for (int i = 0; i < n; i++) {
		b.clear();
		for (int j = 0; j < m; j++) {
			cin >> x;
			b.push_back(x);
		}
		maps.push_back(b);
	}
	b.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] <= 5 && maps[i][j] >= 1) {
				b.clear();
				b.push_back(maps[i][j]);
				b.push_back(i);
				b.push_back(j);
				vec.push_back(b);
			}
		}
	}
	vector<int(*)(int, int, int)> v;
	v.push_back(cam1);
	v.push_back(cam2);
	v.push_back(cam3);
	v.push_back(cam4);
	v.push_back(cam5);
	b.clear();
	dfs(b, vec.size());
	go(v);
	cout << res << endl;
}