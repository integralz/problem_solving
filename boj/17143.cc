#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct shark {
	int r, c, s, d, z;
};

int row, col, num;
int mat[100][100];
vector <struct shark> v;
int ans = 0;

void che(int x, int y, int i) {
	if (mat[x][y] != -1) {
		if (v[mat[x][y]].z > v[i].z) {
			v[i].z = 0;
		}
		else {
			v[mat[x][y]].z = 0;
			mat[x][y] = i;
		}
	}
	else {
		mat[x][y] = i;
	}
}

void go(int x, int y, int s, int d, int i) {
	if (d == 1) {
		if (x - s > 0) {
			x -= s;
			s = 0;
		}
		else if (x - s == 0) {
			s = 0;
			x  = 0;
			d = 2;
		}
		else {
			s -= x;
			x = 0;
			d = 2;
		}
		
	}
	else if (d == 2) {
		if (x + s < row - 1) {
			x += s;
			s = 0;
		}
		else if (x + s == row - 1) {
			s = 0;
			x = row - 1;
			d = 1;
		}
		else {
			d = 1;
			s -= (row - 1 - x);
			x = row - 1;
		}
	}
	else if (d == 3) {
		if (y + s < col - 1) {
			y += s;
			s = 0;
		}
		else if (y + s == col - 1) {
			s = 0;
			y = col - 1;
			d = 4;
		}
		else {
			d = 4;
			s -= (col - 1 - y);
			y = col - 1;
		}
	}
	else {
		if (y - s > 0) {
			y -= s;
			s = 0;
		}
		else if (y - s == 0) {
			d = 3;
			y = 0;
			s = 0;
		}
		else {
			d = 3;
			s -= y;
			y = 0;
		}
	}
	if (s > 0) {
		go(x, y, s, d, i);
	}
	else if (s == 0) {
		v[i].r = x;
		v[i].c = y;
		v[i].d = d;
	}

}

void dfs(int que) {
	int ro = 987654321, qu = -1;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].z == 0) {
			v.erase(v.begin() + i);
			--i;
		}
		else {
			if (v[i].c == que) {
				if (v[i].r < ro) {
					ro = v[i].r;
					qu = i;
				}
			}
		}
	}
	if (qu != -1) {
		ans += v[qu].z;
		v.erase(v.begin() + qu);
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat[i][j] = -1;
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		go(v[i].r, v[i].c, v[i].s, v[i].d, i);
		che(v[i].r, v[i].c, i);
	}
}

int main(void) {
	struct shark sh;
	scanf("%d%d%d", &row, &col, &num);

	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d%d%d", &sh.r, &sh.c, &sh.s, &sh.d, &sh.z);
		if (sh.d == 1 || sh.d == 2) {
			sh.s %= 2 * (row - 1);
		}
		else {
			sh.s %= 2 * (col - 1);
		}
		sh.r--;
		sh.c--;
		v.push_back(sh);
	}
	for (int i = 0; i < col; ++i) {
		dfs(i);
	}
	printf("%d", ans);
}