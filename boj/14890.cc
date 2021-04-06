#include <iostream>
#include <cstdio>
using namespace std;

int row, l;
int mat[100][100];
int root[100], ans = 0, que, bef;

void dfs() {
	que = -1;
	bef = root[0];
	for (int i = 1; i < row; ++i) {
		if (bef == root[i]) continue;
		else if (bef > root[i]) {
			if (bef - 1 == root[i]) {
				for (int j = 1; j < l; ++j) {
					if (root[i + j] == root[i]);
					else return;
				}
				que = i + l - 1;
				bef = root[i];
				i = que;
			}
			else return;
		}
		else {
			if (bef + 1 == root[i]) {
				if (que < i - l && i - l >= 0);
				else return;
				for (int j = 1; j <= l; ++j) {
					if (root[i - j] == bef);
					else return;
				}
				bef = root[i];
			}
			else return;
		}
	}
	++ans;
}

int main(void) {
	scanf("%d%d", &row, &l);
	
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			root[j] = mat[i][j];
		}
		dfs();
		for (int j = 0; j < row; ++j) {
			root[j] = mat[j][i];
		}
		dfs();
	}
	printf("%d", ans);

	return 0;
}