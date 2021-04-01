#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int row, col;
int mat[8][8];
int root[8][8];
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue <pair<int, int> > que;
int ans = 0, cou;
int h;

void che() {
	cou = 0;
	int nx, ny, x, y;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			root[i][j] = mat[i][j];
			if (mat[i][j] == 2)
				que.push(make_pair(i, j));
		}
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && root[nx][ny] == 0){
				root[nx][ny] = 2;
				que.push(make_pair(nx, ny));
			}
		}
	}
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			if (root[i][j] == 0)
				cou++;
		}
	if (cou > ans) {
		ans = cou;
	}
}

void dfs(int k, int cou) {
	int x, y;
	if (cou == 3) {
		che();
	}
	else {
		for (int i = k; i < h; ++i) {
			x = i / col;
			y = i % col;
			if (mat[x][y] == 0) {
				mat[x][y] = 1;
				dfs(i + 1, cou + 1);
				mat[x][y] = 0;
		}
	}
	}

}

int main(void) {
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			scanf("%d", &mat[i][j]);
	h = row * col;
	dfs(0,0);

	printf("%d", ans);
	return 0;
}