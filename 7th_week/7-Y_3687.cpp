// 7-Y_3687

#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

int n, x;
string dp[104];
int arr[10];
string maxStr;

string findMin(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) {
        if (s1.length() < s2.length())
            return s1;
        return s2;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] < s2[i])
            return s1;
        if (s1[i] > s2[i])
            return s2;
    }
    return s1;
}

string findMax(int cnt) {
	string str;
	str = "";
	if (cnt % 2) {
		cnt -= 3;
		str = "7";
	}
	cnt /= 2;
	while (cnt--)
		str += "1";
	return str;
}

string go(int cnt) {
	if (cnt == 0) return "";
	string &ret = dp[cnt];
	if (ret != "-1") return dp[cnt];
	ret = maxStr;
	string tmp;
	for (int i = 0; i < 10; i++) {
		if (cnt - arr[i] < 0 ) continue;
		if (cnt == x && i == 0) continue;
		ret = findMin(ret, to_string(i) + go(cnt - arr[i]));
	}
	return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	arr[0] = 6;
	arr[1] = 2;
	arr[2] = 5;
	arr[3] = 5;
	arr[4] = 4;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 3;
	arr[8] = 7;
	arr[9] = 6;
    for (int i = 0; i < 50; i++)
        maxStr += "1";
    fill(&dp[0], &dp[104], "-1");
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << go(x) << ' ' << findMax(x) << endl;
    }
}
