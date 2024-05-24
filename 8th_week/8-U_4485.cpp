#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
int arr[125][125];
int dist[125][125];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pque;
    int offset, d;
    pair<int, int> here, to;
    dist[0][0] = arr[0][0];
    pque.push({dist[0][0], 0, 0});
    while (pque.size()) {
        here = make_pair(get<1>(pque.top()), get<2>(pque.top()));
        offset = get<0>(pque.top());
        pque.pop();
        if (dist[here.first][here.second] != offset) continue;
        for (int i = 0; i < 4; i++) {
            to.first = here.first + dy[i];
            to.second = here.second + dx[i];
            if (to.first >= n || to.first < 0 || to.second >= n || to.second < 0) continue;
            d = offset + arr[to.first][to.second];
            if (dist[to.first][to.second] > d) {
                dist[to.first][to.second] = d;
                pque.push({d, to.first, to.second});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int idx = 1;
    while (n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        fill(&dist[0][0], &dist[0][0] + 125 * 125, INF);
        go();
        cout << "Problem " << idx << ": " << dist[n - 1][n - 1] << '\n';
        cin >> n;
        idx++;
    }
}