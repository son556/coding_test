#include "test.hpp"

//#include <bits/stdc++.h>
// 그리디 예제를 봤을 때 괜찮으면 제출
// 실수형인 경우 그냥 제출해 보고 틀렸다고 뜨면 작은 수를 더해볼것
//ex) printf("%.3lf", ret) ->(틀리면) => printf("%.3lf", ret + 0.00001)
using namespace std;

vector<double> arr;
vector<double> dp;
double n, x;

double findDouble() {
    dp[0] = arr[0];
    double res = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        dp[i] = max(arr[i], arr[i] * dp[i - 1]);
        if (dp[i] > res) res = dp[i];
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
        dp.push_back(x);
    }
    double answer = findDouble();
    cout << fixed;
    cout.precision(3);
    cout << round(answer * 1000) / 1000 << endl;
}
//p103