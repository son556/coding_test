#include "test.hpp"

//#include <bits/stdc++.h>
// 배열을 뒤집는 것 보다 스택을 사용하는것이 더 좋음(뒤집은 배열을 출력해야 할 때)
using namespace std;

vector<int> res;
vector<pair<int, int>> arr;
int n, x;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back({x, 0});
    }
    res.push_back(arr[0].first);
    int idx, flag;
    for (int i = 1; i < arr.size(); i++) {
        idx = lower_bound(res.begin(), res.end(), arr[i].first) - res.begin();
        if (idx == res.size()) {
            res.push_back(arr[i].first);
            arr[i].second = idx;
        }
        else {
            res[idx] = arr[i].first;
            arr[i].second = idx;
        }
    }
    flag = res.size() - 1;
    res.clear();
    for (int i = arr.size() - 1; i > -1; i--) {
        if (flag == arr[i].second) {
            res.push_back(arr[i].first);
            flag--;
        }
        if (flag < 0) break;
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    cout << endl;
}
