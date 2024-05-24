#include "test.hpp"

/*
알고리즘 스택, 시간초과??
나중에 같은 알고리즘으로 덱으로 바꿨더니 됨??
*/

//#include <bits/stdc++.h>

using namespace std;

string str;
int n, k;
deque<char> box;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    int target = n - k;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (k == 0) {
            box.push_back(str[i]);
            continue;
        }
        if (box.size() == 0)
            box.push_back(str[i]);
        else if (box[box.size() - 1] >= str[i])
            box.push_back(str[i]);
        else {
            while (box.size() && box[box.size() - 1] < str[i] && k) {
                box.pop_back();
                k--;
            }
            box.push_back(str[i]);
        }
    }
    string res;
    if (box.size()) {
        for (int i = 0; i < target; i++)
            res += box[i];
    }
    if (res.size() == 0) res = "0";
    cout << res << '\n';
}

//2812