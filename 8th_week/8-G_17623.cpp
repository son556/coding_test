#include "test.hpp"
// 8-G_17623, 점수는 어떻게 구할 지 생각해보기

//#include <bits/stdc++.h>

using namespace std;

map<char, char> book;
string dp[1004];
int n, t;
string answer, tmp;

string findmin(string str1, string str2) {
    if (str1.size() != str2.size()) {
        if (str1.size() < str2.size())
            return str1;
        if (str1.size() > str2.size())
            return str2;
    }
    for (int i = 0; i < str1.size(); i++) {
        if (book[str1[i]] < book[str2[i]]) return str1;
        if (book[str1[i]] > book[str2[i]]) return str2;
    }
    return str1;
}

string go(int num) {
    string &ret = dp[num];
    if (ret != tmp) return ret;
    for (int i = 1; i < num; i++) {
        ret = findmin(ret, go(i) + go(num - i));
    }
    if (num % 2 == 0) ret = findmin(ret, "(" + go(num / 2) + ")");
    if (num % 3 == 0) ret = findmin(ret, "{" + go(num / 3) + "}");
    if (num % 5 == 0) ret = findmin(ret, "[" + go(num / 5) + "]");
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 2000; i++) {
        tmp = tmp + "[]";
    }
    book.insert({'(', '1'});
    book.insert({')', '2'});
    book.insert({'{', '3'});
    book.insert({'}', '4'});
    book.insert({'[', '5'});
    book.insert({']', '6'});
    cin >> t;
    fill(dp, dp + 1004, tmp);
    dp[1] = "()";
    dp[2] = "{}";
    dp[3] = "[]";
    int num;
    while (t--) {
        cin >> num;
        cout << go(num) << '\n';
    }
}

/*
#include <bits/stdc++.h>
using namespace std; 
int t, n; 
string dp[1001];   
map<char, char> mp; 
char a[6] = {'(', ')', '{', '}', '[', ']'};
bool check(string before, string after){ 
	if(before == "" && after == "") return false; 
	if(before == "") return true;   
	if(before.size() == after.size()) return after < before;
	return after.size() < before.size(); 
}
 
int main(){  
	for(int i = 0; i < 6; i++){
		mp[i + '1'] = a[i];
	}  
	dp[1] = "12"; 
	dp[2] = "34";
	dp[3] = "56"; 
	for(int idx = 1; idx <= 1000; idx++){   
		if(idx % 2 == 0 && check(dp[idx], '1' + dp[idx / 2] + '2'))dp[idx] = '1' + dp[idx / 2] + '2'; 
		if(idx % 3 == 0 && check(dp[idx], '3' + dp[idx / 3] + '4'))dp[idx] = '3' + dp[idx / 3] + '4'; 
		if(idx % 5 == 0 && check(dp[idx], '5' + dp[idx / 5] + '6'))dp[idx] = '5' + dp[idx / 5] + '6';   
		for(int i = 1; i <= idx; i++){
			if(check(dp[idx], dp[i] + dp[idx - i]))dp[idx] = dp[i] + dp[idx - i]; 
		}
	}  
	cin >> t; 
	while(t--){
		cin >> n;
		for(char a : dp[n]) cout << mp[a];
		cout << "\n"; 
	} 
}
*/