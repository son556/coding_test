// 1202 풀기
#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> jewel;
priority_queue<int> ppq;
vector<int> pack;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m, v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        cin >> m;
        pack.push_back(m);
    }
    sort(pack.begin(), pack.end());
    sort(jewel.begin(), jewel.end());
    long long answer = 0;
    int start = 0;
    int flag = 0;
    for (int i = 0; i < pack.size(); i++) {
        for(int j = start; j < jewel.size(); j++)
        {
            start = j;
            if (jewel[j].first > pack[i]) {
                flag = 1;
                break;
            }
            ppq.push(jewel[j].second);
        }
        if (ppq.size() == 0) continue;
        answer += ppq.top();
        ppq.pop();
        if (flag == 0) start++;
        flag = 0;
    }
    cout << answer << endl;
    return 0;
}