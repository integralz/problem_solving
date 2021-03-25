#include <iostream>
#include <cstdio>
using namespace std;

int row;
int mat[20][20], root[20][20];
int cou[5];
int big = 0;

void find() {
	int che, no;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			root[i][j] = mat[i][j];

	for (int i = 0; i < 5; ++i) {
		if (cou[i] == 0) {
			for (int j = 0; j < row; ++j) {
				che = 0;
				for (int k = 0; k < row; ++k) {
					if (root[k][j] != 0) {
						no = root[k][j];
						root[k][j] = 0;
						if (root[che][j] == 0) {
							root[che][j] = no;
						}
						else if (root[che][j] == no) {
							root[che][j] *= 2;
							che++;
						}
						else {
							che++;
							root[che][j] = no;
						}
					}
				}
			}
		}
		else if (cou[i] == 1) {
			for (int j = 0; j < row; ++j) {
				che = row - 1;
				for (int k = row -1; k >= 0; --k) {
					if (root[k][j] != 0) {
						no = root[k][j];
						root[k][j] = 0;
						if (root[che][j] == 0) {
							root[che][j] = no;
						}
						else if (root[che][j] == no) {
							root[che][j] *= 2;
							che--;
						}
						else {
							che--;
							root[che][j] = no;
						}
					}
				}
			}
		}
		else if (cou[i] == 2) {
			for (int j = 0; j < row; ++j) {
				che = 0;
				for (int k = 0; k < row; ++k) {
					if (root[j][k] != 0) {
						no = root[j][k];
						root[j][k] = 0;
						if (root[j][che] == 0) {
							root[j][che] = no;
						}
						else if (root[j][che] == no) {
							root[j][che] *= 2;
							che++;
						}
						else {
							che++;
							root[j][che] = no;
						}
					}
				}
			}
		}
		else {
			for (int j = 0; j < row; ++j) {
				che = row - 1;
				for (int k = row -1; k >= 0; --k) {
					if (root[j][k] != 0) {
						no = root[j][k];
						root[j][k] = 0;
						if (root[j][che] == 0) {
							root[j][che] = no;
						}
						else if (root[j][che] == no) {
							root[j][che] *= 2;
							che--;
						}
						else {
							che--;
							root[j][che] = no;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			if (big < root[i][j]) big = root[i][j];
		}
}

void dfs(int co) {
	if (co == 5) {
		find();
	}
	else {
		for (int i = 0; i < 4; i++) {
			cou[co] = i;
			dfs(co + 1);
		}
	}
}

int main(void) {
	scanf("%d", &row);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);

	dfs(0);

	printf("%d", big);

	return 0;
}