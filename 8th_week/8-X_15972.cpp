#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int tank[1000][1000][4];
int height[1000][1000];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
int n, m, h;

void inque(int hi, int y, int x) {
	if (height[y][x] > hi) {
		height[y][x] = hi;
    	pque.push({hi, y * 1000 + x});
	}
}


void displayH() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << height[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void displayT() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "[ ";
			for (int k = 0; k < 4; k++)
				cout << tank[i][j][k] << ' ';
			cout << " ] ";
		}
		cout << endl;
	}
	cout << endl;
}

void outgaro() {
	for (int i = 0; i < m; i++) {
		if (tank[0][i][0] != -1)
			inque(tank[0][i][0], 0, i);
		if (tank[n - 1][i][2] != -1)
			inque(tank[n - 1][i][2], n - 1, i);
	}
}

void outsero() {
	for (int i = 0; i < n; i++) {
		if (tank[i][0][3] != -1)
			inque(tank[i][0][3], i, 0);
		if (tank[i][m - 1][1] != -1)
			inque(tank[i][m - 1][1], i, m - 1);
	}
}

void dijkstra() {
	int offset, hx, hy, ny, nx, d;
	while (pque.size()) {
		hy = pque.top().second / 1000;
		hx = pque.top().second % 1000;
		offset = pque.top().first;
		pque.pop();
		if (height[hy][hx] != offset) continue;
		for (int i = 0; i < 4; i++) {
			if (tank[hy][hx][i] == -1) continue;
			ny = hy + dy[i];
			nx = hx + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			d = max(tank[hy][hx][i], offset);
			if (height[ny][nx] > d) {
				height[ny][nx] = d;
				pque.push({d, ny * 1000 + nx});
			}
		}
	}
}


int check() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			res += height[i][j];
	}
	return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    fill(&height[0][0], &height[0][0] + 1000 * 1000, h);
    int num;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            if (i == 0)
                tank[i][j][0] = num;
            else if (i == n)
                tank[i - 1][j][2] = num;
            else {
                tank[i][j][0] = num;
                tank[i - 1][j][2] = num;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> num;
            if (j == 0)
                tank[i][j][3] = num;
            else if (j == m)
                tank[i][j - 1][1] = num;
            else {
                tank[i][j][3] = num;
                tank[i][j - 1][1] = num;
            }
        }
    }
	outgaro();
	outsero();
	dijkstra();
	cout << check() << '\n';
}