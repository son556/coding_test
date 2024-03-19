#include "test.hpp"

/*
알고리즘 (그리디)
    나무토막을 자를 수 없음
    웅덩이를 시작점 크기로 정렬 후 
    주어진 웅덩이 하나하나에 대해 덮을 수 있는 나무를 최소한으로
    사용 하고 나무가 도달한 끝 값 + 1을 저장함
    저장된 값보다 작은 값은 이미 나무가 덮혀 있다는 뜻임
    웅덩이를 순회하면 웅덩이의 끝값이 저장한 값보다 작다면 이미
    전부 덮혔다는 뜻 이므로 해당 웅덩이를 건너뜀

문제점
    인덱스로 생각하는 것과 문제의 내용을 잘 이해하지 못함
    나무를 자를 수 있다고 생각했음
*/

// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int st, ed;
int cnt;
int n, l;
vector<pair<int, int>> vec;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> st >> ed;
        vec.push_back({st, ed});
    }
    sort(vec.begin(), vec.end());
    ed = -1;
    st = 0;
    for (int i = 0; i < vec.size(); i++) {
        st = max(ed + 1, vec[i].first);
        if (vec[i].second < st)
            continue;
        int dist = vec[i].second - st;
        int tmp = dist / l;
        if (dist % l) 
            tmp++;
        ed = st + tmp * l - 1;
        cnt += tmp;
    }
    cout << cnt << '\n';
}