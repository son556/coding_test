#include "test.hpp"

//#include <bits/stdc++.h>
// 순서를 바꿔도 되는 지 잘 확인 할 것
// long long의 최대값은 1e18로 잡을 것
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll n, m, t, a, h;
vector<vector<ll>> dun, dun_cp;
ull st, mi, en;

bool go(ll hp_max) {
	ll hit = m;
	ll hp = hp_max;
	ll cnt;
	for (int i = 0; i < dun.size(); i++) {
		if (dun[i][0] == 1) {
			if (dun[i][2] % hit) cnt = dun[i][2] / hit;
			else cnt = dun[i][2] / hit - 1;
			hp -= cnt * dun[i][1];
			if (hp <= 0) return false;
		}
		else {
			hp += dun[i][2];
			hit += dun[i][1];
			if (hp > hp_max) hp = hp_max;
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<ll> b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		b.clear();
		b.push_back(t);
		b.push_back(a);
		b.push_back(h);
		dun.push_back(b);
	}
	dun_cp = dun;
	st = 1;
	ll res = __LONG_LONG_MAX__;
	en = res;
	while (st <= en) {
		mi = (st + en) / 2;
		if (go(mi)) {
			res = min(res, ll(mi));
			en = mi - 1;
		}
		else st = mi + 1;
		dun = dun_cp;
	}
	cout << res << endl;
	return 0;
}