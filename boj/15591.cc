#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, q, a;
bool mat[5001];
vector <pair<int, int> > v[5001];
vector <int> score;
int ans;

void dfs(int st) {
	int k;
	mat[st] = 1;
	for (int i = 0; i < v[st].size(); ++i) {
		k = v[st][i].second;
			if (mat[v[st][i].first] == 0 && k >= a) {
				score.push_back(v[st][i].second);
				if (k >= a) ++ans;
				dfs(v[st][i].first);
				score.pop_back();
			}
		
	}
}

int main(void) {
	int b, c;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &a, &b);
		ans = 0;
		for (int j = 0; j < 5001; ++j)
			mat[j] = 0;
		dfs(b);
		printf("%d\n", ans);
	}
}