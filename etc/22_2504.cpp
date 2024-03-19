#include "test.hpp"

//#include <bits/stdc++.h>
// 스택에 누적 and stack 2개
using namespace std;

int cnt, n, s, w;
vector<pair<int, int>> visited;

bool check(string str) {
    stack<char> box;
    for (int i = 0; i < str.size(); i++) {
        if (box.size() == 0 || str[i] == '(' || str[i] == '[')
            box.push(str[i]);
        else if (str[i] == ')' && box.top() == '(')
            box.pop();
        else if (str[i] == ')' && box.top() != '(') { return false; }
        else if (str[i] == ']' && box.top() == '[')
            box.pop();
        else if (str[i] == ']' && box.top() != '[') { return false;}
    }
    if (box.size()) { return false; }
    return true;
}

int makeNum(string s) {
    stack<pair<char, int>> box1;
    stack<char> box2;
    int res = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            if (box2.size()) {
                box1.push({box2.top(), 0});
                box2.pop();
            }
            box2.push(s[i]);
            continue;
        }
        if (s[i] == ')') {
            if (box2.size() && box2.top() == '(') {
                box2.pop();
                if (box1.size())
                    box1.top().second += 2;
                else
                    res += 2;
            }
            else if (box1.top().first == '(') {
                tmp = box1.top().second * 2;
                box1.pop();
                if (box1.size())
                    box1.top().second += tmp;
                else
                    res += tmp;
            }
        }
        else if (s[i] == ']') {
            if (box2.size() && box2.top() == '[') {
                box2.pop();
                if (box1.size())
                    box1.top().second += 3;
                else
                    res += 3;
            }
            else if (box1.top().first == '[') {
                tmp = box1.top().second * 3;
                box1.pop();
                if (box1.size())
                    box1.top().second += tmp;
                else
                    res += tmp;
            }
        }
    }
    return res;
}

int main(void) {
    string str;
    cin >> str;
    if (check(str) == false) {
        cout << 0 << '\n';
        return 0;
    }
    cout << makeNum(str) << '\n';
}