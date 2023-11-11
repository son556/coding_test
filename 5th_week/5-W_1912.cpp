#include "test.hpp"

//#include <bits/stdc++.h>
// 초기 값은 구간의 밖의 값으로 하기
// 누적합 음수이면 버림
using namespace std;

vector<int> arr;
int n;
long long res;

void find() {
    long long sum = arr[arr.size() - 1];
    res = sum;
    for (int i = arr.size() - 2; i > -1; i--) {
        sum = max(int(arr[i] + sum), int(arr[i]));
        if (res < sum) res = sum;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    find();
    cout << res << endl;
}

// 해설
// int n, sum, a, ret = -1001; 
// int main(){
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++){
//         scanf("%d", &a);  
//         sum += a; 
//         ret = max(ret, sum); 
//         if(sum < 0) sum = 0;   
//     } 
//     printf("%d\n", ret);
//     return 0;
// }