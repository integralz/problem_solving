#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int num, check;
vector<int> v;
void print() {
	for (int i = 0; i < check; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dfs(int start, int cou) {
	if (cou == check) {
		print();
	}
	else {
		for (int i = start; i < num; i++) {
			v.push_back(i + 1);
			dfs(i, cou + 1);
			v.pop_back();
		}
	}
}

int main(void) {
	scanf("%d %d", &num, &check);

	dfs(0,0);
	return 0;
}