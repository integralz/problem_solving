#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct uu {
	int x, y, co;
};

int ans = 9876;
int row, col;
int mat[8][8];
int dir1[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int dir2[2][2][2] = { {{-1,0}, {1,0} }, { {0,1}, {0,-1} } };
int dir3[4][2][2] = { {{-1,0},{0,1}},{{-1,0},{0,-1}},{{0,-1},{1,0}},{{1,0},{0,1}} }; 
vector <struct uu> v;

void dfs(int cou) {
	int bx, by;
	int nx, ny;
	int che = 0;
	if (cou == v.size()) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (mat[i][j] == 0) ++che;
			}
		}
		if (ans > che) ans = che;
	}
	else {
		bx = v[cou].x;
		by = v[cou].y;
		mat[bx][by]--;
		if (v[cou].co == 1) {
			for (int i = 0; i < 4; ++i) {
				nx = bx + dir1[i][0];
				ny = by + dir1[i][1];
				while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
					mat[nx][ny]--;
					nx += dir1[i][0];
					ny += dir1[i][1];
				}
				dfs(cou + 1);
				nx = bx + dir1[i][0];
				ny = by + dir1[i][1];
				while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
					mat[nx][ny]++;
					nx += dir1[i][0];
					ny += dir1[i][1];
				}
			}
		}
		else if (v[cou].co == 2) {
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					nx = bx + dir2[i][j][0];
					ny = by + dir2[i][j][1];
					while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
						mat[nx][ny]--;
						nx += dir2[i][j][0];
						ny += dir2[i][j][1];
					}
				}
				dfs(cou + 1);
				for (int j = 0; j < 2; ++j) {
					nx = bx + dir2[i][j][0];
					ny = by + dir2[i][j][1];
					while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
						mat[nx][ny]++;
						nx += dir2[i][j][0];
						ny += dir2[i][j][1];
					}
				}
			}
		}
		else if (v[cou].co == 3) {
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 2; ++j) {
					nx = bx + dir3[i][j][0];
					ny = by + dir3[i][j][1];
					while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
						mat[nx][ny]--;
						nx += dir3[i][j][0];
						ny += dir3[i][j][1];
					}
				}
				dfs(cou + 1);
				for (int j = 0; j < 2; ++j) {
					nx = bx + dir3[i][j][0];
					ny = by + dir3[i][j][1];
					while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
						mat[nx][ny]++;
						nx += dir3[i][j][0];
						ny += dir3[i][j][1];
					}
				}
			}
		}
		else if (v[cou].co == 4) {
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					if (i != j) {
						nx = bx + dir1[j][0];
						ny = by + dir1[j][1];
						while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
							mat[nx][ny]--;
							nx += dir1[j][0];
							ny += dir1[j][1];
						}
					}
				}
				dfs(cou + 1);
				for (int j = 0; j < 4; ++j) {
					if (i != j) {
						nx = bx + dir1[j][0];
						ny = by + dir1[j][1];
						while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
							mat[nx][ny]++;
							nx += dir1[j][0];
							ny += dir1[j][1];
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; ++i) {
				nx = bx + dir1[i][0];
				ny = by + dir1[i][1];
				while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
					mat[nx][ny]--;
					nx += dir1[i][0];
					ny += dir1[i][1];
				}
			}
			dfs(cou + 1);
			for (int i = 0; i < 4; ++i) {
				nx = bx + dir1[i][0];
				ny = by + dir1[i][1];
				while (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] != 6) {
					mat[nx][ny]++;
					nx += dir1[i][0];
					ny += dir1[i][1];
				}
			}
		}
		mat[bx][by]++;
	}
}

int main(void) {
	struct uu ch;
	scanf("%d%d", &row, &col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] > 0 && mat[i][j] < 6) {
				ch.x = i;
				ch.y = j;
				ch.co = mat[i][j];
				mat[i][j] = 0;
				v.push_back(ch);
			}
		}
	dfs(0);

	printf("%d", ans);
	
}