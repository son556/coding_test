#include <bits/stdc++.h>

using namespace std;

int* func(void) {
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	return &arr[0];
}

int *funcGood(void) {
	int *arr = new int[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	return arr;
}

int main(void) {
	int *arr = funcGood();
	for (int i = 0; i < 10; i++)
		cout << arr[i] << '\n';
}