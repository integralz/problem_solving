#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int num, check;
int *arr;
bool *tf;
void print() {
	for (int i = 0; i < num; i++)
		if (tf[i] == 1)
			printf("%d ", arr[i]);
	printf("\n");
}
void dfs(int start, int cou) {
	if (cou == check) print();
	else {
		for (int i = start; i < num; i++) {
			tf[i] = 1;
			dfs(i + 1, cou + 1);
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

	dfs(0,0);

	delete[] arr;
	delete[] tf;
	return 0;
}