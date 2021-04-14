#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, lo, hi;
int mat[50][50];
int root[50][50];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
queue <pair<int, int> > que;
vector <pair<int, int> > v;
int ans = 0;
int tot;
int u = 0;

void bfs() {
	int x, y, nx, ny, dif, av, siz;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row && root[nx][ny] == 0) {
				if (mat[x][y] > mat[nx][ny])
					dif = mat[x][y] - mat[nx][ny];
				else dif = mat[nx][ny] - mat[x][y];
				if (dif >= lo && dif <= hi) {
					root[nx][ny] = 1;
					tot += mat[nx][ny];
					v.push_back(make_pair(nx, ny));
					que.push(make_pair(nx, ny));
				}
			}
		}
	}
	siz = v.size();
	av = tot / siz;
	for (int i = siz - 1; i >= 0; --i) {
		mat[v[i].first][v[i].second] = av;
		v.pop_back();
	}
}

void dfs() {
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			root[i][j] = 0;
		}
	u = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if (root[i][j] == 0) {
				que.push(make_pair(i, j));
				v.push_back(make_pair(i, j));
				root[i][j] = 1;
				tot = mat[i][j];
				bfs();
				++u;
			}
		}
	}
}

int main(void) {
	scanf("%d%d%d", &row, &lo, &hi);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);
	while (u != row * row) {
		dfs();
		++ans;
	}
	printf("%d", ans - 1);
	return 0;
}