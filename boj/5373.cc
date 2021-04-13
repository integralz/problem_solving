#include <iostream>
#include <cstdio>
using namespace std;

int num;
char mat[6][3][3];
int ord;
char ho, whe;

void rot(int wh,char di) {
	char que1, que2;
	if (di == '+') {
		que1 = mat[wh][2][0];
		que2 = mat[wh][2][1];
		for (int i = 0; i < 2; ++i) {
			mat[wh][2][i] = mat[wh][2 - i][2];
			mat[wh][2 - i][2] = mat[wh][0][2 - i];
			mat[wh][0][2 - i] = mat[wh][i][0];
		}
		mat[wh][0][0] = que1;
		mat[wh][1][0] = que2;
	}
	else {
		que1 = mat[wh][2][0];
		que2 = mat[wh][2][1];
		for (int i = 0; i < 2; ++i) {
			mat[wh][2][i] = mat[wh][i][0];
			mat[wh][i][0] = mat[wh][0][2 - i];
			mat[wh][0][2 - i] = mat[wh][2 - i][2];
		}
		mat[wh][2][2] = que1;
		mat[wh][1][2] = que2;
	}
}

void dfs(char wh, char di) {
	char root[3];
	if (wh == 'U') {
		rot(0, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[5][0][i];
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					mat[5 - i][0][j] = mat[4 - i][0][j];
				}
			}
			for (int i = 0; i < 3; ++i) {
				mat[2][0][i] = root[i];
			}
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[2][0][i];
			for(int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) {
					mat[2 + i][0][j] = mat[3 + i][0][j];
				}
			for (int i = 0; i < 3; ++i)
				mat[5][0][i] = root[i];
		}
	}
	else if (wh == 'D') {
		rot(1, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[2][2][i];
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) {
					mat[2 + i][2][j] = mat[3 + i][2][j];
				}
			for (int i = 0; i < 3; ++i)
				mat[5][2][i] = root[i];
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[5][2][i];
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					mat[5 - i][2][j] = mat[4 - i][2][j];
				}
			}
			for (int i = 0; i < 3; ++i) {
				mat[2][2][i] = root[i];
			}
		}
	}
	else if (wh == 'F') {
		rot(2, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[1][0][i];
			for (int i = 0; i < 3; ++i) {
				mat[1][0][i] = mat[5][2 - i][0];
				mat[5][2 - i][0] = mat[0][2][2 - i];
				mat[0][2][2 - i] = mat[3][i][2];
			}
			for (int i = 0; i < 3; ++i)
				mat[3][i][2] = root[i];
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[1][0][i];
			for (int i = 0; i < 3; ++i) {
				mat[1][0][i] = mat[3][i][2];
				mat[3][i][2] = mat[0][2][2 - i];
				mat[0][2][2 - i] = mat[5][2 - i][0];
			}
			for (int i = 0; i < 3; ++i)
				mat[5][2 - i][0] = root[i];
		}
	}
	else if (wh == 'L') {
		rot(3, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][i][0];
			for (int i = 0; i < 3; ++i) {
				mat[0][i][0] = mat[4][2 - i][2];
				mat[4][2 - i][2] = mat[1][i][0];
				mat[1][i][0] = mat[2][i][0];
			}
			for (int i = 0; i < 3; ++i)
				mat[2][i][0] = root[i];
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][i][0];
			for (int i = 0; i < 3; ++i) {
				mat[0][i][0] = mat[2][i][0];
				mat[2][i][0] = mat[1][i][0];
				mat[1][i][0] = mat[4][2 - i][2];
			}
			for (int i = 0; i < 3; ++i)
				mat[4][2 - i][2] = root[i];
		}
	}
	else if (wh == 'B') {
		rot(4, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][0][i];
			for (int i = 0; i < 3; ++i) {
				mat[0][0][i] = mat[5][i][2];
				mat[5][i][2] = mat[1][2][2 - i];
				mat[1][2][2 - i] = mat[3][2 - i][0];
			}
			for (int i = 0; i < 3; ++i)
				mat[3][2 - i][0] = root[i];
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][0][i];
			for (int i = 0; i < 3; ++i) {
				mat[0][0][i] = mat[3][2 - i][0];
				mat[3][2 - i][0] = mat[1][2][2 - i];
				mat[1][2][2 - i] = mat[5][i][2];
			}
			for (int i = 0; i < 3; ++i)
				mat[5][i][2] = root[i];
		}
	}
	else {
		rot(5, di);
		if (di == '+') {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][i][2];
			for (int i = 0; i < 3; ++i) {
				mat[0][i][2] = mat[2][i][2];
				mat[2][i][2] = mat[1][i][2];
				mat[1][i][2] = mat[4][2 - i][0];
			}
			for (int i = 0; i < 3; ++i)
				mat[4][2 - i][0] = root[i];
		}
		else {
			for (int i = 0; i < 3; ++i)
				root[i] = mat[0][i][2];
			for (int i = 0; i < 3; ++i) {
				mat[0][i][2] = mat[4][2 - i][0];
				mat[4][2 - i][0] = mat[1][i][2];
				mat[1][i][2] = mat[2][i][2];
			}
			for (int i = 0; i < 3; ++i)
				mat[2][i][2] = root[i];
		}
	}
}

int main(void) {
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%d", &ord);
		for(int k = 0; k < 3; ++k)
			for (int z = 0; z < 3; ++z) {
				mat[0][k][z] = 'w';
				mat[1][k][z] = 'y';
				mat[2][k][z] = 'r';
				mat[3][k][z] = 'g';
				mat[4][k][z] = 'o';
				mat[5][k][z] = 'b';
			}
		for (int j = 0; j < ord; ++j) {
			scanf("%c", &ho);
			if(ho == ' ' || ho == '\n')
				scanf("%c%c", &ho, &whe);
			else scanf("%c", &whe);
			dfs(ho, whe);
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				printf("%c",mat[0][i][j]);
			printf("\n");
		}
	}
	return 0;
}