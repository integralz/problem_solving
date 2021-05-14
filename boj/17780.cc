#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, num;
int mat[12][12];
vector <pair <pair <int, int>, int> > v;
vector <int> root[12][12];
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

int dfs() {
	int x, y, nx, ny, que, siz;
	for (int i = 0; i < num; ++i) {
		x = v[i].first.first;
		y = v[i].first.second;
		nx = x + dir[v[i].second][0];
		ny = y + dir[v[i].second][1];
		if (root[x][y][0] == i) {
			if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
				if (mat[nx][ny] == 0) {
					for (int j = 0; j < root[x][y].size(); ++j) {
						if (root[x][y][j] == i) {
							que = j;
							break;
						}
					}
					for (int j = que; j < root[x][y].size(); ++j) {
						v[root[x][y][j]].first.first = nx;
						v[root[x][y][j]].first.second = ny;
						root[nx][ny].push_back(root[x][y][j]);
					}
					siz = root[x][y].size();
					for (int j = que; j < siz; ++j)
						root[x][y].pop_back();
					if (root[nx][ny].size() > 3) return 0;
				}
				else if (mat[nx][ny] == 1) {
					for (int j = 0; j < root[x][y].size(); ++j) {
						if (root[x][y][j] == i) {
							que = j;
							break;
						}
					}
					siz = root[x][y].size();
					for (int j = siz - 1; j >= que; --j) {
						v[root[x][y][j]].first.first = nx;
						v[root[x][y][j]].first.second = ny;
						root[nx][ny].push_back(root[x][y][j]);
					}
					for (int j = que; j < siz; ++j)
						root[x][y].pop_back();
					if (root[nx][ny].size() > 3) return 0;
				}
				else {
					nx = x - dir[v[i].second][0];
					ny = y - dir[v[i].second][1];
					if (v[i].second == 0 || v[i].second == 2) ++v[i].second;
					else if (v[i].second == 1 || v[i].second == 3) --v[i].second;
					if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
						if (mat[nx][ny] == 0) {
							for (int j = 0; j < root[x][y].size(); ++j) {
								if (root[x][y][j] == i) {
									que = j;
									break;
								}
							}
							for (int j = que; j < root[x][y].size(); ++j) {
								v[root[x][y][j]].first.first = nx;
								v[root[x][y][j]].first.second = ny;
								root[nx][ny].push_back(root[x][y][j]);
							}
							siz = root[x][y].size();
							for (int j = que; j < siz; ++j)
								root[x][y].pop_back();
							if (root[nx][ny].size() > 3) return 0;
						}
						else if (mat[nx][ny] == 1) {
							for (int j = 0; j < root[x][y].size(); ++j) {
								if (root[x][y][j] == i) {
									que = j;
									break;
								}
							}
							siz = root[x][y].size();
							for (int j = siz - 1; j >= que; --j) {
								v[root[x][y][j]].first.first = nx;
								v[root[x][y][j]].first.second = ny;
								root[nx][ny].push_back(root[x][y][j]);
							}
							for (int j = que; j < siz; ++j)
								root[x][y].pop_back();
							if (root[nx][ny].size() > 3) return 0;
						}
						else;
					}
					else;
				}
			}
			else {
				nx = x - dir[v[i].second][0];
				ny = y - dir[v[i].second][1];
				if (v[i].second == 0 || v[i].second == 2) ++v[i].second;
				else if (v[i].second == 1 || v[i].second == 3) --v[i].second;
				if (nx >= 0 && nx < row && ny >= 0 && ny < row) {
					if (mat[nx][ny] == 0) {
						for (int j = 0; j < root[x][y].size(); ++j) {
							if (root[x][y][j] == i) {
								que = j;
								break;
							}
						}
						for (int j = que; j < root[x][y].size(); ++j) {
							v[root[x][y][j]].first.first = nx;
							v[root[x][y][j]].first.second = ny;
							root[nx][ny].push_back(root[x][y][j]);
						}
						siz = root[x][y].size();
						for (int j = que; j < siz; ++j)
							root[x][y].pop_back();
						if (root[nx][ny].size() > 3) return 0;
					}
					else if (mat[nx][ny] == 1) {
						for (int j = 0; j < root[x][y].size(); ++j) {
							if (root[x][y][j] == i) {
								que = j;
								break;
							}
						}
						siz = root[x][y].size();
						for (int j = siz - 1; j >= que; --j) {
							v[root[x][y][j]].first.first = nx;
							v[root[x][y][j]].first.second = ny;
							root[nx][ny].push_back(root[x][y][j]);
						}
						for (int j = que; j < siz; ++j)
							root[x][y].pop_back();
						if (root[nx][ny].size() > 3) return 0;
					}
					else;
				}
				else;

			}
		}
	}
	return 1;
}

int main(void) {
	int x, y, dire, ans = 0;
	scanf("%d%d", &row, &num);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d", &x, &y, &dire);
		v.push_back(make_pair(make_pair(--x,--y), dire -1));
		root[x][y].push_back(i);
	}
	while (1) {
		++ans;
		x = dfs();
		if (x == 0) break;
		if (ans > 1000) break;
	}
	
	if (ans > 1000) printf("%d", -1);
	else printf("%d", ans);


	return 0;
}