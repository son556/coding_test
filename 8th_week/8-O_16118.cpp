#include "test.hpp"

/*
알고리즘 다익스트라
    늑대의 경우 경우의수를 나누기 위해 2차원 배열을 사용
    왔던 경로를 기준으로 저장했더니 코드가 꼬이는 문제발생
*/

//#include <bits/stdc++.h>

using namespace std;

#define MAX 987654321

typedef long long ll;

ll n, m;
ll arr[4001];
ll brr[4001][2];
vector<pair<ll, ll>> mapp[4001];
ll a, b, d;

void fox() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pque;
    ll from, to;
    ll dist1, dist2;
    arr[1] = 0;
    pque.push({0, 1});
    while (pque.size()) {
        from = pque.top().second;
        dist1 = pque.top().first;
        pque.pop();
        if (arr[from] != dist1) continue;
        for (ll i = 0; i < mapp[from].size(); i++) {
            to = mapp[from][i].first;
            dist2 = mapp[from][i].second;
            if (arr[to] > dist1 + dist2) {
                arr[to] = dist1 + dist2;
                pque.push({dist1 + dist2, to});
            }
        }
    }
}

class cmp {
    public:
        bool operator() (pair<pair<ll, ll>, ll> &p1, pair<pair<ll, ll>, ll> &p2) {
            return p1.first.first > p2.first.first;
        }
};

void wolf() {
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, cmp> pque;
    ll from, to, dist1, dist2, flag1, flag2;
    brr[1][0] = 0;
    pque.push({{0, 0}, 1});
    while (pque.size()) {
        from = pque.top().second;
        dist1 = pque.top().first.first;
        flag1 = pque.top().first.second;
        pque.pop();
        if (brr[from][flag1] != dist1) continue;
        for (ll i = 0; i < mapp[from].size(); i++) {
            if (flag1 == 0)
                dist2 = mapp[from][i].second / 2;
            else
                dist2 = mapp[from][i].second * 2;
            flag2 = flag1 ^ 1;
            to = mapp[from][i].first;
            if (brr[to][flag2] > dist1 + dist2) {
                brr[to][flag2] = dist1 + dist2;
                pque.push({{dist1 + dist2, flag2}, to});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> d;
        mapp[a].push_back({b, d * 2});
        mapp[b].push_back({a, d * 2});
    }
    fill(arr, arr + 4001, MAX);
    fill(&brr[0][0], &brr[0][0] + 4001 * 2, MAX);
    fox();
    wolf();
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        if (arr[i] < min(brr[i][0], brr[i][1]))
            cnt++;
    }
    cout << cnt << '\n';
}
