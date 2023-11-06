#include "test.hpp"

//#include<bits/stdc++.h>
using namespace std;
// 최대 -> 최소를 작게 or 최대를 크게
// 그리디 -> sort or priority queue or 둘 다
// priority queue같은 경우 일단 넣어보고 처리해주는 문제가 많다.
// 정렬 pq유형은 암기가 필요

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