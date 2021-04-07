#include <iostream>
#include <cstdio>
using namespace std;

int mat[4][8];
int dir[4];
int num;
int ans = 0;
int cou, ord;

void go() {
	int ch;
	for (int i = 0; i < 4; ++i) {
		if (dir[i] != 0) {
			if (dir[i] == 1) {
				ch = mat[i][7];
				for (int j = 7; j > 0; --j) {
					mat[i][j] = mat[i][j - 1];
				}
				mat[i][0] = ch;
			}
			else{
				ch = mat[i][0];
				for (int j = 0; j < 7; ++j) {
					mat[i][j] = mat[i][j + 1];
				}
				mat[i][7] = ch;
			}
		}
	}
}

void dfs(int co, int way) {
	int w = way;
	for (int i = 0; i < 4; ++i) {
		dir[i] = 0;
	}
	dir[co - 1] = way;

	for (int i = co; i < 4; ++i) {
		if (mat[i][6] == mat[i - 1][2]) break;
		else {
			w *= -1;
			dir[i] = w;
		}
	}
	w = way;
	for (int i = co - 2; i >= 0; --i) {
		if (mat[i][2] == mat[i + 1][6]) break;
		else {
			w *= -1;
			dir[i]= w;
		}
	}
	go();
}


int main(void) { 
	int g = 1;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 8; ++j)
			scanf("%1d", &mat[i][j]);

	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &cou, &ord);
		dfs(cou, ord);
	}
	for (int i = 0; i < 4; ++i) {
		if (mat[i][0] == 1) {
			ans += g;
		}
		g *= 2;
	}
	printf("%d", ans);
}