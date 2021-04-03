#include <iostream>
#include <cstdio>
using namespace std;

struct robot {
	int x, y, dir;
};

struct robot robot;
int row, col;
int mat[50][50];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int ans = 0;

void order1() {
	mat[robot.x][robot.y] = 2;
}

int order2() {
	int nx, ny;
	for (int i = 0; i < 4; ++i) {
		nx = robot.x + dir[(robot.dir + 3) % 4][0];
		ny = robot.y + dir[(robot.dir + 3) % 4][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == 0) {
			robot.x = nx;
			robot.y = ny;
			robot.dir = (robot.dir + 3) % 4;
			return 1;
		}
		else {
			robot.dir = (robot.dir + 3) % 4;
		}
	}
	nx = robot.x + dir[(robot.dir + 2) % 4][0];
	ny = robot.y + dir[(robot.dir + 2) % 4][1];
	if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
		if (mat[nx][ny] == 1) {
			return 0;
		}
		else {
			robot.x = nx;
			robot.y = ny;
			return 1;
		}
	}
	else return 0;
}

int main(void) {
	int a, b, c;
	scanf("%d %d", &row, &col);
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			scanf("%d", &mat[i][j]);

	robot.x = a;
	robot.y = b;
	robot.dir = c;
	a = 1;
	while (a) {
		order1();
		a = order2();
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (mat[i][j] == 2)
				ans++;
	printf("%d", ans);

	return 0;
}