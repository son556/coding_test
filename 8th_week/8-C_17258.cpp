// 8-C_17258

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
int n, m, k, t;
vector<pair<int, int>> party;
int arr[301];
vector<pair<int, int>> quests;
int dp[301][301][301];

int go(int idx, int p, int prev) {
    if (idx == quests.size()) return 0;
    int &ret = dp[idx][p][prev];
    if (ret) return ret;
    int cost = max(t - quests[idx].second - prev, 0);
    if (p >= cost){
        ret = max(ret, go(idx + 1, p - cost, t - quests[idx].second) + quests[idx].first);
        ret = max(ret, go(idx + 1, p, 0));
    }
    else
        ret = max(ret, go(idx + 1, p, 0));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k >> t;
    int st, ed;
    for (int i = 0; i < m; i++) {
        cin >> st >> ed;
        party.push_back({st, ed});
    }
    for (int i = 0; i < party.size(); i++) {
        for (int j = party[i].first; j < party[i].second; j++) {
            if (arr[j] + 1 > t) arr[j] = t;
            else arr[j]++;
        }
    }
    int temp = arr[1]; 
    int _count = 1; 
    for(int i = 2; i <= n; i++){  
        if(temp != arr[i]){ 
            quests.push_back({_count, temp});  
            _count = 0; 
            temp = arr[i];
        }
        _count++;
    }
    quests.push_back({_count, temp});
    cout << go(0, k, 0) << '\n';
}
/*
11 3 2 2
3 12
5 10
7 8

answer:
9

9 6 3 3
5 7
1 3
1 2
2 3
5 7
5 10

answer:
7
*/