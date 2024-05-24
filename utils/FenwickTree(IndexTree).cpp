#include "test.hpp"

using namespace std;

int n;
vector<int> fenwickTree;

void update(int idx, int diff) {
    while (idx <= n) {
        fenwickTree[idx] += diff;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int total = 0;
    while (idx > 0) {
        total += fenwickTree[idx];
        idx -= (idx & -idx);
    }
    return total;
}

int query(int start, int end) {
    return sum(end) - sum(start - 1);
}

int main(void) {
    cin >> n;
    fenwickTree = vector<int>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        update(i + 1, num);
    }
    cout << sum(n) << endl;
    cout << query(3, n) << endl;
}