//7-O_17837
#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
vector<vector<int>> board;
vector<vector<string>> visited;
map<string, vector<int>> status;
int n, k;

bool endGame() {
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[i].size(); j++) {
			if (visited[i][j].size() >= 4) return true;
		}
	}
	return false;
}

void move(string str, int idx) {
	int x = status[str][1];
	int y = status[str][0];
	int ny = y + dy[idx];
	int nx = x + dx[idx];
	if (ny >= n || nx >= n || nx < 0 || ny < 0 || board[ny][nx] == 2) {
		idx = idx ^ 1;
		ny = y + dy[idx];
		nx = x + dx[idx];
		status[str][2] = idx;
		if (ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] == 2) return;
	}
	string tmp, now_str = visited[y][x].substr(visited[y][x].find(str));
	visited[y][x] = visited[y][x].substr(0, visited[y][x].find(str));
	if (visited[y][x].size() == 0) visited[y][x] = ".";
	for (int i = 0; i < now_str.size(); i++) {
		tmp = now_str[i];
		status[tmp][0] = ny;
		status[tmp][1] = nx;
	}
	if (board[ny][nx] == 0) {
		if (visited[ny][nx] == ".") visited[ny][nx] = now_str;
		else {
			visited[ny][nx] += now_str;
		}
	}
	else {
		reverse(now_str.begin(), now_str.end());
		if (visited[ny][nx] == ".") visited[ny][nx] = now_str;
		else {
			visited[ny][nx] += now_str;
		}
	}
}


int go() {
	int cnt = 0;
	int ny, nx;
	while (1) {
		cnt++;
		for (auto it = status.begin(); it != status.end(); it++) {
			move(it->first, (it->second)[2]);
			if (endGame()) return cnt;
		}
		if (cnt > 1000) return -1;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	vector<int> b(n, 0);
	vector<string> c(n, ".");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		board.push_back(b);
		visited.push_back(c);
	}
	int x, y, z;
	string str;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> z;
		str = 'a' + i;
		visited[x - 1][y - 1] = str;
		status[str].push_back(x - 1);
		status[str].push_back(y - 1);
		status[str].push_back(z - 1);
	}
	cout << go() << endl;
}