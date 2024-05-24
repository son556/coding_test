#include "test.hpp"
// #include <bits/stdc++.h>

using namespace std;

int t;
string str;

int check(string &s) {
    int st = 0;
    int ed = s.size() - 1;
    while (st <= ed) {
        if (s[st] == s[ed]) {
            st++;
            ed--;
            continue;
        }
        break;
    }
    if (ed < st) return 0;
    int tst = st, ted = ed;
    st += 1;
    while (st <= ed) {
        if (s[st] == s[ed]) {
            st++;
            ed--;
            continue;
        }
        if (s[st] != s[ed]) break;
    }
    if (ed < st) return 1;
    st = tst;
    ed = ted - 1;
    while (st <= ed) {
        if (s[st] == s[ed]) {
            st++;
            ed--;
            continue;
        }
        if (s[st] != s[ed]) break;
    }
    if (ed < st) return 1;
    return 2;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        cout << check(str) << '\n';
    }
}