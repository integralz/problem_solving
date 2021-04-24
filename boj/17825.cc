#include <iostream>
#include <cstdio>
using namespace std;

int step[10];
int mat[4][22], che[4][22];
int root[4][2];
int total = 0;
int big = 0;

void dfs(int coup) {
	int x, y, minus;
	int cou;
	if (coup == 10) {
		if (total > big) {
			big = total;
		}
	}
	else {
		cou = step[coup];
		for (int i = 0; i < 4; i++) {
			x = root[i][0];
			y = root[i][1];
			if (root[i][0] == 0) {
				if (root[i][1] == 5) {
					if (cou <= 3) {
						if (che[1][cou - 1] == 0) {
							total += mat[1][cou - 1];
							root[i][0] = 1;
							root[i][1] = cou - 1;
							che[0][5]--;
							che[1][cou - 1]++;
							dfs(coup + 1);
							che[1][cou - 1]--;
							che[0][5]++;
							root[i][1] = y;
							root[i][0] = x;
							total -= mat[1][cou - 1];
						}
						else continue;
					}
					else {
						if (che[3][cou - 1] == 0) {
							total += mat[3][cou - 1];
							root[i][0] = 3;
							root[i][1] = cou - 1;
							che[0][5]--;
							che[3][cou - 1]++;
							dfs(coup + 1);
							che[3][cou - 1]--;
							che[0][5]++;
							root[i][1] = y;
							root[i][0] = x;
							total -= mat[3][cou - 1];
						}
						else continue;
					}
				}
				else if (root[i][1] == 10) {
					if (cou <= 2) {
						if (che[2][cou - 1] == 0) {
							total += mat[2][cou - 1];
							root[i][0] = 2;
							root[i][1] = cou - 1;
							che[0][10]--;
							che[2][cou - 1]++;
							dfs(coup + 1);
							che[2][cou - 1]--;
							che[0][10]++;
							root[i][1] = y;
							root[i][0] = x;
							total -= mat[2][cou - 1];
						}
						else continue;
					}
					else {
						if (che[3][cou] == 0) {
							total += mat[3][cou];
							root[i][0] = 3;
							root[i][1] = cou;
							che[0][10]--;
							che[3][cou]++;
							dfs(coup + 1);
							che[3][cou]--;
							che[0][10]++;
							root[i][1] = y;
							root[i][0] = x;
							total -= mat[3][cou];
						}
						else continue;
					}
				}
				else if (root[i][1] == 15) {
					if (che[3][cou - 1] == 0) {
						total += mat[3][cou - 1];
						root[i][0] = 3;
						root[i][1] = cou - 1;
						che[3][cou - 1]++;
						che[0][15]--;
						dfs(coup + 1);
						che[0][15]++;
						che[3][cou - 1]--;
						root[i][0] = x;
						root[i][1] = y;
						total -= mat[3][cou - 1];
					}
					else continue;
				}
				else {
					if (root[i][1] + cou <= 20) {
						if (che[root[i][0]][root[i][1] + cou] == 0){
							root[i][1] += cou;
							che[root[i][0]][root[i][1]]++;
							che[x][y] --;
							total += mat[root[i][0]][root[i][1]];
							if (root[i][1] == 20) {
								che[3][6]++;
							}
							dfs(coup + 1);
							if (root[i][1] == 20)
								che[3][6]--;
							total -= mat[root[i][0]][root[i][1]];
							che[x][y]++;
							che[root[i][0]][root[i][1]]--;
							root[i][1] -= cou;

						}
						else continue;
					}
					else if (root[i][1] + cou >= 21) {
						root[i][1] = 21;
						che[x][y]--;
						che[x][21]++;
						dfs(coup + 1);
						che[x][y]++;
						che[x][21]--;
						root[i][1] = y;

					}
					else{
						continue;
					}
				}
			}
			else if (root[i][0] == 1) {
				if (root[i][1] + cou < 3) {
					if (che[x][y + cou] == 0) {
						total += mat[x][y + cou];
						root[i][1] += cou;
						che[x][y + cou]++;
						che[1][y]--;
						dfs(coup + 1);
						che[1][y]++;
						che[x][y + cou]--;
						root[i][1] = y;
						total -= mat[x][y + cou];
					}
					else continue;
				}
				else {
					minus = cou + y;
					if (minus <= 6 && che[3][minus] == 0) {
						total += mat[3][minus];
						root[i][1] = minus;
						root[i][0] = 3;
						che[3][minus]++;
						che[x][y] --;
						if (minus == 6)
							che[0][20]++;
						dfs(coup + 1);
						if (minus == 6)
							che[0][20]--;
						total -= mat[3][minus];
						root[i][1] = y;
						root[i][0] = x;
						che[3][minus]--;
						che[x][y]++;
					}
					else if (minus >= 7) {
						root[i][1] = 7;
						che[x][y]--;
						che[3][7]++;
						dfs(coup + 1);
						che[x][y]++;
						che[3][7]--;
						root[i][1] = y;
					}
					else {
						continue;
					}
				}
			}
			else if (root[i][0] == 2) {
				if (root[i][1] + cou < 2) {
					if (che[2][y + cou] == 0) {
						total += mat[2][y + cou];
						root[i][1] = y + cou;
						che[2][y + cou]++;
						che[2][y]--;
						dfs(coup + 1);
						che[2][y]++;
						che[2][y + cou]--;
						root[i][1] = y;
						total -= mat[2][y + cou];
					}
					else continue;
				}
				else {
					minus = cou + y + 1;
					if (minus <= 6 && che[3][minus] == 0) {
						total += mat[3][minus];
						root[i][0] = 3;
						root[i][1] = minus;
						che[3][minus]++;
						che[x][y]--;
						if (minus == 6)
							che[0][20]++;
						dfs(coup + 1);
						if (minus == 6)
							che[0][20]--;
						che[x][y]++;
						che[3][minus]--;
						root[i][0] = x;
						root[i][1] = y;
						total -= mat[3][minus];
					}
					else if (minus >= 7) {
						root[i][1] = 7;
						che[x][y]--;
						che[3][7]++;
						dfs(coup + 1);
						che[x][y]++;
						che[3][7]--;
						root[i][1] = y;
					}
					else continue;
				}
			}
			else {
				if (y + cou <= 6 && che[3][y + cou] == 0) {
					total += mat[3][y + cou];
					root[i][1] = y + cou;
					che[x][y + cou]++;
					che[x][y]--;
					if (root[i][1] == 6)
						che[0][20]++;
					dfs(coup + 1);
					if (root[i][1] == 6)
						che[0][20]--;
					che[x][y]++;
					che[x][y + cou]--;
					root[i][1] = y;
					total -= mat[3][y + cou];
				}
				else if (y + cou >= 7) {
					root[i][1] = 7;
					che[x][y]--;
					che[3][7]++;
					dfs(coup + 1);
					che[x][y]++;
					che[3][7]--;
					root[i][1] = y;
				}
				else continue;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 10; ++i)
		scanf("%d", &step[i]);
	for (int i = 0; i <= 20; ++i)
		mat[0][i] = 2 * i;
	for (int i = 0; i < 3; ++i) {
		mat[1][i] = 13 + 3 * i;
		mat[3][i] = 28 - i;
	}
	mat[2][0] = 22;
	mat[2][1] = 24;
	che[0][0] = 4;
	for (int i = 0; i < 4; ++i)
		mat[3][i + 3] = 25 + 5 * i;

	dfs(0);
	printf("%d", big);
}