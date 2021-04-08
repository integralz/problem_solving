#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col, num;
int mat[30][10];
int ans = 4;
int ff;

int find() {
	int a;
	for (int i = 0; i < col; ++i) {
		a = i;
		for (int j = 0; j < row; ++j) {
			if (mat[j][a] != 0) {
				if (a - 1 >= 0 && mat[j][a - 1] == mat[j][a]) a = a - 1;
				else a = a + 1;
			}
		}
		if (a != i) return 0;
	}
	return 1;
}

void dfs(int x, int y, int co, int ma) {
	int que;
	if (co == ma) {
		que = find();
		if (que) {
			if (ans > ma) {
				ans = ma;
			}
		}
	}
	else {
		for (int i = y; i < col - 1; ++i) {
			if (mat[x][i] == 0) {
				if (mat[x][i + 1] == 0) {
					mat[x][i] = ff;
					mat[x][i + 1] = ff;
					ff++;
					dfs(x, i + 1, co + 1, ma);
					ff--;
					mat[x][i] = 0;
					mat[x][i + 1] = 0;
				}
			}
		}
		for (int i = x + 1; i < row; ++i) {
			for (int j = 0; j < col - 1; ++j) {
				if (mat[i][j] == 0) {
					if (mat[i][j + 1] == 0){
						mat[i][j] = ff;
						mat[i][j + 1] = ff;
						ff++;
						dfs(i, j + 1, co + 1, ma);
						ff--;
						mat[i][j] = 0;
						mat[i][j + 1] = 0;
					}
				}
			}
		}
	}
}

int main(void) {
	int g, h;
	ff = 1;
	scanf("%d%d%d", &col, &num, &row);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &g, &h);
		--g;
		mat[g][h] = ff;
		mat[g][h - 1] = ff;
		ff++;
	}
	for (int i = 0; i <= 3; ++i) {
		dfs(0, 0, 0, i);
	}
	if(ans != 4)
	printf("%d", ans);
	else printf("%d", -1);
	return 0;
}