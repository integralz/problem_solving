#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int row, col, k;
int mat[100][100];
int ans = 0;
int rqu, cqu;
int root[101];
vector <pair <int, int> > v;

bool dd(pair <int, int> a, pair <int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void dfs(int rque, int cque) {
	int rmax = -1, cmax = -1, k;
	if (rque >= cque) {
		for (int i = 0; i < rque; ++i) {
			for (int j = 0; j < 101; ++j)
				root[j] = 0;
			for (int j = 0; j < cque; ++j) {
				if (mat[i][j] != 0) {
					root[mat[i][j]]++;
					mat[i][j] = 0;
				}
			}
			for (int j = 0; j < 101; ++j) {
				if (root[j] > 0) {
					v.push_back(make_pair(j, root[j]));
				}
			}
			sort(v.begin(), v.end(), dd);
			for (int j = 0; j < v.size(); ++j) {
				if (j >= 50) break;
				else {
					mat[i][2 * j] = v[j].first;
					mat[i][2 * j + 1] = v[j].second;
				}
			}
			k = v.size();
			if (2*k > cmax) cmax = 2*k;
			while (!v.empty()) v.pop_back();
		}
	}
	else {
		for (int i = 0; i < cque; ++i) {
			for (int j = 0; j < 101; ++j)
				root[j] = 0;
			for (int j = 0; j < rque; ++j) {
				if (mat[j][i] != 0) {
					root[mat[j][i]]++;
					mat[j][i] = 0;
				}
			}
			for (int j = 0; j < 101; ++j){
				if (root[j] > 0)
					v.push_back(make_pair(j, root[j]));
			}
			sort(v.begin(), v.end(), dd);
			for (int j = 0; j < v.size(); ++j) {
				if (j >= 50) break;
				else {
					mat[2 * j][i] = v[j].first;
					mat[2 * j + 1][i] = v[j].second;
				}
			}
			k = v.size();
			if (2 * k > rmax) rmax = 2 * k;

			while (!v.empty()) v.pop_back();
		}
	}
	if (rmax != -1) {
		if(rmax <= 100)
			rqu = rmax;
		else rqu = 100;
	}
	else {
		if (cmax <= 100)
			cqu = cmax;
		else cqu = 100;
	}
}

int main(void) {
	scanf("%d%d%d", &row, &col, &k);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &mat[i][j]);
	rqu = 3;
	cqu = 3;
	while (mat[row - 1][col - 1] != k && ans <= 100) {
		ans++;
		dfs(rqu, cqu);
	}
	if (ans == 101) {
		printf("%d", -1);
	}
	else {
		printf("%d", ans);
	}
	return 0;
}