//7-U_1450

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string str;
int dp[2501][2501];
int dp2[2501];
map<int, vector<int>> book;

int go(int st, int en) {
    if (st == en) {
        dp[st][en] = 1;
        book[st].push_back(en);
        return 1;
    }
    int &ret = dp[st][en];
    if (ret != -1) return ret;
    ret = 0;
    if (str[st] == str[en]) {
        if (st + 1 == en) {
            dp[st][en] = 1;
            book[st].push_back(en);
            ret = 1;
        }
        else {
            ret = go(st + 1, en - 1);
            if (ret == 1) book[st].push_back(en);
        }
    }
    go(st + 1, en);
    go(st, en - 1);
    return ret;
}

int go2(int start) {
    if (start >= str.size()) return 0;
    if (dp2[start]) return dp2[start];
    int &answer = dp2[start];
    answer = INT_MAX;
    for (int i = 0; i < book[start].size(); i++)
    {
        answer = min(answer, go2(book[start][i] + 1) + 1);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    memset(dp, -1, sizeof(dp));
    go(0, str.size() - 1);
    int answer = INT_MAX;
    for (int i = 0; i < str.size(); i++) {
        answer = min(answer, go2(i) + i);
    }
    cout << answer << endl;
}
