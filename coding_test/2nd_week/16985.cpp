#include "test.hpp"

/*
알고리즘: bfs, 구현

행렬 회전하는 코드 외우기


1. 중복을 허용하는 경우의 수
2. 회전
3. bfs
*/


//#include <bits/stdc++.h>

using namespace std;

int rot[4] = {0, 1, 2, 3};
int vv[5];
int visited[5][5][5];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ud[2] = {-1, 1};
int res = INT_MAX;
vector<vector<int>> rots;
vector<vector<int>> seq;
vector<vector<vector<int>>> arr;

void makeRot(vector<int> &v) {
    if (v.size() == 5) {
        rots.push_back(v);
        return;
    }
    for (int i = 0; i < 4; i++) {
        v.push_back(i);
        makeRot(v);
        v.pop_back();
    }
}

void makeSeq(vector<int> &v) {
    if (v.size() == 5) {
        seq.push_back(v);
        return ;
    }
    for (int i = 0; i < 5; i++) {
        if (vv[i]) continue;
        vv[i] = 1;
        v.push_back(i);
        makeSeq(v);
        vv[i] = 0;
        v.pop_back();
    }
}

vector<vector<int>> rot90(vector<vector<int>> m) {
    vector<vector<int>> answer = m;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            answer[j][4 - i] = m[i][j];
    }
    return answer;
}

void go(int sidx, int ridx) {
    fill(&visited[0][0][0], &visited[0][0][0] + 5 * 5 * 5, INT_MAX);
    vector<vector<vector<int>>> maze = arr;
    for (int i = 0; i < 5; i++)
        maze[i] = arr[seq[sidx][i]];
    vector<vector<int>> temp;
    int num;
    for (int i = 0; i < 5; i++) {
        temp = maze[i];
        num = rots[ridx][i];
        for (int j = 0; j < num; j++)
            temp = rot90(temp);
        maze[i] = temp;
    }
    if (maze[0][0][0] == 0) return;
    queue<pair<int, pair<int, int>>> que;
    int hf, y, x, ny, nx, nf;
    visited[0][0][0] = 1;
    que.push({0, {0, 0}});
    while (que.size()) {
        hf = que.front().first;
        y = que.front().second.first;
        x = que.front().second.second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            nf = hf;
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0) continue;
            if (visited[nf][ny][nx] <= visited[hf][y][x] + 1 || maze[nf][ny][nx] == 0) continue;
            visited[nf][ny][nx] = visited[hf][y][x] + 1;
            que.push({nf, {ny, nx}});
        }
        for (int i = 0; i < 2; i++) {
            nf = hf + ud[i];
            ny = y;
            nx = x;
            if (nf >= 5 || nf < 0) continue;
            if (visited[nf][ny][nx] <= visited[hf][y][x] + 1 || maze[nf][ny][nx] == 0) continue;
            visited[nf][ny][nx] = visited[hf][y][x] + 1;
            que.push({nf, {ny, nx}});
        }
    }
    if (res > visited[4][4][4])
        res = visited[4][4][4];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> temp;
    vector<int> tmp;
    int num;
    for (int i = 0; i < 5; i++) {
        temp.clear();
        for (int j = 0; j < 5; j++) {
            tmp.clear();
            for (int k = 0; k < 5; k++) {
                cin >> num;
                tmp.push_back(num);
            }
            temp.push_back(tmp);
        }
        arr.push_back(temp);
    }
    tmp.clear();
    makeRot(tmp);
    tmp.clear();
    makeSeq(tmp);
    for (int i = 0; i < seq.size(); i++) {
        for (int j = 0; j < rots.size(); j++) {
            go(i, j);
        }
    }
    if (res == INT_MAX)
        cout << -1 << '\n';
    else
        cout << res - 1 << '\n';
}
