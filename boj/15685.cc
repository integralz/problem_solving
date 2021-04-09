#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num;
int mat[101][101];
vector <int> v[20];
int x, y;
int ans = 0;
int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
void check(int que) {
	int nx, ny;
	mat[x][y] = 1;
	nx = x;
	ny = y;
	for (int i = 0; i < v[que].size(); ++i) {
		nx += dir[v[que][i]][0];
		ny += dir[v[que][i]][1];
		mat[nx][ny] = 1;
	}
}

void dfs(int que, int now, int gen) {
	int len;
	if (now == gen) {
		check(que);
	}
	else {
		len = v[que].size();
		for (int i = len - 1; i >= 0; --i) {
			v[que].push_back((v[que][i] + 1) % 4);
		}
		dfs(que, now + 1, gen);
	}

}


int main(void) {
	int wh, a;
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d%d", &y, &x, &wh, &a);
		v[i].push_back(wh);
		dfs(i, 0, a);
	}
	for(int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j) {
			if (mat[i][j] == 1 && mat[i + 1][j] == 1 && mat[i][j + 1] == 1 && mat[i + 1][j + 1] == 1) {
				++ans;
			}
		}

	printf("%d", ans);
	return 0;
}