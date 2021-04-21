#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int row;
int mat[20][20];
int d1, d2;
int root[5];
int full = 0;
int ans = 987654321;


void dfs(int x, int y) {
	int kk = 0;
	int su = 0;
	for (int i = 0; i < 5; ++i) {
		root[i] = 0;
	}
	for (int i = 0; i < x - d1; ++i) {
		for (int j = 0; j <= y + d1; ++j)
			root[0] += mat[i][j];
	}
	for (int i = x - d1; i < x; ++i) {
		for (int j = 0; j < y + d1 - kk; ++j) {
			root[0] += mat[i][j];
		}
		kk++;
	}
	for (int i = row - 1; i > x + d2; --i) {
		for (int j = 0; j < y + d2; ++j)
			root[2] += mat[i][j];
	}
	kk = 0;
	for (int i = x + d2; i >= x; --i) {
		for (int j = 0; j < y + d2 - kk; ++j) {
			root[2] += mat[i][j];
		}
		kk++;
	}
	for (int i = 0; i < x - d1; ++i) {
		for (int j = row - 1; j > y + d1; --j)
			root[1] += mat[i][j];
	}
	kk = 0;
	for (int i = x - d1; i <= x - d1 + d2; ++i) {
		for (int j = row - 1; j > y + d1 + kk; --j) {
			root[1] += mat[i][j];
		}
		kk++;
	}
	for (int i = row - 1; i > x + d2; --i) {
		for (int j = row - 1; j >= y + d2; --j)
			root[3] += mat[i][j];
	}
	kk = 0;
	for (int i = x + d2; i > x - d1 + d2; --i) {
		for (int j = row - 1; j > y + d2 + kk; --j) {
			root[3] += mat[i][j];
		}
		kk++;
	}
	for (int i = 0; i < 4; ++i)
		su += root[i];
	root[4] = full - su;

	sort(root, root + 5);
	if (ans > root[4] - root[0]) ans = root[4] - root[0];
}

void bfs(int x, int y) {
	for (int i = 1; i < row; ++i) {
		if (x - i >= 0) {
			for (int j = 1; j < row; ++j) {
				if (x + j < row && y + i + j < row) {
					d1 = i;
					d2 = j;
					dfs(x,y);
				}
				else break;
			}
		}
		else break;
	}
}

int main(void) {
	scanf("%d", &row);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat[i][j]);
			full += mat[i][j];
		}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			bfs(i, j);
		}
	}

	printf("%d", ans);
	return 0;
}