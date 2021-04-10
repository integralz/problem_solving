#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row;
int num;
vector <pair <int, int> > chi;
vector <pair <int, int> > home;
vector <pair <int, int> > v;
int ans = 987654321;

void che() {
	int g, mi, go =0;
	for (int i = 0; i < home.size(); ++i) {
		mi = 987654321;
		for (int j = 0; j < v.size(); ++j) {
			g = 0;
			if (v[j].first > home[i].first)
				g += v[j].first - home[i].first;
			else
				g += home[i].first - v[j].first;
			if (v[j].second > home[i].second)
				g += v[j].second - home[i].second;
			else
				g += home[i].second - v[j].second;
			if (mi > g) mi = g;

		}
		go += mi;
	}
	if (ans > go) ans = go;
}


void dfs(int que, int cou) {
	if (cou == num) {
		che();
	}
	else {
		for (int i = que; i < chi.size(); ++i) {
			v.push_back(chi[i]);
			dfs(i + 1, cou + 1);
			v.pop_back();
		}
	}
}

int main(void) {
	int a;
	scanf("%d%d", &row, &num);
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j) {
			scanf("%d", &a);
			if (a == 1) {
				home.push_back(make_pair(i, j));
			}
			else if(a == 2) {
				chi.push_back(make_pair(i, j));
			}
		}
	dfs(0,0);
	printf("%d", ans);
}