#include <iostream>
#include <cstdio>
using namespace std;

int row, col, x, y, num;
int mat[20][20];
int ord[1000];
int dice[4][3];
int dir[4][2] = { {0,1}, {0, -1}, {-1,0}, {1,0} };

void dfs(int cou) {
	int wh = ord[cou] - 1;
	int ch;
	x += dir[wh][0];
	y += dir[wh][1];

	if (x >= 0 && x < row && y >= 0 && y < col) {
		if (wh == 0) {
			ch = dice[1][2];
			for (int i = 0; i < 2; ++i) 
				dice[1][2 - i] = dice[1][1 - i];
			dice[1][0] = dice[3][1];
			dice[3][1] = ch;
		}
		else if (wh == 1) {
			ch = dice[1][0];
			for (int i = 0; i < 2; ++i)
				dice[1][i] = dice[1][i + 1];
			dice[1][2] = dice[3][1];
			dice[3][1] = ch;
		}
		else if (wh == 2) {
			ch = dice[0][1];
			for (int i = 0; i < 3; ++i)
				dice[i][1] = dice[i + 1][1];
			dice[3][1] = ch;
		}
		else {
			ch = dice[3][1];
			for (int i = 0; i < 3; ++i)
				dice[3 - i][1] = dice[2 - i][1];
			dice[0][1] = ch;
		}
		if (mat[x][y] == 0) {
			mat[x][y] = dice[3][1];
		}
		else {
			dice[3][1] = mat[x][y];
			mat[x][y] = 0;
		}
		printf("%d\n", dice[1][1]);
	}
	else {
		x -= dir[wh][0];
		y -= dir[wh][1];
	}

}

int main(void) {
	scanf("%d %d %d %d %d", &row, &col, &x, &y, &num);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			scanf("%d", &mat[i][j]);

	for (int i = 0; i < num; ++i)
		scanf("%d", &ord[i]);

	for (int i = 0; i < num; ++i) {
		dfs(i);
	}

	return 0;
}