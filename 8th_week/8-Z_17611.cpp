#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

const int siz = 1000001;
const int offset = 500000;

int arr_y[siz], arr_x[siz];
int n, x, y, prev_x, prev_y;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    prev_x = -1;
    prev_y = -1;
    int first_x, first_y, st, ed;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x += offset;
        y += offset;
        if (i == 0) {
            prev_x = x;
            prev_y = y;
            first_x = x;
            first_y = y;
            continue;
        }
        if (i == n - 1 && i > 1) {
            if (x == first_x) {
                st = min(y, first_y);
                ed = max(y, first_y);
                for (int j = st + 1; j <= ed; j++)
                    arr_y[j] += 1;
            }
            else if (y == first_y) {
                st = min(x, first_x);
                ed = max(x, first_x);
                for (int j = st + 1; j <= ed; j++)
                    arr_x[j] += 1;
            }
        }
        if (prev_x == x) {
            st = min(y, prev_y);
            ed = max(y, prev_y);
            for (int j = st + 1; j <= ed; j++)
                arr_y[j] += 1;
        }
        else if (prev_y == y) {
            st = min(x, prev_x);
            ed = max(x, prev_x);
            for (int j = st + 1; j <= ed; j++)
                arr_x[j] += 1;
        }
        prev_x = x;
        prev_y = y;
    }
    int ret = -1;
    for (int i = 0; i < siz; i++)
        ret = max(ret, arr_y[i]);
    for (int i = 0; i < siz; i++)
        ret = max(ret, arr_x[i]);
    cout << ret << '\n';
}


/*
// x좌표가 같다 = 수직선
// y좌표가 같다 = 수평선

// 끝점에 표식을 한 후 선을 쓸어 올린다.
 
#include <iostream>
#include <vector>
#include <algorithm>
 
#define ALPHA 500000
#define MAX 1000010
using namespace std;
 
int N;
int Count_X[MAX];
int Count_Y[MAX];
vector<pair<int, int>> Coord;
 
void Input()
{
    cin >> N;
    for(int i = 0 ; i < N; i++) 
    {
        int a, b; cin >> a >> b;
        a += ALPHA;
        b += ALPHA;
        Coord.push_back(make_pair(a, b));
    }
}
 
void Solution()
{
    for(int i = 0 ; i < N; i++)
    {
        int x = Coord[i].first;
        int y = Coord[i].second;
        int nx = Coord[(i + 1) % N].first;
        int ny = Coord[(i + 1) % N].second;
 
        if(x == nx)
        {
            int Max_Y = max(y, ny);
            int Min_Y = min(y, ny);
            Count_Y[Min_Y]++;
            Count_Y[Max_Y]--;
        }
        else
        {
            int Max_X = max(x, nx);
            int Min_X = min(x, nx);
            Count_X[Min_X]++;
            Count_X[Max_X]--;
        }
    }
    
    for(int i = 1; i < MAX; i++)
    {
        Count_X[i] += Count_X[i - 1];
        Count_Y[i] += Count_Y[i - 1];
    }
 
    int answer = 0;
    for(int i = 1; i < MAX; i++)
    {
        answer = max(max(Count_X[i], Count_Y[i]), answer);
    }
 
    cout << answer << endl;
 
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    Solve();
    return 0;
}

*/