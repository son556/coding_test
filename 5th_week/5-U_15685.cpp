#include "test.hpp"

//기하처럼 보이는 문제 -> 규칙찾기 (기하문제는 코테X)

// 0, 1, {2, 1}, {2, 3, 2, 1} ...

//#include <bits/stdc++.h>

using namespace std;

int maps[101][101];
vector<vector<int>> factors;

int x, y, d, g, n;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int cnt;

void rotate(vector<int> &v, int d_y, int d_x) {
    vector<int> b;
    int nx, ny;
    ny = v[0] + d_y;
    nx = v[1] + d_x;
    int tmp = ny;
    ny = nx;
    nx = -tmp;
    ny -= d_y;
    nx -= d_x;
    b.push_back(ny);
    b.push_back(nx);
    factors.push_back(b);
}

void drawMap() {
    for (int i = 0; i < factors.size(); i++) {
        maps[factors[i][0]][factors[i][1]] = 1;
    }
}

void Dragons(int gen) {
    int end;
    while (gen)
    {
        end = factors.size() - 1;
        for (int i = end - 1; i > -1; i--) {
            rotate(factors[i], -1 * factors[end][0], -1 * factors[end][1]);
        }
        gen--;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vec;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        factors.clear();
        vec.clear();
        vec.push_back(y);
        vec.push_back(x);
        factors.push_back(vec);
        vec.clear();
        vec.push_back(y + dy[d]);
        vec.push_back(x + dx[d]);
        factors.push_back(vec);
        Dragons(g);
        drawMap();
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (maps[i][j] == 0) continue;
            if (maps[i][j + 1] && maps[i + 1][j + 1] && maps[i + 1][j]) cnt++;
        }
    }
    cout << cnt << endl;
}