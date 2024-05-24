#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int g, p, s;
int arr[100001];
vector<int> ps;

int check(int num) {
    if (arr[num] == num) {
        arr[num]--;
        return num;
    }
    int ret = num;
    while (ret) {
        if (ret && arr[ret] == ret) {
            arr[ret]--;
            arr[num] = ret;
            return ret;
        }
        ret = arr[ret];
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> g;
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> s;
        ps.push_back(s);
    }
    for (int i = 0; i <= g; i++)
        arr[i] = i;
    int cnt = 0;
    for (int i = 0; i < ps.size(); i++) {
        int tmp = check(ps[i]);
        if (tmp == -1)
            break;
        cnt++;
    }
    cout << cnt << '\n';
}