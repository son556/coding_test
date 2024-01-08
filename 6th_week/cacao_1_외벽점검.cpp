#include "test.hpp"
// #include <bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
vector<int> changeStartIdx(vector<int> weak, int start, int n){
    if(start == 0) return weak;
    vector<int> ret; 
    for(int i = start; i < weak.size(); i++)ret.push_back(weak[i]);
    for(int i = 0; i < start; i++)ret.push_back(weak[i] + n);
    return ret; 
}
int solution(int n, vector<int> weak, vector<int> dist) { 
    int ret = INF;
    sort(dist.begin(), dist.end()); 
    do{ 
        for(int j = 0; j < (int)weak.size(); j++){
            vector<int> weakList = changeStartIdx(weak, j, n);  
            int idx = 0, flag = 0;
            int curr = weakList[0] + dist[0]; 
            for(int i = 1; i < weakList.size(); i++){
                if(weakList[i] > curr){ 
                    if(idx + 1 == dist.size()){
                        flag = 1;
                        break;
                    }
                    curr = weakList[i] + dist[++idx];
                }
            }
            if(!flag) ret = min(ret, idx + 1); 
        }
    }while(next_permutation(dist.begin(), dist.end()));  
    if (ret == INF) return -1;
    return ret;
}