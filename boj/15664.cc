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
	for (int i = 0; i < check; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int start,int cou) {
	int a = 0;
	if (cou == check) print();
	else {
		for (int i = start; i < num; i++) {
			if (tf[i] == 1) {
				a = 0;
				continue;
			}
			if (i != 0 && a == 1) {
				if (arr[i] == arr[i - 1])
					continue;
				else {
					v.push_back(arr[i]);
					tf[i] = 1;
					dfs(i, cou + 1);
					v.pop_back();
					tf[i] = 0;
					a = 1;
				}
			}
			else {
				v.push_back(arr[i]);
				tf[i] = 1;
				dfs(i, cou + 1);
				v.pop_back();
				tf[i] = 0;
				a = 1;
			}
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
	return 0;
}