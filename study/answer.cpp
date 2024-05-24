#include "test.hpp"
#include <random>
using namespace std;

vector<string> users, problem;
mt19937 gen, gen1;


int main() {
    string p;
    for (int i = 0; i < 4; i++) {
        cin >> p;
        problem.push_back(p);
    }
    users.push_back("chanson");
    users.push_back("dokoh");
    users.push_back("seycheon");
    users.push_back("sanghhan");
    gen1.seed(time(NULL));
    shuffle(users.begin(), users.end(), gen1);
    for (int i = 0; i < users.size(); i++) {
        cout << "[ " << users[i] << " : " << problem[i] << " ]  ";
    }
    cout << endl;
}