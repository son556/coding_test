#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > lines, points;
int n, x, y;
long long res;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0] < v2[0];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        b.clear();
        b.push_back(x);
        b.push_back(y);
        sort(b.begin(), b.end());
        points.push_back(b);
    }
    sort(points.begin(), points.end(), cmp);
    int start, end, sw;
    for (int i = 0; i < points.size(); i++) {
        sw = 0;
        for (int j = 0; j < lines.size(); j++) {
            start = lines[j][0];
            end = lines[j][1];
            if (start >= points[i][0] && end <= points[i][1]) {
                lines[j][0] = points[i][0];
                lines[j][1] = points[i][1];
                sw = 1;
                break;
            }
            if (start <= points[i][0] && points[i][0] <= end && points[i][1] > end) {
                lines[j][1] = points[i][1];
                sw = 1;
                break;
            }
            if (start <= points[i][1] && points[i][1] <= end && points[i][0] < start) {
                lines[j][0] = points[i][0];
                sw = 1;
                break;
            }
            if (start <= points[i][0] && end >= points[i][1]) {
                sw = 1;
                break;
            }
        }
        if (sw == 0) {
            b.clear();
            b.push_back(points[i][0]);
            b.push_back(points[i][1]);
            lines.push_back(b);
        }
    }
    for (int i = 0; i < lines.size(); i++) res += lines[i][1] - lines[i][0];
    cout << res << endl;
}

///// 답지

typedef pair<int, int> P;
P L[1000004];
int n, from, to, l, r, ret; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        cin >> from >> to;
        L[i] = P(from, to);
    }
    sort(L, L + n); 
    l = L[0].first; r = L[0].second; 
    for(int i = 1; i < n; i++){ 
        if(r < L[i].first){ 
            ret += (r - l); 
            l = L[i].first;
            r = L[i].second;
        }else if(L[i].first <= r && L[i].second >= r){ 
            r = L[i].second;
        }
    }
    ret += r - l;
    cout << ret << '\n';
}