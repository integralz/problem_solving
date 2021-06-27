#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int num, check;
vector<int> v;
int *arr;

void print() {
	for (int i = 0; i < check; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int cou) {
	if (cou == check) print();
	else {
		for (int i = 0; i < num; i++) {
			v.push_back(arr[i]);
			dfs(cou + 1);
			v.pop_back();
		}
	}
}

int main(void) {
	scanf("%d %d", &num, &check);
	arr = new int[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + num);

	dfs(0);

	delete[] arr;
	return 0;
}