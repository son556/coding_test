#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

int n, resMax = INT_MIN, resMin = INT_MAX;
vector<int> nums;
vector<int> arr;
vector<string> oper;

void go(int num, int next, int cnt) {
    if (cnt == n - 1) {
        if (resMax < num) resMax = num;
        if (resMin > num) resMin = num;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 0) continue;
        if (oper[i] == "+") num += nums[next];
        else if (oper[i] == "-") num -= nums[next];
        else if (oper[i] == "*") num *= nums[next];
        else num /= nums[next];
        arr[i] -= 1;
        go(num, next + 1, cnt + 1);
        arr[i] += 1;
        if (oper[i] == "+") num -= nums[next];
        else if (oper[i] == "-") num += nums[next];
        else if (oper[i] == "*") num /= nums[next];
        else num *= nums[next];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    oper.push_back("+");
    oper.push_back("-");
    oper.push_back("*");
    oper.push_back("/");

    cin >> n;
    int m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        nums.push_back(m);
    }
    for (int i = 0; i < 4; i++) {
        cin >> m;
        arr.push_back(m);
    }
    go(nums[0], 1, 0);
    cout << resMax << endl;
    cout << resMin << endl;
    return 0;
}