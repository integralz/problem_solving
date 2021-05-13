#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int num, c;
int root[2000];
vector <pair <int, int> > v;
vector <pair<pair <int, int>, int> > mat;

int uni(int a) {
	if (root[a] == a) return a;
	else return root[a] = uni(root[a]);
}

void makeunion(int a, int b) {
	int x, y;
	x = uni(a);
	y = uni(b);

	if (x < y) root[root[y]] = root[x];
	else root[root[x]] = root[y];
}

int checkunion(int a, int b) {
	int x, y;
	x = uni(a);
	y = uni(b);
	if (x == y) return 1;
	else return 0;
}


bool gg(pair<pair <int, int>, int> a, pair<pair <int, int>, int> b) {
	return a.second < b.second;
}

int main(void) {
	int row, col, cou, ans = 0;

	for (int i = 0; i < 2000; ++i)
		root[i] = i;

	scanf("%d%d", &num, &c);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &row, &col);
		v.push_back(make_pair(row, col));
	}
	for(int i = 0; i < num; ++i)
		for (int j = i; j < num; ++j) {
			cou = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
			mat.push_back(make_pair(make_pair(i, j), cou));
		}
	sort(mat.begin(), mat.end(), gg);
	cou = 0;
	for (int i = 0; i < mat.size(); ++i) {
		if (mat[i].second < c) continue;
		else {
			if (!checkunion(mat[i].first.first, mat[i].first.second)) {
				makeunion(mat[i].first.first, mat[i].first.second);
				ans += mat[i].second;
				++cou;
			}
			if (cou == num - 1) {
				printf("%d", ans);
				return 0;
			}
		}
	}
	printf("%d", -1);
	return 0;
}