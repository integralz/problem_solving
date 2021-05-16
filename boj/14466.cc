#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, num, route;
queue <pair <int, int> > que;
int mat[100][100];
int root[10001];
vector <pair <int, int> > v[100][100];
vector <int> ve;
int k = 0;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int ans = 0;

int che(int x, int y, int nx, int ny) {
	for (int i = 0; i < v[x][y].size(); ++i) {
		if (v[x][y][i].first == nx && v[x][y][i].second == ny)
			return 1;
	}
	return 0;
}

void bfs() {
	int nx, ny, x, y;
	mat[que.front().first][que.front().second] = k;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row && mat[nx][ny] == 0) {
				if (che(x, y, nx, ny)) continue;
				mat[nx][ny] = k;
				que.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void) {
	int x, y, x2, y2;
	scanf("%d%d%d", &row, &num, &route);
	for (int i = 0; i < route; ++i) {
		scanf("%d%d%d%d", &x, &y, &x2, &y2);
		--x;
		--y;
		--x2;
		--y2;
		v[x][y].push_back(make_pair(x2, y2));
		v[x2][y2].push_back(make_pair(x, y));
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if (mat[i][j] == 0) {
				++k;
				que.push(make_pair(i, j));
				bfs();
			}
		}
	}
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &x, &y);
		--x;
		--y;
		++root[mat[x][y]];
	}
	for (int i = 0; i < 10001; ++i) {
		if (root[i] != 0)
			ve.push_back(root[i]);
	}
	for(int i = 0; i < ve.size(); ++i)
		for (int j = i + 1; j < ve.size(); ++j) {
			ans += ve[i] * ve[j];
		}
	printf("%d", ans);
}