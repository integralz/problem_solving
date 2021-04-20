#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, num;
int ans = 987654321;
int root[10];
int gg = 0;
vector <pair <int, int> > virus;
queue <pair <pair <int, int>, int> > q;
int mat1[50][50];
int mat[50][50];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void bfs() {
	int x, y,z, nx, ny, hh = 0, k = 0;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		z = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row && mat[nx][ny] != 1 && mat[nx][ny] != 3) {
				if (mat[nx][ny] == 0) {
					hh++;
					k = z + 1;
				}
				mat[nx][ny] = 3;
				q.push({ { nx, ny }, z + 1 });
			}
		}
	}
	if (hh == gg) {
		if (k < ans) ans = k;
	}
}

void dfs(int now,int que, int cou) {
	if (que == cou) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < row; ++j) {
				mat[i][j] = mat1[i][j];
			}
		}
		for(int i = 0; i < virus.size(); ++i)
			if (root[i] == 1) {
				mat[virus[i].first][virus[i].second] = 3;
				q.push(make_pair(virus[i], 0));
			}
		bfs();
	}
	else {
		for (int i = now; i < virus.size(); ++i) {
			if (root[i] == 0) {
				root[i] = 1;
				dfs(i + 1, que + 1, cou);
				root[i] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &row, &num);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat1[i][j]);
			if (mat1[i][j] == 2) virus.push_back({ i,j });
			else if (mat1[i][j] == 0) ++gg;
		}
	dfs(0,0,num);
	if (ans == 987654321) printf("-1");
	else printf("%d", ans);
	return 0;
}