#include "test.hpp"

//#include <bits/stdc++.h>

/*
문제에서 나온 n에 대한 범위가 2^30 - 1까지이고 피보나치 수열을 사용한다고 하여
40까지만 피보나치를 구해주면 넉넉할 것이라고 생각함.

idx를 주고 해당 문자열을 찾아야 하는데 dp[40]의 문자열을 만들기에는 무자열 길이가 너무 길었음
그래서 Messi -> M, Gimossi -> G로 줄여서 풀려고 했는데 2 ^ 30 - 1 번 째의 글자를 찾기에는 시간이 
너무 오래걸림

해결책:
    찾고 싶은 번째의 번호가 dp[n] 보다 작다면 해당 번호는 dp[n - 1] || ' ' || dp[n - 2] 영역 중 한곳에
    존재 재귀를 돌며 n이 1 또는 2 가 될 때 까지 번호를 줄여가며 접근 -> 이 때 공백을 만나면 주어진 문자열 출력
비슷한 문제:
    16974 백준 레벨 햄버거

답지를 봤으나 위의 로직이 가장 이해가 잘됨.
*/


using namespace std;
typedef long long ll;

ll dp[45];
string tmp1 = "Messi";
string tmp2 = "Messi Gimossi";

ll pivo(ll num) {
    ll &ret = dp[num];
    if (ret) return ret;
    ret = pivo(num - 1) + pivo(num - 2) + 1;
    return ret;
}

string findIndex(int idx, int n) {
    string answer = "";
    if (n == 1) {
        answer += tmp1[idx - 1];
        return answer;
    }
    if (n == 2) {
        if (idx == 6)
            return "Messi Messi Gimossi";
        answer += tmp2[idx - 1];
        return answer;
    }
    if (idx <= dp[n - 1])
        return findIndex(idx, n - 1);
    if (idx > dp[n - 1] + 1)
        return findIndex(idx - dp[n - 1] - 1, n - 2);
    return "Messi Messi Gimossi";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[1] = 5;
    dp[2] = 13;
    int n;
    cin >> n;
    ll res = pivo(40);
    cout << findIndex(n, 40) << endl;
}
