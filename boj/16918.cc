#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col, tim;
int mat[200][200];
vector <pair <int, int> > v;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void bomb() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (mat[i][j] == 0) mat[i][j] = -1;
			else mat[i][j]--;
		}
	}
}

void dfs() {
	int nx, ny;
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			--mat[i][j];
			if (mat[i][j] == -4)
				v.push_back(make_pair(i, j));
		}
	for (int i = 0; i < v.size(); ++i) {
		mat[v[i].first][v[i].second] = 0;
		for (int j = 0; j < 4; ++j) {
			nx = v[i].first + dir[j][0];
			ny = v[i].second + dir[j][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col)
				mat[nx][ny] = 0;
		}
	}
	while (!v.empty()) v.pop_back();
}

int main(void) {
	char a;
	scanf("%d%d%d", &row, &col, &tim);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%c", &a);
			if (a == '\n') scanf("%c", &a);
			if (a == '.')mat[i][j] = 0;
			else mat[i][j] = -2;
		}
	for (int i = 2; i <= tim; ++i) {
		if (i % 2 == 0) {
			bomb();
		}
		else if (i % 2 == 1) {
			dfs();
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			if(mat[i][j] == 0)
			printf(".");
			else printf("O");
		printf("\n");
	}
	return 0;
}