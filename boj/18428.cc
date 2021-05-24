#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row; 
int mat[6][6];
vector <pair <int, int> > v;
int ans = 0;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

int che() {
	int x, y, nx, ny;
	for (int i = 0; i < v.size(); ++i) {
		x = v[i].first;
		y = v[i].second;
		for (int j = 0; j < 4; ++j) {
			nx = x + dir[j][0];
			ny = y + dir[j][1];
			while (nx >= 0 && nx < row && ny >= 0 && ny < row) {
				if (mat[nx][ny] == 3) break;
				else if (mat[nx][ny] == 1) return 0;
				nx += dir[j][0];
				ny += dir[j][1];
			}
		}
	}
	return 1;
}

void dfs(int cou, int startx, int starty) {
	if (cou == 3) {
		if (che()) {
			ans = 1;
		}
	}
	else {
		if (ans == 1) return;
		for (int j = starty; j < row; ++j) {
			if (mat[startx][j] == 0) {
				mat[startx][j] = 3;
				dfs(cou + 1, startx, j + 1);
				mat[startx][j] = 0;
			}
		}
		for (int i = startx + 1; i < row; ++i) {
			for (int j = 0; j < row; ++j) {
				if (mat[i][j] == 0) {
					mat[i][j] = 3;
					dfs(cou + 1, i, j + 1);
					mat[i][j] = 0;
				}
			}
		}
	}
}

int main(void) {
	char a;
	scanf("%d", &row);
	for(int i = 0; i < row; ++i)
		for (int j = 0; j< row; ++j) {
			scanf("%c", &a);
			if (a == '\n' || a == ' ') scanf("%c", &a);
			if (a == 'X') {
				mat[i][j] = 0;
			}
			else if (a == 'S') {
				mat[i][j] = 1;
			}
			else {
				v.push_back({ i, j });
				mat[i][j] = 2;
			}
		}
	dfs(0, 0 , 0);
	if (ans == 1) printf("YES");
	else printf("NO");
}