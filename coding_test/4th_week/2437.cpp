#include "test.hpp"

/*
정렬후 끝 값만 알면 그사이의 값은 전부 포함된다.
나는 사이값을 전부 계산하고 확인하니 시간초과
이유 : book이 1 부터 시작하므로 어떤값 a + 1 ~ a + book의 끝 값 이 전부 포함
*/

// #include <bits/stdc++.h>

using namespace std;
int n, res;
vector<int> arr;
vector<int> book;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        if (book.size() == 0 && arr[i] != 1) {
            cout << 1 << '\n';
            return 0;
        }
        if (book.size() && arr[i] + 1 > book[book.size() - 1] + 1 && arr[i] > book[book.size() - 1] + 1) {
            cout << book[book.size() - 1] + 1 << '\n';
            return 0;
        }
        if (book.size() == 0)
            book.push_back(1);
        else
            book.push_back(book[book.size() - 1] + arr[i]);
    }
    cout << book[book.size() - 1] + 1 << '\n';
}