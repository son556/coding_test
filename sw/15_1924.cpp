#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> cal;
vector<string> yo;
string arr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int arr31[] = {1, 3, 5, 7, 8, 10, 12};
int arr30[] = {4, 6, 9, 11};
int m, d;

int check(int idx) {
    for (int i = 0; i < 7; i++) {
        if (arr31[i] == idx) return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (arr30[i] == idx) return 2;
    }
    return 0;
}

int main() {
    
    int flag = 1;
    for (int i = 0; i < 12; i++) {
        yo.clear();
        int idx = check(i + 1);
        if (idx == 0) {
            for (int j = 0; j < 28; j++) {
                yo.push_back(arr[flag]);
                flag++;
                if (flag == 7) flag = 0;
            }
            cal.push_back(yo);
        }
        else if (idx == 1) {
            for (int j = 0; j < 31; j++) {
                yo.push_back(arr[flag]);
                flag++;
                if (flag == 7) flag = 0;
            }
            cal.push_back(yo);
        }
        else {
            for (int j = 0; j < 30; j++) {
                yo.push_back(arr[flag]);
                flag++;
                if (flag == 7) flag = 0;
            }
            cal.push_back(yo);
        }
    }
    cin >> m >> d;
    cout << cal[m - 1][d - 1] << endl;
}