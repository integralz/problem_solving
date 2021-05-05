#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, col, maxtime, che = 0, ans;
char roo;
int mat[1500][1500];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0, -1} };
queue <pair< pair <int, int>, int> > que;
vector <pair<int, int> > v;
vector <pair<int, int> > goose;
bool root[1500][1500];

void dfs(int cou) {
	int nx, ny, x, y;
	if (!v.empty()) {
		x = v.back().first;
		y = v.back().second;
		v.pop_back();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && root[nx][ny] == 0 && mat[nx][ny] <= cou) {
				root[nx][ny] = 1;
				if (nx == goose[1].first && ny == goose[1].second) che = 1;
				v.push_back(make_pair(nx, ny));
				dfs(cou);
			}
		}
	}
}

void binary(int a, int b) {
	int qu;
	while (a <= b) {
		qu = (a + b) / 2;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				root[i][j] = 0;
		v.push_back(goose[0]);
		root[goose[0].first][goose[0].second] = 1;
		dfs(qu);
		if (che == 1) {
			che = 0;
			b = qu - 1;
			ans = qu;
		}
		else {
			a = qu + 1;
		}
	}
}

void bfs() {
	int nx, ny, x, y, cou;

	while (!que.empty()) {
		x = que.front().first.first;
		y = que.front().first.second;
		cou = que.front().second + 1;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == -1) {
				mat[nx][ny] = cou;
				que.push(make_pair(make_pair(nx, ny), cou));
			}
		}
	}
	maxtime = cou;
}

int main(void) {
	scanf("%d%d", &row, &col);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%c", &roo);
			if (roo == '\n')
				scanf("%c", &roo);
			if (roo == 'X') {
				mat[i][j] = -1;
			}
			else if (roo == 'L') {
				mat[i][j] = 0;
				que.push(make_pair(make_pair(i, j), 0));
				goose.push_back(make_pair(i, j));
			}
			else {
				mat[i][j] = 0;
				que.push(make_pair(make_pair(i, j), 0));
			}
		}


	bfs();

	binary(0, maxtime);
	printf("%d", ans);
	return 0;
}