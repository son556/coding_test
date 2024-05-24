#include "test.hpp"

//#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> karts[100004];
deque<pair<ll, ll>> cus;
vector<ll> res;
ll n, k, id, w;
ll t;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> id >> w;
        cus.push_back({id, w});
    }
    for (int i = 0; i < k; i++) {
        if (cus.size() == 0) break;
        karts[i] = cus.front();
        cus.pop_front();
    }
    
    while (res.size() != n) {
        stack<ll> box;
        for (int i = 0; i < k; i++) {
            if (karts[i].second == t && karts[i].second) {
                box.push(karts[i].first);
                if (cus.size()) {
                    karts[i].first = cus.front().first;
                    karts[i].second = t + cus.front().second;
                    cus.pop_front();
                }
                else
                    karts[i] = {0, 0};
            }
        }
        while (box.size()) {
            res.push_back(box.top());
            box.pop();
        }
        t++;
    }
    ll answer = 0;
    for (int i = 0; i < n; i++)
        answer += (i + 1) * res[i];
    cout << answer << '\n';
}

/* 
// 우선순위 큐 사용
#include<bits/stdc++.h>
using namespace std;   
int n, k, id, cost_time, _time, idx;
long long ret; 
struct Cacher{
    int id, maxTime, cacher_id;  
}; 
struct comp{
    bool operator()(Cacher & a, Cacher & b){
        if(a.maxTime == b.maxTime){
            return a.cacher_id > b.cacher_id; 
        }
        return a.maxTime > b.maxTime;  
    }
}; 

bool cmp2(const Cacher & a, const Cacher & b){
    if(a.maxTime == b.maxTime){
        return a.cacher_id > b.cacher_id; 
    }
    return a.maxTime < b.maxTime; 
}
priority_queue<Cacher, vector<Cacher>, comp> pq; 
vector<Cacher> v; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    cin >> n >> k;  
    for(int i = 0; i < n; i++){
        cin >> id >> cost_time; 
        if(i < k){
            pq.push({id, cost_time, i + 1});   
            continue;
        }    
        pq.push({id, cost_time + pq.top().maxTime, pq.top().cacher_id});  
        v.push_back(pq.top());
        pq.pop();    
    }   
    while(pq.size()){  
        v.push_back(pq.top());
        pq.pop();
    } 
    sort(v.begin(), v.end(), cmp2);
    for(int i = 0; i < v.size(); i++){
        ret += 1LL * (i + 1) * v[i].id; 
    }
    cout << ret << "\n"; 
    return 0;
}   
*/

// 다음 2-O_4949