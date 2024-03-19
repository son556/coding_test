#include "test.hpp"

// 2023
/*
알고리즘
    수학에 가까운 듯 처음으로 오는 수는 정해져 있고 그 다음수도 짝수는 불가능
    숫자를 하나하나 늘려보며 소수인 경우 진행
    소수 판별 -> 빠르게 판별하는 방법을 알고 있어야 함-> 그냥 소수 판별 하는 경우 시간초과
    주어진 수의 제곱근 까지 검사하면 빠르게 소수판별 가능
*/
//#include <bits/stdc++.h>

using namespace std;
vector<int> res;
string start = "2357";
string nex = "13579";
int n;

bool check(int num) {
    int tmp;
    for (int i = 2; i < num; i++) {
        if (i * i > num) break;
        tmp = i * i;
    }
    for (int i = 2; i <= tmp; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void go(int idx, string str) {
    if (idx == n) {
        res.push_back(stoi(str));
        return;
    }
    if (idx == 0) {
        for (int i = 0; i < start.size(); i++) {
            go(idx + 1, str + start[i]);
        }
    }
    else {
        for (int i = 0; i < nex.size(); i++) {
            int tmp = stoi(str + nex[i]);
            if (check(tmp) == false) continue;
            go(idx + 1, str + nex[i]);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string tmp = "";
    go(0, tmp);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
}