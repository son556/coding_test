#include <iostream>
#include <vector>

using namespace std;
vector<int> che;

vector<int> eraChe(int num) // 1000만 이상이면 힘들다
{
    che = vector<int>(num, 0);
    vector<int> v;
    for (int i = 2; i <= num; i++) {
        if (che[i]) continue;
        for (int j = 2 * i; j <= num; j += i)
            che[i] = 1;
    }
    for (int i = 2; i <= num; i++) {
        if (che[i] == 0)
            v.push_back(i);
    }
    return v;
}

bool check(int num) { // 크기가 큰 경우
    if (num < 2) return false;
    if (num == 2) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}