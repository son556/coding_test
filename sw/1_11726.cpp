#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, cnt;
ll arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i < 1001; i++)
        arr[i] = (arr[i - 1] % 10007 + arr[i - 2] % 10007);
    cout << arr[n] << endl;
}