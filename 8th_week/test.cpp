#include "test.hpp"

//#include <bits/stdc++.h>

using namespace std;

void func1();

void func2() {
    cout << "called func2" << endl;
    func1();
}

void func1() {
    cout << "called func1" << endl;
    func2();
}

int main() {
    func1();
}

// 다음 2-K_3474