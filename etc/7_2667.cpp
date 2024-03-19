#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, res, cnt;
vector<vector<int>> arr;
vector<int> answer;
int visited[25][25];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    int ny, nx;
    cnt++;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if (arr[ny][nx] == 0) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string str;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            b.push_back(str[j] - '0');
        }
        arr.push_back(b);
        b.clear();
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (visited[i][j] || arr[i][j] == 0) continue;
            visited[i][j] = 1;
            dfs(i, j);
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}