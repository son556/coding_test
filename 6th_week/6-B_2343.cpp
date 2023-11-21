#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> arr;
int n, m;
ll len;
double target, total;

bool checkBluelay(double target) {
    int num = m - 1;
    ll tmp = 0;
    for (int i = 0; i < arr.size(); i++) {
        tmp += arr[i];
        if (tmp > target && num > 0) {
            tmp -= arr[i];
            len = max(tmp, len);
            tmp = arr[i];
            num--;
            continue;
        }
        if (tmp > target && num == 0) {
            len = 0;
            return false;
        }
    }
    len = max(len, tmp);
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < n; i++) total += arr[i];
    target = total / m;
    while (!checkBluelay(target)) target++;
    cout << len << endl;
    return 0;
}

// 답지
// int n, m, lo, hi, ret, a[100004], sum, mx;
// bool check(int mid){
//     if(mx > mid) return false;  
//     int temp = mid;
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         if(mid - a[i] < 0){
//             mid = temp;
//             cnt++;
//         }
//         mid -= a[i];
//     }
//     if(mid != temp) cnt++; 
//     return cnt <= m;
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         sum += a[i]; 
//         mx = max(mx, a[i]);
//     } 
//     lo = 0; hi = sum; // 0 ~ sum 까지 들어있는 배열이 있다고 가정하고 이분탐색으로 넣을 수 있는 목표값을 찾는다.
//     while(lo <= hi){
//         int mid = (lo + hi) / 2;
//         if(check(mid)){
//             hi = mid - 1;
//             ret = mid;
//         }else lo = mid + 1;
//     }
//     cout << ret << "\n";
//     return 0;
// }
