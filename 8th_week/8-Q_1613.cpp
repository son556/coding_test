#include "test.hpp"

/*
알고리즘
    플로이드 워셜

    정점의 개수가 작고 모든 영역을 탐색해야 한다면 -> 플로이드 워셜
*/

//#include <bits/stdc++.h>

using namespace std;

int n, k, a, b, s;
int dist[404][404];
vector<int> arr[404];

const int INF = 987654321;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    fill(&dist[0][0], &dist[0][0] + 404 * 404, INF);
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for (int i = 1; i <= 400; i++)
        dist[i][i] = 0;
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 1; k <= 400; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        if (dist[a][b] == INF && dist[b][a] == INF)
            cout << 0 << '\n';
        else if (dist[a][b] != INF)
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
    }
}


/*
int n, K, s, e, a, b, c, dist[404][404], t;
const int INF = 987654321;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> K;
	for(int i = 0; i < K; i++){
		cin >> a >> b;
		dist[a][b] = -1, dist[b][a] = 1; // 방향에 따라 -1, 1로 표현
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<= n; i++)
			for(int j=1; j<= n; j++){
//			    if(i == j || j == k || i == k) continue;
//			    if(dist[i][j] != 0) continue;
                if(dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1; // k 다음 i 이고 j 다음 k 이면 j 다음 i 이다.  
                else if(dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1; // i 다음 k 이고 k 다음 j 이면 i 다음 j 이다.
			}
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }

    return 0;
}
*/
// 다음 2-L_2852