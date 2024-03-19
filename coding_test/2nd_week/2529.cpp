#include "test.hpp"

/*
알고리즘 백트래킹

*/

//#include<bits/stdc++.h>

using namespace std;

vector<char> vec;
vector<string> res;
char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int visited[10];

void go(int idx, string str) {
    if (idx == vec.size()) {
        res.push_back(str);
        return;
    }
    if (vec[idx] == '>') {
        for (int i = 0; i < str[str.size() - 1] - '0'; i++) {
            if (visited[i]) continue;
            visited[i] = 1;
            go(idx + 1, str + arr[i]);
            visited[i] = 0;
        }
    }
    else {
        for (int i = str[str.size() - 1] - '0' + 1; i < 10; i++) {
            if (visited[i]) continue;
            visited[i] = 1;
            go(idx + 1, str + arr[i]);
            visited[i] = 0;
        }
    }
}

bool cmp(string &s1, string &s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) continue;
        return s1[i] > s2[i];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        vec.push_back(c);
    }
    for (int i = 0; i < 10; i++) {
        memset(visited, 0, sizeof(visited));
        string str = to_string(i);
        visited[i] = 1;
        go(0, str);
    }
    sort(res.begin(), res.end(), cmp);
    cout << res[0] <<'\n';
    cout << res[res.size() - 1] << '\n';
}