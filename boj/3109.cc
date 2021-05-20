#include <iostream>
#include <cstdio>
using namespace std;

int row, col;
int mat[10000][500];
int dir[3] = { -1,0,1 };
int ans;
int que = 0;

void dfs(int startx, int starty) {
	int nx, ny;
	if (starty == col - 1) {
		que = 1;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			nx = startx + dir[i];
			ny = starty + 1;
			if (nx >= 0 && nx < row && mat[nx][ny] == 0) {
				mat[nx][ny] = 2;
				dfs(nx, ny);
				if (que == 1) return;
			}
		}
	}
	
}

int main(void) {
	char a;
	int nx, ny;
	scanf("%d%d", &row, &col);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%c", &a);
			if (a == '\n') scanf("%c", &a);
			if (a == 'x') mat[i][j] = 1;
			else mat[i][j] = 0;
		}

	for (int i = 0; i < row; ++i) {
		que = 0;
		dfs(i, -1);
	}
	for (int i = 0; i < row; ++i)
		if (mat[i][col - 1] == 2) ans++;
	printf("%d", ans);
}