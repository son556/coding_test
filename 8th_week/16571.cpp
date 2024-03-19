#include "test.hpp"

// 1 바로 이길 수 있는 곳 찾기
// 2 막아야 하는 곳 찾기
// 3 2x2를 만들 수 있는 곳 찾기


//#include <bits/stdc++.h>

using namespace std;

int arr[3][3];
int visited[3][3];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<int, int>> vec;


bool check() {
    int flag = 0;
    int tmp1;
    int tmp2;
    for (int i = 0; i < 3; i++) {
        tmp1 = 0;
        tmp2 = 0;
        for (int j = 0; j < 3; j++) {
            if (visited[i][j] == 1)
                tmp1++;
            if (visited[i][j] == 2)
                tmp2++;
        }
        if (tmp1 == 3 || tmp2 == 3)
            return 1;
        tmp1 = 0;
        tmp2 = 0;
        for (int j = 0; j < 3; j++) {
            if (visited[j][i] == 1)
                tmp1++;
            if (visited[j][i] == 2)
                tmp2++;
        }
        if (tmp1 == 3 || tmp2 == 3)
            return 1;
    }
    tmp1 = 0;
    tmp2 = 0;
    for (int i = 0; i < 3; i++) {
        if (visited[i][i] == 1)
            tmp1++;
        if (visited[i][i] == 2)
            tmp2++;
    }
    if (tmp1 == 3 || tmp2 == 3)
        return 1;
    tmp1 = 0;
    tmp2 = 0;
    for (int i = 0; i < 3; i++) {
        if (visited[i][2 - i] == 1)
            tmp1++;
        if (visited[i][2 - i] == 2)
            tmp2++;
    }
    if (tmp1 == 3 || tmp2 == 3)
        return 1;
    return 0;
}

int go(int turn)
{
    if (check())
        return -1;
    int res = 900;
    for (int i = 0; i < vec.size(); i++)
    {
        if (visited[vec[i].first][vec[i].second]) continue;
        if (turn)
            visited[vec[i].first][vec[i].second] = 2;
        else
            visited[vec[i].first][vec[i].second] = 1;
        res = min(go(turn ^ 1), res);
        visited[vec[i].first][vec[i].second] = 0;
    }
    if (res == 900)
        res = 0;
    else if (res == -1)
        res = 1;
    else if (res == 1)
        res = -1;
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = arr[i][j];
            if (arr[i][j] == 1)
                cnt1++;
            else if (arr[i][j] == 2)
                cnt2++;
            if (arr[i][j] == 0)
                vec.push_back({i, j});
        }
    }
    int flag = 0;
    if (cnt1 == cnt2)
        flag = 0;
    else
        flag = 1;
    int out = go(flag);
    if (out == 1)
        cout << "W\n";
    else if (out == 0)
        cout << "D\n";
    else
        cout << "L\n";
}

/*
1 2 0
1 1 2
0 0 2

W

1 2 0
0 1 0
0 0 0

L

1 0 1
0 2 1
2 1 2

answer: D

0 0 0
0 0 0
0 0 0

answer: D
*/