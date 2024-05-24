//7662

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    multimap<int, int> ss;
    int t, k, num;
    char c;
    cin >> t;
    while (t--) {
        cin >> k;
        ss.clear();
        for (int i = 0; i < k; i++) {
            cin >> c >> num;
            if (c == 'I') {
                ss.insert({num, 0});
            }
            else if (ss.size()) {
                if (num == 1)
                    ss.erase(--ss.end());
                else
                    ss.erase(ss.begin());
            }
        }
        if (ss.size() == 0)
            cout << "EMPTY" << '\n';
        else
            cout << (--ss.end())->first << ' ' << (ss.begin())->first << '\n';
    }
}



