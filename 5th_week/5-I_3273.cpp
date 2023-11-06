#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
int n, m, t, cnt;

bool cmp(int n1, int n2)
{
    return n1 > n2;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vec.push_back(m);
    }
    cin >> m;
    int s, e;
    s = 0;
    e = vec.size() - 1;
    sort(vec.begin(), vec.end(), cmp);
    if (vec.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    while(s < e)
    {
        t = vec[s] + vec[e];
        if (t == m)
        {
            cnt++;
            s++;
            e = vec.size() - 1;
        }
        else if (t > m)
            s++;
        else
            e--;
    }
    cout << cnt << endl;
}