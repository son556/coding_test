#include "test.hpp"

/*
cout precision 사용해야함
좋지 않음 (공부용)
*/

//#include <bits/stdc++.h>

using namespace std;

int dir[4] = {0, 0, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int arr[41][41];
double total;
int num;

void go(int y, int x, int cnt, double p) {
    if (cnt == num) {
        total += p;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (arr[ny][nx] || dir[i] == 0) continue;;
        arr[ny][nx] = 1;
        go(ny, nx, cnt + 1, p * double(dir[i]) / 100.0);
        arr[ny][nx] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num >> dir[0] >> dir[1] >> dir[2] >> dir[3];
    arr[20][20] = 1;
    go(20, 20, 0, 1);
    cout.precision(9);
    cout << total << '\n';
}