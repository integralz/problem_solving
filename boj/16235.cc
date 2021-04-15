#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int robot[10][10];
int mat[10][10];
int bunsik[10][10];
int row, num, year;
int dir[8][2] = { {0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1},{1,1},{1,-1}, {-1,1} };
vector <int> v[10][10];


void dfs() {
	int l, q, nx, ny;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			sort(v[i][j].begin(), v[i][j].end());

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			q = v[i][j].size();
			for (int k = 0; k < v[i][j].size(); ++k) {
				if (mat[i][j] - v[i][j][k] >= 0) {
					mat[i][j] -= v[i][j][k];
					++v[i][j][k];
				}
				else {
					q = k;
					break;
				}
			}
			l = v[i][j].size();
			for (int k = q; k < l; ++k) {
				mat[i][j] += v[i][j][k] / 2;
			}
			for (int k = q; k < l; ++k)
				v[i][j].pop_back();
		}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			bunsik[i][j] = 0;
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < v[i][j].size(); ++k) {
				if (v[i][j][k] % 5 == 0) {
					for (int z = 0; z < 8; ++z) {
						nx = i + dir[z][0];
						ny = j + dir[z][1];
						if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
							++bunsik[nx][ny];
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < bunsik[i][j]; ++k)
				v[i][j].push_back(1);
		}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			mat[i][j] += robot[i][j];
}

int main(void) {
	int x, y, z;
	scanf("%d%d%d", &row, &num, &year);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			mat[i][j] = 5;
			scanf("%d", &robot[i][j]);
		}
	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		v[--x][--y].push_back(z);
	}
	for (int i = 0; i < year; ++i) {
		dfs();
	}
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			ans += v[i][j].size();
		}
	printf("%d", ans);

	return 0;
}