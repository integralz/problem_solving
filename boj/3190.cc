#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int row, apple, ch;
int mat[100][100];
queue <pair<int, int> > head;
queue <pair<int, int> > tail;
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int nown = 0, nowe = 0;
int nx = 0, ny = 0, ex = 0, ey = 0;
int ans = 0, eans = 0;

void dfs() {
	while (!head.empty()) {
		ans++;
		if (ans <= head.front().first) {
			nx += dir[nown][0];
			ny += dir[nown][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
				if (mat[nx][ny] == 1) {
					printf("%d", ans);
					return;
				}
				else if (mat[nx][ny] == -1) {
					mat[nx][ny] = 1;
				}
				else {
					mat[nx][ny] = 1;
					mat[ex][ey] = 0;
					ex += dir[nowe][0];
					ey += dir[nowe][1];
					eans++;
					if (eans >= tail.front().first) {
						if (tail.front().second == 0) {
							nowe = (nowe + 1) % 4;
						}
						else {
							nowe = (nowe + 3) % 4;
						}
						tail.pop();
					}
				}
			}
			else {
				printf("%d", ans);
				return;
			}
		}
		else {
			if (head.front().second == 0) {
				nown = (nown + 1) % 4;
			}
			else {
				nown = (nown + 3) % 4;
			}
			head.pop();
			nx += dir[nown][0];
			ny += dir[nown][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
				if (mat[nx][ny] == 1) {
					printf("%d", ans);
					return;
				}
				else if (mat[nx][ny] == -1) {
					mat[nx][ny] = 1;
				}
				else {
					mat[nx][ny] = 1;
					mat[ex][ey] = 0;
					ex += dir[nowe][0];
					ey += dir[nowe][1];
					eans++;
					if (eans >= tail.front().first) {
						if (tail.front().second == 0) {
							nowe = (nowe + 1) % 4;
						}
						else {
							nowe = (nowe + 3) % 4;
						}
						tail.pop();
					}
				}
			}
			else {
				printf("%d", ans);
				return;
			}
		}
	}
	while (1) {
		ans++;
		nx += dir[nown][0];
		ny += dir[nown][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
			if (mat[nx][ny] == 1) {
				printf("%d", ans);
				return;
			}
			else if (mat[nx][ny] == -1) {
				mat[nx][ny] = 1;
			}
			else {
				mat[nx][ny] = 1;
				mat[ex][ey] = 0;
				ex += dir[nowe][0];
				ey += dir[nowe][1];
				eans++;
				if (!tail.empty()) {
					if (eans >= tail.front().first) {
						if (tail.front().second == 0) {
							nowe = (nowe + 1) % 4;
						}
						else {
							nowe = (nowe + 3) % 4;
						}
						tail.pop();
					}
				}
			}
		}
		else {
			printf("%d", ans);
			return;
		}
	}
}

int main(void) {
	int x, y;
	char z;
	scanf("%d %d", &row, &apple);

	for (int i = 0; i < apple; ++i) {
		scanf("%d %d", &x, &y);
		x--; 
		y--;
		mat[x][y] = -1;
	}
	mat[0][0] = 1;
	scanf("%d", &ch);
	for (int i = 0; i < ch; ++i) {
		scanf("%d %c", &x, &z);
		if (z == 'D') y = 0;
		else y = 1;
		head.push(make_pair(x, y));
		tail.push(make_pair(x, y));
	}
	dfs();
}