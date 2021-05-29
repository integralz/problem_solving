#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, num;
int mat[100][100];
int root[100][100];
vector <pair <int, int> > v[100][100];
queue <pair <int, int> > que;
queue <pair <int, int> > v1;
int ans = 1;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

int dfs() {
	int x, y, nx, ny;
	if (que.empty()) return 1;
	while(!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < v[x][y].size(); ++i) {
			if (mat[v[x][y][i].first][v[x][y][i].second] == 0) {
				mat[v[x][y][i].first][v[x][y][i].second] = 1;
				ans++;
			}
		}
	}
	v1.push({ 0,0 });
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			root[i][j] = 0;
		}
	root[0][0] = 1;
	while (!v1.empty()) {
		x = v1.front().first;
		y = v1.front().second;
		v1.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row && root[nx][ny] == 0) {
				if (mat[nx][ny] == 1) {
					root[nx][ny] = 1;
					v1.push({ nx, ny });
					que.push({ nx, ny });
					mat[nx][ny] = 2;
				}
				else if (mat[nx][ny] == 2) {
					v1.push({ nx, ny });
					root[nx][ny] = 1;
				}
			}
		}
	}
	return 0;
}

int main(void) {
	int a, b, c, d;
	scanf("%d%d", &row, &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		v[a - 1][b - 1].push_back({ c - 1,d - 1 });
	}
	que.push({ 0,0 });
	mat[0][0] = 2;
	while (1) {
		if (dfs()) break;
	}
	printf("%d", ans);
}