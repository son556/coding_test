#include "test.hpp"

/*
알고리즘
    segment tree 구현

문제
    트리 뿐 아니라 원래 가지고 있던 배열의 값도 업데이트 해줘야한다.
    diff의 값을 원 배열의 값을 참조하여 바꿔주기 때문..
*/

//#include <bits/stdc++.h>

using namespace std;
#define SIZE 1000000
typedef long long ll;

ll tree[SIZE * 4];
ll arr[SIZE];
ll n, m, k, a, b, c;

ll init(ll start, ll ed, ll nod) {
    if (start == ed) {
        tree[nod] = arr[start];
        return tree[nod];
    }
    ll mid = (start + ed) / 2;
    tree[nod] = init(start, mid, nod * 2) + init(mid + 1, ed, nod * 2 + 1);
    return tree[nod];
}

void update(ll start, ll ed, ll nod, ll index, ll diff) {
    if (index < start || index > ed) return;
    tree[nod] += diff;
    if (start == ed) return;
    ll mid = (start + ed) / 2;
    update(start, mid, nod * 2, index, diff);
    update(mid + 1, ed, nod * 2 + 1, index, diff);
}

ll sum(ll start, ll ed, ll nod, ll left, ll right) {
    if (start > right || ed < left) return 0;
    if (left <= start && ed <= right) return tree[nod];
    ll mid = (start + ed) / 2;
    return sum(start, mid, nod * 2, left, right) + sum(mid + 1, ed, nod * 2 + 1, left, right);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    init(0, n - 1, 1);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            ll diff = c - arr[b - 1];
            update(0, n - 1, 1, b - 1, diff);
            arr[b - 1] = c;
        }
        else
            cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
    }
}
