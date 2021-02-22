#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int mat[1000][1000];
int v[1000][1000];

int main(void) {
	int row, col;
	scanf("%d%d", &row, &col);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf("%1d", &mat[i][j]);
		}
	}
	for (int i = 0; i < col; ++i) {
		v[0][i] = mat[0][i];
	}
	for (int i = 0; i < row; ++i) {
		v[i][0] = mat[i][0];
	}
	for (int i = 1; i < row; ++i) {
		for (int j = 1; j < col; ++j)
		{
			if (mat[i][j] == 0) {
				v[i][j] = 0;
			}
			else {
				int g = min(v[i - 1][j], v[i - 1][j - 1]);
				g = min(v[i][j - 1], g);
				++g;
				v[i][j] = g;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			ans = max(ans, v[i][j]);
		}
	
	}
	printf("%d", ans * ans);

}