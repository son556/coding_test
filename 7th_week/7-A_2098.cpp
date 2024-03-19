#include "test.hpp"
// dp 완전탐색 + 메모이제이션
// 생각의 순서: 1.완전탐색 -> 경우의 수 너무 큼 -> 2. 메모이제이션(배열, 맵 등) 가능한가  -> \
 3. 배열이 1000만정도 필요해 보인다 -> 그리디 혹은 다른 알고리즘
// dp 는 방향성이 있고 싸이클이 없어야 한다
// 1 문제를 잘 정의 할 것 2 부분문제들 사이의 관계를 파악할 것

// #include <bits/stdc++.h> 
#define MAX_N 16
const int INF = 987654321;
using namespace std; 
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){
    if(visited == (1 << n) - 1){
        return dist[here][0] ? dist[here][0] : INF;
    }
    int &ret = dp[here][visited];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue;
        if(dist[here][i] == 0) continue;
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';
    return 0;
}
