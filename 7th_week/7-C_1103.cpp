#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> board;
int dp[50][50];
int flag;
bool check(int y, int x, int d, int cnt) {
    int ny = y, nx = x;
    if (d == 0) nx += cnt;
    else if (d == 1) ny += cnt;
    else if (d == 2) nx -= cnt;
    else if (d == 3) ny -= cnt;
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) return false;
    if (board[ny][nx] == 'H') return false;
    return true;
}

vector<int> move(int y, int x, int d, int cnt) {
    int ny = y, nx = x;
    vector<int> mov;
    if (d == 0) nx += cnt;
    else if (d == 1) ny += cnt;
    else if (d == 2) nx -= cnt;
    else if (d == 3) ny -= cnt;
    mov.push_back(ny);
    mov.push_back(nx);
    return mov;
}

void go(int y, int x, int depth) {
    vector<int> cor;
    if (board[y][x] == 'H' || flag) { return ; }
    for (int i = 0; i < 4; i++) {
        if (check(y, x, i, board[y][x] - '0') == false) continue;
        cor = move(y, x, i, board[y][x] - '0');
        if (dp[y][x] + 1 <= dp[cor[0]][cor[1]]) continue;
        if (flag) continue;
        dp[cor[0]][cor[1]] = dp[y][x] + 1;
        if (dp[cor[0]][cor[1]] > 4000) flag = 1;
        go(cor[0], cor[1], depth + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        str.clear();
        cin >> str;
        board.push_back(str);
    }
    flag = 0;
    go(0, 0, 0);
    if (flag) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res < dp[i][j]) res = dp[i][j];
        }
    }
    cout << res + 1 << endl;
}