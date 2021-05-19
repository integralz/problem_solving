#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, start;
int mat[10][10];
int root[10];
vector <int> v;
int ans = 987654321;
int que = 0;

void dfs(int cou) {
	if (cou == row) {
		que = 0;
		for (int i = 0; i < row - 1; ++i) {
			if (mat[v[i]][v[i + 1]] == 987654321) return;
			else {
				que += mat[v[i]][v[i + 1]];
			}
		}
		if (ans > que) {
			ans = que;
		}
	}
	else {
		for (int i = 0; i < row; ++i) {
			if (root[i] == 0) {
				root[i] = 1;
				v.push_back(i);
				dfs(cou + 1);
				v.pop_back();
				root[i] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &row, &start);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &mat[i][j]);
		}
	for(int i = 0; i< row; ++i)
		for(int j = 0; j < row; ++j)
			for (int k = 0; k < row; ++k) {
				if (mat[j][k] > mat[j][i] + mat[i][k])
					mat[j][k] = mat[j][i] + mat[i][k];
			}

	v.push_back(start);
	root[start] = 1;
	dfs(1);
	printf("%d", ans);
}