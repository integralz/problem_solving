#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col;
char c[101];
vector <int> mat[100][100];
pair <int, int> jong;
vector <pair <pair <int, int>, int > > v;
int dir[9][2] = { {1,-1}, {1,0}, {1,1}, {0,-1}, {0,0}, {0,1}, {-1,-1}, {-1,0}, {-1,1} };
int ans = 0;
int dfs(int how){
	int siz;
	ans++;
	jong.first += dir[how][0];
	jong.second += dir[how][1];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			while (!mat[i][j].empty()) mat[i][j].pop_back();
		}

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == 1) {
			if (v[i].first.first > jong.first) {
				--v[i].first.first;
			}
			else if (v[i].first.first < jong.first) {
				++v[i].first.first;
			}
			if (v[i].first.second > jong.second) {
				--v[i].first.second;
			}
			else if (v[i].first.second < jong.second) {
				++v[i].first.second;
			}
			if (v[i].first.first == jong.first && v[i].first.second == jong.second) return 1;
			mat[v[i].first.first][v[i].first.second].push_back(i);
		}
	}
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			siz = mat[i][j].size();
			if (siz >= 2) {
				for (int k = 0; k < mat[i][j].size(); ++k) {
					v[mat[i][j][k]].second = 0;
				}
			}
		}
	return 0;
}

int main(void) {
	char a;
	int b;
	scanf("%d%d", &row, &col);

	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			scanf("%c", &a);
			if (a == '\n') scanf("%c", &a);
			if (a == 'R') {
				v.push_back({ { i,j }, 1 });
			}
			else if (a == 'I') {
				jong = { i,j };
			}
		}
	scanf("%c", &a);
	fgets(c, 101, stdin);
	for (int i = 0; i < 101; ++i) {
		if (c[i] == '\n' || c[i] == '\0') break;
		b = c[i] - '1';
		if (dfs(b)) {
			printf("kraj %d", ans);
			return 0;
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == jong.first && j == jong.second) {
				printf("I");
			}
			else {
				if (mat[i][j].size() == 0) {
					printf(".");
				}
				else if (mat[i][j].size() == 1) {
					printf("R");
				}
				else { printf(".");
				}
			}
		}
		printf("\n");
	}
}