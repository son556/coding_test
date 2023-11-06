#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

const int max_n = 500000; 
int visited[2][max_n + 4], a, b, ok, turn = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if(a == b)
	{cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1;
    q.push(a);
    while(q.size())
	{
        b += turn;
        if(b > max_n)
			break;  
        if(visited[turn % 2][b]) 
		{
            ok = true;
            break;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++)
		{
            int x = q.front();
			q.pop();
			for(int nx : {x + 1, x - 1, x * 2})
			{
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) 
					continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; 
                if(nx == b)
				{
                    ok = 1; 
					break;
				}
                q.push(nx); 
			} 
			if(ok)
				break;
        }
        if(ok)
			break;
        turn++;
    }
    if(ok) 
		cout << turn << "\n";
    else 
		cout << -1 << "\n";
    return 0;
}

/* 내 풀이 짝수일 때 홀수일 때 나눠서 방문체크
int arr[500004], visited[2][500004];
int n, k, res = -1;

void go(int now)
{
	int tmp, now_k, idx, nn;
	queue<pair<int, int>> q;
	visited[0][now] = 1;
	q.push({now, 0});
	while (q.size())
	{
		tie(now, tmp) = q.front();
		q.pop();
		now_k = tmp * (1 + tmp) / 2 + k;
		if (now_k > 500000)
		{
			res = -1;
			return;
		}
		if (now == now_k)
		{
			res = tmp;
			return ;
		}
		if (visited[tmp % 2][now_k])
		{
			res = tmp;
			return ;
		}
		for (int nx : {now + 1, now - 1, now * 2})
		{
			if (nx < 0 || nx > 500000 || visited[(tmp + 1) % 2][nx]) continue;
			visited[(tmp + 1) % 2][nx] = tmp + 1;
			q.push({nx, tmp + 1});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	go(n);
	cout << res;
}
*/