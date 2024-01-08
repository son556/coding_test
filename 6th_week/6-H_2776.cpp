#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> arr;

bool find(int num) {
    int st = 0;
    int en = arr.size() - 1;
    int mid;

    while (st <= en) {
        mid = (st + en) / 2;
        if (arr[mid] == num) return true;
        if (arr[mid] > num) en = mid - 1;
        else st = mid + 1;
    }
    return false;
}

int main(void) {
    scanf("%d", &t);
    int x, idx;
    while(t--) {
        scanf("%d", &n);
        arr.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            cout << find(x) << endl;
        }
    }
}
