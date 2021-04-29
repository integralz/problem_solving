#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num;
int mat[50][9];
vector <int> v;
int root[9];
int st = 0;
int base[3];
int ans = 0;

void che() {
	int out;
	int st = 0;
	int sc = 0;
	for (int j = 0; j < num; ++j) {
		out = 0;
		for (int i = 0; i < 3; ++i)
			base[i] = 0;
		while (1) {
			if (mat[j][v[st]] == 0) {
				++out;
				++st;
				st %= 9;
				if (out == 3) break;
			}
			else if (mat[j][v[st]] == 1) {
				++st;
				st %= 9;
				if (base[2] == 1) ++sc;
				for (int i = 2; i >= 1; --i)
					base[i] = base[i - 1];
				base[0] = 1;

			}
			else if (mat[j][v[st]] == 2) {
				++st;
				st %= 9;
				for (int i = 1; i < 3; ++i) {
					if (base[i] == 1) ++sc;
				}
				base[2] = base[0];
				base[1] = 1;
				base[0] = 0;
			}
			else if (mat[j][v[st]] == 3) {
				++st;
				st %= 9;
				for (int i = 0; i < 3; ++i)
					if (base[i] == 1) ++sc;
				base[2] = 1;
				for (int i = 0; i < 2; ++i)
					base[i] = 0;
			}
			else {
				st++;
				st %= 9;
				for (int i = 0; i < 3; ++i) {
					if (base[i] == 1) {
						++sc;
						base[i] = 0;
					}
				}
				++sc;
			}
		}
	}
	if (sc > ans) {
		ans = sc;
	}
}

void dfs(int que) {
	if (que == 9) {
		che();
	}
	else if (que == 3) {
		v.push_back(0);
		dfs(que + 1);
		v.pop_back();
	}
	else {
		for (int i = 1; i < 9; ++i) {
			if (root[i] == 0) {
				v.push_back(i);
				root[i] = 1;
				dfs(que + 1);
				v.pop_back();
				root[i] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d", &num);
	for(int i = 0; i < num; ++i)
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &mat[i][j]);
		}
	dfs(0);
	printf("%d", ans);
}