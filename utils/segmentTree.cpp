#include "test.hpp"

using namespace std;

vector<int> segment, arr;

int init(int start, int ed, int node) {
    if (start == ed) return segment[node] = arr[start];
    int mid = (start + ed) / 2;
    segment[node] = init(start, mid, node * 2) + init(mid + 1, ed, node * 2 + 1);
    return segment[node];
}

int sum(int start, int ed, int node, int left, int right) {
    if (ed < left || start > right) return 0;
    if (ed <= right && start >= left) return segment[node];
    int mid = (start + ed) / 2;
    int ret = sum(start, mid, 2 * node, left, right) + sum(mid + 1, ed, 2 * node + 1, left, right);
    return ret;
}

void update(int start, int ed, int node, int index, int diff) {
    if (index < start || index > ed) return;
    segment[node] += diff;
    if (start == ed) return;
    int mid = (start + ed) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, ed, node * 2 + 1, index, diff);
}

int main(void) {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    segment = vector<int>(4 * n, 0);
    init(0, n - 1, 1);
    cout << segment[1] << endl;
    cout << sum(0, n - 1, 1, 0, 5) << endl;
    update(0, n - 1, 1, 1, -1);
    cout << segment[1] << endl;
}