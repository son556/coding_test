#include "test.hpp"
#include <random>
using namespace std;

vector<string> users, algorithms;
map<string, vector<string>> res;
mt19937 gen;

void makeAlgo() {
    int num;
    gen.seed(time(NULL));
    uniform_int_distribution<int> dis(0, 3);

    int target = dis(gen);
    shuffle(algorithms.begin(), algorithms.end(), gen);
    int idx = 0;
    for (int i = 0; i < users.size(); i++) {
        if (i == target) {
            for (int j = idx; j < idx + 2; j++)
                res[users[i]].push_back(algorithms[j]);
            idx += 2;
        }
        else {
            for (int j = idx; j < idx + 3; j++)
                res[users[i]].push_back(algorithms[j]);
            idx += 3;
        }
    }
    shuffle(users.begin(), users.end(), gen);
}

int main(void) {
    users.push_back("chanson");
    users.push_back("dokoh");
    users.push_back("seycheon");
    users.push_back("sanghhan");

    algorithms.push_back("백트래킹");
    algorithms.push_back("dp");
    algorithms.push_back("그리디");
    algorithms.push_back("다익스트라");
    algorithms.push_back("시뮬레이션");
    algorithms.push_back("bfs");
    algorithms.push_back("mst");
    algorithms.push_back("이분탐색");
    algorithms.push_back("투 포인터");
    algorithms.push_back("dfs");
    algorithms.push_back("플로이드 워셜");
    makeAlgo();

    for (auto it : res) {
        cout << it.first << " : ";
        for (int i = 0; i < it.second.size(); i++) {
            if (i == it.second.size() - 1)
                cout << it.second[i];
            else
                cout << it.second[i] << ", ";
        }
        cout << endl;
    }
    cout << "----------------------------------------\n";
    cout << "s1 ~ g4: ";
    for (int i = 0; i < 2; i++) {
        if (i != 1)
            cout << users[i] << ", ";
        else
            cout << users[i] << '\n';
    }
    cout << "g3 ~ g1: ";
    for (int i = 2; i < 4; i++) {
        if (i != 3)
            cout << users[i] << ", ";
        else
            cout << users[i] << '\n';
    }
}
