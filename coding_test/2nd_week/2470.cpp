#include "test.hpp"

/*
알고리즘: 투 포인터

나눠서 찾기 + 예외 양수에서 2개 뽑거나 음수에서 2개 뽑는경우
가장 작은것을 찾기위한 시작점설정을 해야 했다.
*/

//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, num;
ll target = INT_MAX;
vector<ll> vec1, vec2;
ll res[2];

ll findNum(ll tmp) {
    int st = 0;
    int ed = vec2.size() - 1;
    ll ff = INT_MAX;
    ll answer;
    while (st <= ed) {
        int mid = (st + ed) / 2;
        if (vec2[mid] > tmp) {
            ed = mid - 1;
            if (ff > abs(tmp - vec2[mid])) {
                ff = abs(tmp - vec2[mid]);
                answer = vec2[mid];
            }
        }
        else {
            st = mid + 1;
            if (ff > abs(tmp - vec2[mid])) {
                ff = abs(tmp - vec2[mid]);
                answer = vec2[mid];
            }
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) vec1.push_back(num);
        else vec2.push_back(-num);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    if (vec1.size() == 0) {
        cout << -vec2[1] << ' ' << -vec2[0] << '\n';
        return 0;
    }
    if (vec2.size() == 0) {
        cout << vec1[0] << ' ' << vec1[1] << '\n';
        return 0;
    }
    ll t1 = INT_MAX, t2 = INT_MAX;
    if (vec1.size() >= 2)
        t1 = min(t1, vec1[0] + vec1[1]);
    if (vec2.size() >= 2)
        t2 = min(vec2[0] + vec2[1], t2);
    if (t1 < t2) {
        target = t1;
        res[0] = vec1[0];
        res[1] = vec1[1];
    }
    else {
        target = t2;
        res[0] = -vec2[1];
        res[1] = -vec2[0];
    }
    for (int i = 0; i < vec1.size(); i++) {
        ll num = findNum(vec1[i]);
        if (target > abs(vec1[i] - num)) {
            res[0] = -num;
            res[1] = vec1[i];
            target = abs(vec1[i] - num);
        }
    }
    cout << res[0] << ' ' << res[1] << '\n';
}
