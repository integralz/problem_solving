#include <iostream>
#include <cstdio>

using namespace std;

int row, col, tim;
int mat[50][50];
int root[50][50];
int mat1[50];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int sum;


void che() {
	int que = 0;
	int mok;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			root[i][j] = 0;
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (mat[i][j] == mat[i + 1][j] && i < row - 1 && mat[i][j] != 0) {
				root[i][j] = 1;
				root[(i + 1) % row][j] = 1;
				que = 1;
			}
			if (mat[i][j] == mat[i][(j + 1) % col] && mat[i][j] != 0) {
				root[i][j] = 1;
				root[i][(j + 1) % col] = 1;
				que = 1;
			}
		}
	}
	if (que == 0) {
		sum = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (mat[i][j] != 0) {
					sum += mat[i][j];
					++que;
				}
			}
		}
		mok = sum / que;
		if (sum  % que == 0) {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					if (mat[i][j] != 0) {
						if (mat[i][j] < mok) mat[i][j]++;
						else if (mat[i][j] > mok) mat[i][j]--;
					}
				}
			}
		}
		else {
			for(int i = 0; i < row; ++i)
				for (int j = 0; j < col; ++j) {
					if (mat[i][j] != 0) {
						if (mat[i][j] <= mok) mat[i][j]++;
						else mat[i][j]--;
					}
				}
		}
	}
	else {
		for(int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) {
				if (root[i][j] == 1)
					mat[i][j] = 0;
			}
	}
}

void dfs(int x, int dir, int cou) {
	if (dir == 0) {
		for (int i = x - 1; i < row; i += x) {
			for (int j = 0; j < col; ++j) {
				mat1[j] = mat[i][(j - cou + col) % col];
			}
			for (int j = 0; j < col; ++j)
				mat[i][j] = mat1[j];
		}
	}
	else {
		for (int i = x - 1; i < row; i += x) {
			for (int j = 0; j < col; ++j) {
				mat1[j] = mat[i][(j + cou) % col];
			}
			for (int j = 0; j < col; ++j)
				mat[i][j] = mat1[j];
		}
	}
}

int main(void) {
	int x, y, z;
	scanf("%d%d%d", &row, &col, &tim);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%d", &mat[i][j]);
		}
	for (int i = 0; i < tim; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		dfs(x, y, z);
		che();
	}
	sum = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			sum += mat[i][j];
	}
	printf("%d", sum);
}