#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col, tim;
vector <pair <pair <int, int>, int> > v;
int mat[50][50];
vector <int> air;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int ans = 0;

void dfs() {
	int x, y, nx, ny, l, siz, cou;
	int ch1, ch2;
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			if (mat[i][j] != -1 && mat[i][j] != 0) {
				v.push_back(make_pair(make_pair(i, j), mat[i][j]));
				mat[i][j] = 0;
			}
		}
	l = v.size();
	for (int i = l - 1; i >= 0; --i) {
		cou = 0;
		x = v.back().first.first;
		y = v.back().first.second;
		siz = v.back().second;
		v.pop_back();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != -1) {
				mat[nx][ny] += siz / 5;
				++cou;
			}
		}
		mat[x][y] += siz - ((siz / 5) * cou);
	}
	for (int i = air[0] - 1; i >= 1; --i) {
		mat[i][0] = mat[i - 1][0];
	}
	for (int i = air[1] + 1; i < row - 1; ++i) {
		mat[i][0] = mat[i + 1][0];
	}
	for (int i = 0; i < col - 1; ++i) {
		mat[0][i] = mat[0][i + 1];
		mat[row - 1][i] = mat[row - 1][i + 1];
	}
	for (int i = 0; i < air[0]; ++i) {
		mat[i][col - 1] = mat[i + 1][col - 1];
	}
	for (int i = row - 1; i > air[1]; --i) {
		mat[i][col - 1] = mat[i - 1][col - 1];
	}

	for (int i = col - 1; i > 1; --i) {
		mat[air[0]][i] = mat[air[0]][i - 1];
		mat[air[1]][i] = mat[air[1]][i - 1];
	}
	mat[air[0]][1] = 0;
	mat[air[1]][1] = 0;
}

int main(void) {
	scanf("%d %d %d", &row, &col, &tim);
	for(int i = 0 ; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == -1) {
				air.push_back(i);
			}
		}
	for (int i = 0; i < tim; ++i) {
		dfs();
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (mat[i][j] > 0) ans += mat[i][j];

	printf("%d", ans);
	return 0;
}