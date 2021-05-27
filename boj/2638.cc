#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, col;
int mat[100][100];
vector <pair <int, int> > v;
queue <pair <int, int> > que;
int dir[4][2] = { {0,1}, {1,0},{-1,0}, {0,-1} };
int ans = 0;

int che() {
	int nx, ny;
	int cou;
	if (v.empty()) return 1;
	ans++;
	for (int i = 0; i < v.size(); ++i) {
		cou = 0; 
		for (int j = 0; j < 4; ++j) {
			nx = v[i].first + dir[j][0];
			ny = v[i].second + dir[j][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == 2)
				++cou;
		}
		if (cou >= 2) {
			que.push(v[i]);
			v.erase(v.begin() + i);
			--i;
		}
	}
	return 0;
}


void dfs() {
	int x, y, nx, ny;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		mat[x][y] = 2;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == 0) {
				mat[nx][ny] = 2;
				que.push({ nx, ny });
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &row, &col);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 1) {
				v.push_back({ i,j });
			}
		}

	for (int i = 0; i < row; ++i) {
		if (mat[i][0] == 0) {
			mat[i][0] = 2;
			que.push({ i, 0 });
		}
		if (mat[i][col - 1] == 0) {
			mat[i][col - 1] = 2;
			que.push({ i, col - 1 });
		}
	}
	for (int i = 0; i < col; ++i) {
		if (mat[0][i] == 0) {
			mat[0][i] = 2;
			que.push({ 0,i });
		}
		if (mat[row - 1][i] == 0) {
			mat[row - 1][i] = 2;
			que.push({ row - 1, i });
		}
	}
	dfs();
	while (1) {
		if (che()) {
			break;
		}
		else {
			dfs();
		}
	}
	printf("%d", ans);
	return 0;
}