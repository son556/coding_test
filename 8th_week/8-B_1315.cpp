//8-B_1315

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
int n;
int dpPoint[1001][1001];
int stet[1001][1001];
vector<vector<int>> quests;

pair<int, int> findQuest(int st, int mp) {
    pair<int, int> res;
    int cnt = 0;
    int point = 0;
    for (int i = 0; i < n; i++) {
        if (st >= quests[i][0] || mp >= quests[i][1]) {
            cnt++;
            point += quests[i][2];
        }
    }
    res.first = cnt;
    res.second = point;
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> tmp(3);
    for (int i = 0; i < n; i++) {
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        quests.push_back(tmp);
    }
    pair<int, int> ret;
    ret = findQuest(1, 1);
    stet[1][1] = ret.first;
    dpPoint[1][1] = ret.second;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (dpPoint[i - 1][j] > 0) {
                ret = findQuest(i, j);
                stet[i][j] = ret.first;
                dpPoint[i][j] = ret.second - ((i - 1) + (j - 1));
            }
            if (dpPoint[i][j - 1] > 0) {
                ret = findQuest(i, j);
                stet[i][j] = ret.first;
                dpPoint[i][j] = ret.second - ((i - 1) + (j - 1));
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j<= 1000; j++)
            answer = max(answer, stet[i][j]);
    }
    cout << answer << '\n';
}

/*
struct game{
    int x, y, c; 
};
vector<game> a;
int n, dp[1001][1001];
bool visited[101]; 

int rpg(int STR, int INT){
	int &ret = dp[STR][INT];
	if(ret != -1) return ret;

	ret = 0;
	int pnt = 0;
	vector<int> v;
	for(int i = 0; i < n; i++){
        if(a[i].x <= STR || a[i].y <= INT){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pnt += a[i].c;
                v.push_back(i);
            }
        }
	}

	for(int p = 0; p <= pnt; p++){
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + pnt - p);
        ret = max(ret, rpg(nextSTR, nextINT));
	}
	for(int here : v)
        visited[here] = false;

	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
        int STR, INT, PNT;
		scanf("%d %d %d", &STR, &INT, &PNT);
        a.push_back({STR, INT, PNT});
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rpg(1, 1));
}
*/