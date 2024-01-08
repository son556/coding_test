//7-S_1509

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
map<pair<ll, pair<int, int> >, ll> book;
vector<int> vec;

ll go(int idx, int flag, ll num) {
    if (num < 0 || num > 20) {
        return 0;
    }
    if (idx == vec.size() - 2) {
        if (num == vec[vec.size() - 1]) return 1;
        return 0;
    }
    if (book.find({num, {idx, flag}}) != book.end()) return book[{num, {idx, flag}}];
    ll &ret = book[{num, {idx, flag}}];
    ret = go(idx + 1, 0, num + vec[idx + 1]) + go(idx + 1, 1, num - vec[idx + 1]);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    cout << go(0, 0, vec[0]) << endl;
}