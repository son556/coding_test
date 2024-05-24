// 2458

#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dist[500][500];

int n, m;
vector<int> arr[500];

bool check(int s) {
    for (int i = 0; i < n; i++) {
        if (i == s) continue;
        if (dist[i][s] == INF && dist[s][i] == INF)
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    fill(&dist[0][0], &dist[0][0] + 500 * 500, INF);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        dist[a - 1][b - 1] = 1;
    }
    for (int i = 0; i < 500; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (check(i)) cnt++;
    }
    cout << cnt << '\n';
}

//2812 7662