#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int row, ans = 0;
bool root[20][20];
int mat[20][20];
pair <int, int> baby;
int babysiz = 2, midsiz = 0;
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
queue <pair <pair<int, int>, int> > que;
vector <pair <int, int> > v;
bool gg(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}


int bfs() {
	int nx, ny, x, y, siz, kk = 987654321, l;
	que.push(make_pair(baby, 0));
	root[baby.first][baby.second] = 1;

	while (!que.empty() && que.front().second <= kk) {
		x = que.front().first.first;
		y = que.front().first.second;
		siz = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			nx = x + dir[i][0];
			ny = y + dir[i][1];
			if (nx >= 0 && nx < row&& ny >= 0 && ny < row && root[nx][ny] == 0 && mat[nx][ny] <= babysiz) {
				root[nx][ny] = 1;
				que.push(make_pair(make_pair(nx, ny), siz + 1));
				if (mat[nx][ny] != 0 && mat[nx][ny] < babysiz) {
					kk = siz;
					v.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	if (!v.empty()) {
		midsiz++;
		if (midsiz == babysiz) {
			midsiz = 0;
			babysiz++;
		}
		sort(v.begin(), v.end(), gg);
		mat[v.front().first][v.front().second] = 0;
		ans += kk + 1;
		baby.first = v.front().first;
		baby.second = v.front().second;
	}
	else {
		return 0;
	}
	l = v.size();
	for (int i = 0; i < l; ++i)
		v.pop_back();
	l = que.size();
	for (int i = 0; i < l; ++i)
		que.pop();
	return 1;
}

int main(void) {
	scanf("%d", &row);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 9) {
				mat[i][j] = 0;
				baby = make_pair(i, j);
			}
		}
	while (1) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < row; ++j) {
				root[i][j] = 0;
			}
		}
		if (bfs());
		else break;
	}
	printf("%d", ans);

	return 0;
}