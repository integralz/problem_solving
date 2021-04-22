#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd {
	int x, y, di;
};

int row, num;
int mat[12][12];
vector <int> root[12][12];
vector <struct dd> v;
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int ans = 0;

int dfs() {
	int nx, ny, x, y;
	int que;
	int siz;
	for (int i = 0; i < num; ++i) {
		nx = v[i].x + dir[v[i].di][0];
		ny = v[i].y + dir[v[i].di][1];
		x = v[i].x;
		y = v[i].y;
		if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
			if (mat[nx][ny] == 0) {
				for (int j = 0; j < root[x][y].size(); ++j) {
					if (root[x][y][j] == i) {
						que = j;
						break;
					}
				}
				for(int j = que; j < root[x][y].size(); ++j){
					v[root[x][y][j]].x = nx; 
					v[root[x][y][j]].y = ny;
					root[nx][ny].push_back(root[x][y][j]);
				}
				siz = root[x][y].size();
				for (int j = que; j < siz; ++j)
					root[x][y].pop_back();
				if (root[nx][ny].size() >= 4) return 1;
			}
			else if (mat[nx][ny] == 1) {
				for (int j = 0; j < root[x][y].size(); ++j) {
					if (root[x][y][j] == i) {
						que = j;
						break;
					}
				}
				for (int j = root[x][y].size() - 1; j >= que; --j) {
					v[root[x][y][j]].x = nx;
					v[root[x][y][j]].y = ny;
					root[nx][ny].push_back(root[x][y][j]);
				}
				siz = root[x][y].size();
				for (int j = que; j < siz; ++j)
					root[x][y].pop_back();
				if (root[nx][ny].size() >= 4) return 1;
			}
			else {
				if (v[i].di == 0 || v[i].di == 2) v[i].di++;
				else v[i].di--;
				nx = x + dir[v[i].di][0];
				ny = y + dir[v[i].di][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
					if (mat[nx][ny] == 0) {
						for (int j = 0; j < root[x][y].size(); ++j) {
							if (root[x][y][j] == i) {
								que = j;
								break;
							}
						}
						for (int j = que; j < root[x][y].size(); ++j) {
							v[root[x][y][j]].x = nx;
							v[root[x][y][j]].y = ny;
							root[nx][ny].push_back(root[x][y][j]);
						}
						siz = root[x][y].size();
						for (int j = que; j < siz; ++j)
							root[x][y].pop_back();
						if (root[nx][ny].size() >= 4) return 1;
					}
					else if (mat[nx][ny] == 1) {
						for (int j = 0; j < root[x][y].size(); ++j) {
							if (root[x][y][j] == i) {
								que = j;
								break;
							}
						}
						for (int j = root[x][y].size() - 1; j >= que; --j) {
							v[root[x][y][j]].x = nx;
							v[root[x][y][j]].y = ny;
							root[nx][ny].push_back(root[x][y][j]);
						}
						siz = root[x][y].size();
						for (int j = que; j < siz; ++j)
							root[x][y].pop_back();
						if (root[nx][ny].size() >= 4) return 1;
					}
					else continue;
				}
				else continue;
			}
		}
		else {
			if (v[i].di == 0 || v[i].di == 2) v[i].di++;
			else v[i].di--;
			nx = x + dir[v[i].di][0];
			ny = y + dir[v[i].di][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
				if (mat[nx][ny] == 0) {
					for (int j = 0; j < root[x][y].size(); ++j) {
						if (root[x][y][j] == i) {
							que = j;
							break;
						}
					}
					for (int j = que; j < root[x][y].size(); ++j) {
						v[root[x][y][j]].x = nx;
						v[root[x][y][j]].y = ny;
						root[nx][ny].push_back(root[x][y][j]);
					}
					siz = root[x][y].size();
					for (int j = que; j < siz; ++j)
						root[x][y].pop_back();
					if (root[nx][ny].size() >= 4) return 1;
				}
				else if (mat[nx][ny] == 1) {
					for (int j = 0; j < root[x][y].size(); ++j) {
						if (root[x][y][j] == i) {
							que = j;
							break;
						}
					}
					for (int j = root[x][y].size() - 1; j >= que; --j) {
						v[root[x][y][j]].x = nx;
						v[root[x][y][j]].y = ny;
						root[nx][ny].push_back(root[x][y][j]);
					}
					siz = root[x][y].size();
					for (int j = que; j < siz; ++j)
						root[x][y].pop_back();
					if (root[nx][ny].size() >= 4) return 1;
				}
				else continue;
			}
			else continue;
		}
	}
	return 0;
}

int main(void) {
	int a, b, c;
	struct dd d;
	scanf("%d%d", &row, &num);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat[i][j]);
		}

	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		--c;
		d.x = a;
		d.y = b;
		d.di = c;
		v.push_back(d);
		root[a][b].push_back(i);
	}
	while (ans <= 999) {
		if(dfs()) break;
		++ans;
	}
	if (ans == 1000) printf("-1");
	else printf("%d", ans + 1);
}