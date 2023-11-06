#include "test.hpp"
//#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[54][54], visited[54][54], cp[54][54], ret = -1, room, cnt;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void cnt_room(int y, int x)
{
	int ny, nx, idx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if ((cp[y][x] & (1 << i)) != 0) continue;
		if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		room++;
		cnt_room(ny, nx);
	}
}

void room_n()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
			{
				cnt++;
				room = 1;
				visited[i][j] = 1;
				cnt_room(i, j);
				ret = max(ret, room);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			cp[i][j] = arr[i][j];
		}
	}
	room_n();
	cout << cnt << '\n' << ret << '\n';
	ret = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (cp[i][j] & (1 << k))
				{
					cp[i][j] = cp[i][j] ^ (1 << k);
					memset(visited, 0, sizeof(visited));
					room_n();
					cp[i][j] = arr[i][j];
				}
			}
		}
	}
	cout << ret;
}
/* connected component 개수 cnt 하는 dfs
int dfs(int y, int x, int cnt){
    if(visited[y][x]) return 0; 
    visited[y][x] = cnt; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            ret += dfs(ny, nx, cnt); 
        } 
    } 
    return ret; 
} 
*/