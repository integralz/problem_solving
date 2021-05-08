#include <iostream>
#include <cstdio>
using namespace std;

int num;
int mat[1000001];


int changeunion(int a) {
	if (mat[a] == a) return a;
	else return mat[a] = changeunion(mat[a]);
}

void makeunion(int a, int b) {
	changeunion(a);
	changeunion(b);

	if (mat[a] > mat[b]) mat[mat[b]] = mat[a];
	else mat[mat[a]] = mat[b];
}
int find(int a, int b) {
	changeunion(a);
	changeunion(b);
	if (mat[a] == mat[b]) return 1;
	else return 0;
}

int main(void) {
	int n, a, b, ans, cou;
	scanf("%d %d", &cou, &num);

	for (int i = 0; i < cou + 1; i++) {
		mat[i] = i;
	}

	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &n, &a, &b);
		if (n == 0) {
			makeunion(a, b);
		}
		else {
			ans = find(a, b);
			if (ans == 1)
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
