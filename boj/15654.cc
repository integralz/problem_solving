#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int num, check;
vector<int> v;
int *arr;
bool *tf;

void print() {
	for (int i = 0; i < check; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dfs(int cou) {
	if (cou == check) {
		print();
	}
	else {
		for (int i = 0; i < num; i++) {
			if (tf[i] == 1) continue;
			v.push_back(arr[i]);
			tf[i] = 1;
			dfs(cou + 1);
			v.pop_back();
			tf[i] = 0;
		}
	}

}

int main(void) {
	scanf("%d %d", &num, &check);
	arr = new int[num];
	tf = new bool[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
		tf[i] = 0;
	}
	sort(arr, arr + num);

	dfs(0);

	delete[] arr;
	delete[] tf;
	return 0;
}