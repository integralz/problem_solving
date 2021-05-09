#include <iostream>
#include <cstdio>
using namespace std;

int num, city;
int mat[200];
int cit[1000];

int listunion(int a) {
	if (a == mat[a]) return a;
	else return mat[a] = listunion(mat[a]);
}
void makeunion(int a, int b) {
	listunion(a);
	listunion(b);

	if (mat[b] > mat[a]) mat[mat[b]] = mat[a];
	else mat[mat[a]] = mat[b];
}

int main(void) {
	int a, ans;
	scanf("%d %d", &num, &city);

	for (int i = 0; i < num; ++i)
		mat[i] = i;

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			scanf("%d", &a);
			if (a == 1 && i > j) {
				makeunion(i, j);
			}
		}
	}
	for (int i = 0; i < num; ++i)
		listunion(i);
	

	for (int i = 0; i < city; ++i) {
		scanf("%d", &cit[i]);
		cit[i]--;
	}
	ans = mat[cit[0]];

	for (int i = 1; i < city; ++i) {
		if (ans == mat[cit[i]]);
		else {
			ans = -1;
			break;
		}
	}
	if (ans == -1)
		printf("NO");
	else printf("YES");

	return 0;
}