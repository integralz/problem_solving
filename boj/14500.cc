#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col;
int mat[500][500];
int root[500][500];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0, -1} };
int sum, ans = 0;
vector <pair<int, int> > v;

void other(int x, int y) {
	int nx, ny, co;
	for (int i = 0; i < 4; ++i) {
		co = 0;
		for (int j = 0; j < 4; ++j) {
			if (j == i);
			else {
				nx = x + dir[j][0];
				ny = y + dir[j][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
					co++;
					v.push_back(make_pair(nx, ny));
				}
				else break;
			}
		}
		if (co == 3) {
			sum = 0;
			for (int i = 0; i < 4; ++i)
				sum += mat[v[i].first][v[i].second];
			for (int i = 1; i < 4; ++i)
				v.pop_back();
			if (ans < sum) ans = sum;
		}
		else {
			sum = v.size();
			for (int i = 0; i < sum - 1; ++i)
				v.pop_back();
		}
	}
}


void dfs(int x, int y, int cou) {
	int nx, ny;
	if (cou == 3) {
		sum = 0;
		for (int i = 0; i < 4; ++i) {
			sum += mat[v[i].first][v[i].second];
		}
		if (ans < sum) {
			ans = sum;
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && root[nx][ny] != 1) {
				root[nx][ny] = 1;
				v.push_back(make_pair(nx, ny));
				dfs(nx, ny, cou + 1);
				v.pop_back();
				root[nx][ny] = 0;
			}
		}
	}

}

int main(void) {
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			scanf("%d", &mat[i][j]);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			v.push_back(make_pair(i, j));
			root[i][j] = 1;
			dfs(i, j, 0);
			other(i, j);
			root[i][j] = 0;
			v.pop_back();
		}

	printf("%d", ans);
	return 0;
}