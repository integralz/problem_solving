#include <iostream>
#include <cstdio>
using namespace std;

int row = 10;
int mat[10][10];
int root[5] = { 5,5,5,5,5 };
int big = 987654321;
int ans = 0;
int que;

void find(int x, int y);

void dfs(int x, int y) {
	for (int i = 4; i >= 0; --i) {
		que = 0;
		if (x + i < row && y + i < row) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k <= i; ++k) {
					if (mat[x + j][y + k] == 1) que++;
					else break;
				}
				if (que % (i + 1) != 0) break;
			}
			if (que == (i + 1)*(i + 1)) {
				root[i]--;
				if (root[i] < 0) {
					root[i]++;
				}
				else {
					for(int j = 0; j <= i; ++j)
						for (int k = 0; k <= i; ++k) {
							mat[x + j][y + k] = 2;
						}
					ans++;
					find(x, y + i + 1);
					root[i]++;
					ans--;
					for(int j = 0; j <= i; ++j)
						for (int k = 0; k <= i; ++k) {
							mat[x + j][y + k] = 1;
						}
				}
			}
		}
		
	}
}

void find(int x, int y) {
	for (int i = y; i < row; ++i) {
		if (mat[x][i] == 1) {
			dfs(x, i);
			return;
		}
	}
	for (int i = x + 1; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if (mat[i][j] == 1) {
				dfs(i, j);
				return;
			}
		}
	}
	if (ans < big) big = ans;
}

int main(void) {
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);

	find(0, 0);
	if (big == 987654321) printf("-1");
	else printf("%d", big);
}