#include "test.hpp"

// 8-E_2302

//#include <bits/stdc++.h>

using namespace std;

int n, m;
int seats[41];
int dp[41][2][2][2];

int go(int sn, int s1, int s2, int s3)
{
	if (seats[sn] && s2)
		return -1;
	if (sn == n && s1 && s2)
		return -1;
	if (sn == n)
		return 1;
	int &ret = dp[sn][s1][s2][s3];
	if (ret) return ret;
	if (seats[sn])
		ret += max(go(sn + 1, 1, s3, 0), 0);
	else
	{
		if (s1 == 0 && sn != 1)
			ret += max(go(sn + 1, s2, s3, 0), 0);
		if (s2 == 0)
			ret += max(go(sn + 1, 1, s3, 0), 0);
		if (s3 == 0 && sn != n)
			ret += max(go(sn + 1, s2, 1, 0), 0);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> m;
	int x;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		seats[x] = 1;
	}
	cout << go(1, 0, 0, 0) << '\n';
}

/*
현재 인덱스에서 자리를 안바꾸면 다음인덱스로 바꿀 수 있으면 다다음 인덱스로
#include<bits/stdc++.h>
using namespace std; 
#define prev fuck
typedef long long ll;
void fastIO(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}        
int n, m, dp[41], cnt[41], temp;
int go(int pos){ 
	if(pos >= n - 1) return 1; 
	if(cnt[pos]) return go(pos + 1); 
	if(dp[pos] != -1) return dp[pos];
	int &ret = dp[pos];
	ret = 0;
	if(!cnt[pos + 1]) ret += (go(pos + 2) + go(pos + 1)); 
	else ret += go(pos + 1); 
	return ret;
}
int main(){ 
	fastIO();
	cin >> n >> m; 
	for(int i = 0; i < m; i++){
		cin >> temp; cnt[temp - 1] = 1; 
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0)<< "\n"; 
	return 0;
}
*/

/*
9
2
4
7

12
*/