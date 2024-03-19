#include "test.hpp"

//#include<bits/stdc++.h>
using namespace std;
// 최대 -> 최소를 작게 or 최대를 크게
// 그리디 -> sort or priority queue or 둘 다
// priority queue같은 경우 일단 넣어보고 처리해주는 문제가 많다.
// 정렬 pq유형은 암기가 필요
// 로직 생각 -> 반례 -> 다른거
int n, a, b, ret; 
vector<pair<int, int>> v; 
priority_queue<int, vector<int>, greater<int>> pq; // 가장작은 값이 top에 위치
// priority_queue<int, vector<int>, less<int>> pq or priority_queue<int> pq -> 가장 큰 값이 top에 위치
// 다른 자료구조 사용시 priority_queue<자료구조, vector<자료구조>, (less or greater)<자료구조>> 로 사용가능
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> a >> b; v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){ 
        pq.push(v[i].second);
        if(pq.size() > v[i].first){ 
            pq.pop();
        } 
    }
	for (int i = 0; i < n; i++)
		cout << pq.top() << ' ';
	cout << endl;
    while(pq.size()){
    	ret += pq.top(); pq.pop();
	}
    cout << ret << "\n";
}

/*
알고리즘
    우선순위 큐의 사이즈 = 경과한 날짜
    날짜 제한이 큐의 사이즈 보다 작으면 큐에 넣는다.
    우선순위 큐는 작은 값이 위에 오도록 정렬
    날짜 제한이 큐 사이즈 이상이라면 큐에서 top을 빼고 
    새로운 값 vs 지금 상태 유지 중 더 큰 쪽을 선택
시간복잡도
    nlog(n) -> 10000 * 10 정도 10 만

*/
/*
vector<pair<int, int>> lec;
priority_queue<int, vector<int>, greater<int>> pq;
int n, p, d, res;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second < p2.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        lec.push_back({p, d});
    }
    sort(lec.begin(), lec.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (pq.size() < lec[i].second) {
            res += lec[i].first;
            pq.push(lec[i].first);
        }
        else {
            if (res - pq.top() + lec[i].first > res) {
                res -= pq.top();
                res += lec[i].first;
                pq.pop();
                pq.push(lec[i].first);
            }
        }
    }
    cout << res << '\n';
}
*/