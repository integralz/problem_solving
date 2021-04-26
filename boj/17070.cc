#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int row; 
queue <pair <pair <int, int>, int> > que;
int mat[16][16];
int dir[3][2] = { {0,1}, {1,1}, {1,0} };
int ans = 0;
void dfs() {
	int x, y, z,nx, ny;
	while (!que.empty()) {
		x = que.front().first.first;
		y = que.front().first.second;
		z = que.front().second;
		que.pop();
		if (x == row - 1 && y == row - 1) ans++;
		else {
			if (z == 0) {
				for (int i = 0; i < 2; ++i) {
					nx = x + dir[i][0];
					ny = y + dir[i][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < row && mat[nx][ny] == 0) {
						if (i == 1) {
							if (mat[nx - 1][ny] == 0 && mat[nx][ny - 1] == 0) {
								que.push({ {nx,ny}, i });
							}
						}
						else {
							que.push({ {nx, ny}, i });
						}
					}
				}
			}
			else if (z == 1) {
				for (int i = 0; i < 3; ++i) {
					nx = x + dir[i][0];
					ny = y + dir[i][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < row && mat[nx][ny] == 0) {
						if (i == 1) {
							if (mat[nx - 1][ny] == 0 && mat[nx][ny - 1] == 0) {
								que.push({ {nx,ny}, i });
							}
						}
						else {
							que.push({ { nx, ny }, i });
						}
					}
				}
			}
			else {
				for (int i = 1; i < 3; ++i) {
					nx = x + dir[i][0];
					ny = y + dir[i][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < row &&mat[nx][ny] == 0) {
						if (i == 1) {
							if (mat[nx][ny - 1] == 0 && mat[nx - 1][ny] == 0) {
								que.push({ {nx, ny}, i });
							}
						}
						else {
							que.push({ {nx, ny}, i });
						}
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d", &row);
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat[i][j]);
		}
	que.push({ { 0,1 }, 0 });
	dfs();
	printf("%d", ans);
}