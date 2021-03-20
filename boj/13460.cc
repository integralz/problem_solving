#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct now {
	int rx, ry, bx, by, cou;
}now;

int row, col;
int mat[10][10];
queue <struct now> que;
int dir[4][2] = { {0,1}, {-1,0}, {1,0}, {0,-1} };

int bfs() {
	int nrx, nry, nbx, nby, cou, rcou, bcou;
	struct now k;
	while (!que.empty()) {
		cou = que.front().cou;
		if (cou >= 10) return -1;
		for (int i = 0; i < 4; ++i) {
			rcou = 0;
			bcou = 0;
			nrx = que.front().rx;
			nry = que.front().ry;
			nbx = que.front().bx;
			nby = que.front().by;
			while (mat[nrx][nry] == '.') {
				nrx += dir[i][0];
				nry += dir[i][1];
				rcou++;
			}
			while(mat[nbx][nby] == '.') {
				nbx += dir[i][0];
				nby += dir[i][1];
				bcou++;
			}
			if (mat[nrx][nry] == 'O') {
				if (mat[nbx][nby] == 'O') continue;
				else {
					return cou + 1;
				}
			}
			else if (mat[nbx][nby] == 'O') continue;
			else {
				nrx -= dir[i][0];
				nry -= dir[i][1];
				nbx -= dir[i][0];
				nby -= dir[i][1];
				if (nrx == nbx && nry == nby) {
					if (rcou > bcou) {
						nrx -= dir[i][0];
						nry -= dir[i][1];
					}
					else {
						nbx -= dir[i][0];
						nby -= dir[i][1];
					}
				}
			}
			if (nrx != que.front().rx || nry != que.front().ry || nbx != que.front().bx || que.front().by != nby) {
				k.rx = nrx;
				k.ry = nry;
				k.bx = nbx;
				k.by = nby;
				k.cou = cou + 1;
				que.push(k);
			}
		}
		que.pop();
	}
	return -1;
}

int main(void){
	int ans;
	struct now g;
	scanf("%d %d", &row, &col);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%c", &mat[i][j]);
			if (mat[i][j] == '\n')
				scanf("%c", &mat[i][j]);
			if (mat[i][j] == 'R') {
				g.rx = i;
				g.ry = j;
				mat[i][j] = '.';
			}
			else if (mat[i][j] == 'B') {
				g.bx = i;
				g.by = j;
				mat[i][j] = '.';
			}
		}
	g.cou = 0;
	que.push(g);
	ans = bfs();
	printf("%d", ans);

	return 0;

}