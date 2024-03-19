#include "test.hpp"
// 8-I_1280
/*
알고리즘
나무 사이의 거리를 구해서 segment tree 만들기
각각의 영역에 대해서 비용을 구한 후 곱함

문제점
    세그먼트 트리를 사용해야 한다는 생각이 들었지만 어떻게 사용하면 좋을지 모르겠음
    문제의 요구사항처럼 구간 사이의 합을 구해야 하는데
    n^2인 방법밖에 안떠오름

해결책
    tip> 그림을 그려서 상황을 파악해보자
    현재 심을 나무의 총비용 = (현재 나무위치 * 왼쪽 나무의 수 - 왼쪽 나무 거리의 총 합) + (오른쪽 나무의 총 합 - 현재 위치 * 오른쪽 나무의 개수)
    1. 두개의 세그먼트 트리를 만들어서 나무를 심기전에 심어져 있는 오른쪽, 왼쪽 나무의 개수를 구한다.
    2. 오른쪽 나무의 거리의 총 합 왼 쪽 나무의 거리의 총 합을 구한다.
    그 후 계산
    3. 1,2에서 구한 값을 최종 결과값에 반영해 주고 현재 나무를 심는다.
    4. 1,2,3 반복
    주의) 같은 위치에 계속 나무를 심는 경우-> 예를 들어 나무 5그루를 같은위치에 전부 심으면 결과는 0 이 나와야 한다. 
*/


//#include <bits/stdc++.h>

#define DIV 1000000007
using namespace std;


typedef long long ll;

ll sum(vector<ll> &vec, int start, int end, int nod, int left, int right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return vec[nod];
    int mid = (start + end) / 2;
    return sum(vec, start, mid, nod * 2, left, right) + sum(vec, mid + 1, end, nod * 2 + 1, left, right);
}

void update(vector<ll> &vec, int start, int end, int nod, int index, ll diff) {
    if (index < start || index > end) return;
    vec[nod] += diff;
    if (start == end) return;
    int mid = ( start + end ) / 2;
    update(vec, start, mid, nod * 2, index, diff);
    update(vec, mid + 1, end, nod * 2 + 1, index, diff);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    vector<ll> dist, count;
    dist = vector<ll>(4 * 200000, 0);
    count = dist;
    cin >> n;
    ll res = 1;
    int flag = 0;
    ll l_cnt, r_cnt, l_dist, r_dist;
    ll num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        l_cnt = 0;
        r_cnt = 0;
        l_dist = 0;
        r_dist = 0;
        if (i) {
            l_cnt = sum(count, 0, 200000, 1, 0, num - 1);
            l_dist = sum(dist, 0, 200000, 1, 0, num - 1);
            l_dist = num * l_cnt - l_dist;
            r_cnt = sum(count, 0, 200000, 1, num + 1, count.size() - 1);
            r_dist = sum(dist, 0, 200000, 1, num + 1, dist.size() - 1);
            r_dist -= r_cnt * num;
        }
        update(dist, 0, 200000, 1, num, num);
        update(count, 0, 200000, 1, num, 1);
        if (l_dist || r_dist)
        {
            flag = 1;
            res *= (l_dist + r_dist) % DIV;
            res %= DIV;
        }
    }
    if (flag == 0) res = 0;
    cout << res << '\n';
}