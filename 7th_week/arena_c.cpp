#include "test.hpp"

// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, m, q, money;
map<string, vector<ll> > comp;

void one(string str, ll cnt) {
	ll pp = comp[str][1] * cnt;
	if (money < pp) return;
	money -= pp;
	comp[str][2] += cnt;
}

void two(string str, ll cnt) {
	if (comp[str][2] == 0) return;
	if (comp[str][2] < cnt) {
		money += comp[str][1] * comp[str][2];
		comp[str][2] = 0;
	}
	else {
		money += comp[str][1] * cnt;
		comp[str][2] -= cnt;
	}
}

void three(string str, ll dis) {
	comp[str][1] = max(comp[str][1] + dis, ll(0));
}

void four(ll g, ll dis) {
	for (auto it = comp.begin(); it != comp.end(); it++) {
		if ((it->second)[0] == g) {
			(it->second)[1] = max(ll(0), (it->second)[1] + dis);
		}
	}
}

void five(ll g, ll e) {
	double ppp;
	ll tmp;
	for (auto it = comp.begin(); it != comp.end(); it++) {
		if ((it->second)[0] == g) {
			ppp = (it->second)[1] * (1 + 0.01 * e);
			tmp = ll(ppp);
			tmp = tmp / 10 * 10;
			(it->second)[1] = tmp;
		}
	}
}

void six() {
	cout << money << endl;
}

void seven() {
	ll res = 0;
	for (auto it : comp) {
		res += (it.second)[1] * (it.second)[2];
		res = min(res, ll(2 * 1e12));
	}
	cout << res + money << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> money >> q;
	ll g, pay, tmp;
	string str;
	vector<ll> v;
	for (ll i = 0; i < n; i++) {
		v.clear();
		cin >> g >> str >> pay;
		v.push_back(g);
		v.push_back(pay);
		v.push_back(0);
		comp.insert({str, v});
	}
	for (ll i = 0; i < q; i++) {
		cin >> g;
		if (g < 4) {
			cin >> str >> pay;
			
		}
		else if (g < 6) {
			cin >> tmp >> pay;
		}
		if (g == 1) one(str, pay);
		else if (g == 2) two(str, pay);
		else if (g == 3) three(str, pay);
		else if (g == 4) four(tmp, pay);
		else if (g == 5) five(tmp, pay);
		else if (g == 6) six();
		else seven();
	}
	// one("AAA", 0);
	// for (auto it : comp) {
	// 	cout << (it.first) << ", " << (it.second)[0] << ", " << (it.second)[1] << ", " << (it.second)[2] << endl;
	// }
	// cout << "money: " << money << endl;
}