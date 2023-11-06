#include "test.hpp"

//#include <bits/stdc++.h>
// string erase 기억하자.

using namespace std;

string str, boom, cmp;
stack<string> box;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	cin >> boom;

	for (int i = 0; i < str.length(); i++)
	{
		box.push(str.substr(i, 1));
		while (box.size() >= boom.length())
		{
			cmp = "";
			for (int j = 0; j < boom.length(); j++)
			{
				cmp += box.top();
				box.pop();
			}
			reverse(cmp.begin(), cmp.end());
			if (cmp != boom)
			{
				for (int j = 0; j < cmp.length(); j++)
					box.push(cmp.substr(j, 1));
				break;
			}
		}
	}
	if (box.size())
	{
		cmp = "";
		while (box.size())
		{
			cmp += box.top();
			box.pop();
		}
		reverse(cmp.begin(), cmp.end());
		cout << cmp << endl;
	}
	else
		cout << "FRULA" << endl;
}


// #include <bits/stdc++.h>
// using namespace std;
// string S, T, ret;
// int main() {
//     cin >> S >> T;
//     for(char a : S){
//         ret += a;
//         if(ret.size() >= T.size() && ret.substr(ret.size() - T.size(), T.size()) == T){
//             ret.erase(ret.end() - T.size(), ret.end()); 
//         }
//     }
//     if(!ret.size())cout << "FRULA" << "\n";
//     else cout << ret << "\n";
//     return 0;
// }