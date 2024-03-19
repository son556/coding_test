#include "test.hpp"
// 8-D_5419 북서풍
/*
막막한 경우 정렬을 한번 생각해보자
*/

// #include <bits/stdc++.h>

#define MAX_NUM 75001

using namespace std;

int t, n;
int segmentTree[MAX_NUM * 4];
vector<pair<int, int>> vec;
vector<int> vec_y;

void update(int st, int ed, int nod, int index, int diff) {
	if (index < st || index > ed) return;
	segmentTree[nod] += diff;
	if (st == ed) return;
	int mid = (st + ed) / 2;
	update(st, mid, nod * 2, index, diff);
	update(mid + 1, ed, nod * 2 + 1, index, diff);
}

int sum(int st, int ed, int nod, int left, int right) {
	if (ed < left || st > right) return 0;
	if (ed <= right && st >= left) return segmentTree[nod];
	int mid = (st + ed) / 2;
	int ret = sum(st, mid, nod * 2, left, right);
	ret += sum(mid + 1, ed, nod * 2 + 1, left, right);
	return ret;
}

bool cmp(pair<int, int> &p1, pair<int ,int> &p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first < p2.first;
}

int findIndex(int target) {
	int st = 0;
	int ed = vec_y.size() - 1;
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (vec_y[mid] == target) return mid;
		if (vec_y[mid] > target)
			st = mid + 1;
		else
			ed = mid - 1;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	int x, y;
	while (t--) {
		cin >> n;
		vec.clear();
		vec_y.clear();
		memset(segmentTree, 0, sizeof(segmentTree));
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			vec.push_back({x, y});
			vec_y.push_back(y);
		}
		sort(vec.begin(), vec.end(), cmp);
		sort(vec_y.begin(), vec_y.end(), greater<int>());
		int ret = 0;
		for (int i = 0; i < vec.size(); i++) {
			int index = findIndex(vec[i].second);
			ret += sum(0, n - 1, 1, 0, index);
			update(0, n - 1, 1, index, 1);
		}
		cout << ret << '\n';
	}
}



/*

2
4
-10 -10
-10 10
10 -10
10 10
3
1 3
2 2
3 1
*/