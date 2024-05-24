#include "test.hpp"

/*
투 포인터 시간복잡도 o(N)
소수 판별 암기!!

*/

//#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> nums;

bool check(int num) {
    if (num == 1)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int dest;
    cin >> dest;
    for (int i = 2; i <= 4000000; i++) {
        if (check(i))
            nums.push_back(i);
    }
    int st = 0, ed = 0, cnt = 0;
    ll total = 2;
    while (st <= ed && ed < nums.size()) {
        if (total < dest) {
            ed++;
            total += nums[ed]; 
        }
        else if (total > dest) {
            total -= nums[st];
            st++;
        }
        else {
            cnt++;
            ed++;
            total += nums[ed];
        }
    }
    cout << cnt << '\n';
}