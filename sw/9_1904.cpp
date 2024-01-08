#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

unsigned long long arr[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i < 1000001; i++) 
        arr[i] = (arr[i - 1] % 15746 + arr[i - 2] % 15746);
    cout << arr[n] % 15746 << endl;
}