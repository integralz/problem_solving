#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int row, col, d;
int mat[15][15];
int root[15][15];
int root1[16][15];
vector <int> v;
queue <pair <pair <int, int>, int> > que;
vector <pair <int, int> > tar;
int dir[3][2] = { {0,-1}, {-1,0}, {0,1} };
int ro, siz;
int ans = 0;

void bfs() {
	int x, y,z, nx, ny;
		while (!que.empty()) {
			if (que.front().second >= d) {
				return;
			}

			x = que.front().first.first;
			y = que.front().first.second;
			z = que.front().second;
			que.pop();
			for (int i = 0; i < 3; ++i) {
				nx = x + dir[i][0];
				ny = y + dir[i][1];
				if (nx >= 0 && nx < ro && ny >= 0 && ny < col && root1[nx][ny] == 0) {
					root1[nx][ny] = 1;
					que.push({ { nx, ny }, z + 1 });
					if (root[nx][ny] == 1) {
						tar.push_back({ nx, ny });
						return;
					}
				}
			}
		}
}

void simu() {
	siz = 0;
	ro = row;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			root[i][j] = mat[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j <= ro; ++j) {
				for (int k = 0; k < col; ++k)
					root1[j][k] = 0;
			}
			que.push({ {ro, v[i]}, 0 });
			root1[ro][v[i]] = 1;
			bfs();
			while (!que.empty()) {
				que.pop();
			}
		}
		for (int i = 0; i < tar.size(); ++i) {
			if (root[tar[i].first][tar[i].second] == 1) {
				root[tar[i].first][tar[i].second] = 0;
				siz++;
			}
		}
		while (!tar.empty()) tar.pop_back();
		--ro;
		if (ro < 0) return;
	}
}

void dfs(int cou, int qu) {
	if (cou == 3) {
		simu();
		if (siz > ans) {
			ans = siz;
		}
	}
	else {
		for (int i = qu; i < col; ++i) {
			v.push_back(i);
			dfs(cou + 1, i + 1);
			v.pop_back();
		}
	}
}

int main(void) {
	scanf("%d%d%d", &row, &col, &d);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			scanf("%d", &mat[i][j]);
	}
	dfs(0, 0);

	printf("%d", ans);
}