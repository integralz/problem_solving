#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row;
int mat[20][20];
vector <int> team1;
vector <int> team2;
int lim, score1, score2;
int ans = 987654321;
void che() {
	score1 = 0;
	score2 = 0;
	for (int i = 0; i < lim; ++i) {
		for (int j = 0; j < lim; ++j) {
			if (i != j) {
				score1 += mat[team1[i]][team1[j]];
				score2 += mat[team2[i]][team2[j]];
			}
		} 
	}
	if (score1 > score2) {
		if (ans > score1 - score2) {
			ans = score1 - score2;
		}
	}
	else {
		if (ans > score2 - score1) {
			ans = score2 - score1;
		}
	}
}

void dfs(int cou) {
	if (cou == row) {
		che();
	}
	else {
		if (team1.size() < lim) {
			team1.push_back(cou);
			dfs(cou + 1);
			team1.pop_back();
		}
		if (team2.size() < lim) {
			team2.push_back(cou);
			dfs(cou + 1);
			team2.pop_back();
		}
	}
}


int main(void) {
	scanf("%d", &row);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
			scanf("%d", &mat[i][j]);
	lim = row / 2;
	dfs(0);

	printf("%d", ans);
}