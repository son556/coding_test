#include "test.hpp"

/*
해결책
    배열을 20만개로 놓고 10만번째 부터 값을 채운 후
    인덱스를 저장하고 앞에 있는 값을 합한다.
    
    아직 세그먼트 트리의 활용이 어색하다.
*/

//#include <bits/stdc++.h>

using namespace std;

map<int, int> movie;
int tree[800000];
int arr[200000];
int t, n, m, num;

int init(int start, int end, int nod) {
    if (start == end) {
        tree[nod] = arr[start];
        return tree[nod];
    }
    int mid = (start + end) / 2;
    tree[nod] = init(start, mid, nod * 2) + init(mid + 1, end, nod * 2 + 1);
    return tree[nod];
}

void update(int start, int end, int nod, int index, int diff) {
    if (index < start || index > end) return;
    tree[nod] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, nod * 2, index, diff);
    update(mid + 1, end, nod * 2 + 1, index, diff);
}

int sum(int start, int end, int nod, int left, int right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return tree[nod];
    int mid = (start + end) / 2;
    int ret = sum(start, mid, nod * 2, left, right);
    ret += sum(mid + 1, end, nod * 2 + 1, left, right);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        movie.clear();
        int flag = 0;
        for (int i = 100000; i < 100000 + n; i++) {
            arr[i] = 1;
            movie[flag + 1] = 100000 + flag;
            flag++;
        }
        init(0, 200000 - 1, 1);
        flag = 100000 - 1;
        for (int i = 0; i < m; i++) {
            cin >> num;
            int idx = movie[num];
            cout << sum(0, 200000 - 1, 1, 0, idx - 1) << ' ';
            update(0, 200000 - 1, 1, idx, -1);
            update(0, 200000 - 1, 1, flag, 1);
            movie[num] = flag;
            flag--;
        }
        cout << '\n';
    }
}

// 풀 문제 2-C_2468