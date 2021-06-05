#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int bus, num;
vector <pair <int, int> > v[1001];
int root[1001];
int mat[1001];
priority_queue <pair <int, int> > que;

void dij(int a, int b) {
	while (!que.empty()) {
		if (root[que.top().second] == 0) {
			for (int i = 0; i < v[que.top().second].size(); ++i) {
				if (mat[v[que.top().second][i].first] < mat[que.top().second] - v[que.top().second][i].second) {
					mat[v[que.top().second][i].first] = mat[que.top().second] - v[que.top().second][i].second;
					que.push({ mat[v[que.top().second][i].first], v[que.top().second][i].first });
				}
			}
			root[que.top().second] = 1;
		}
		que.pop();
	}
}

int main(void) {
	int a, b, c;
	scanf("%d%d", &bus, &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= bus; ++i)
		mat[i] = -987654321;
	mat[a] = 0;
	que.push({ 0, a });
	dij(a, b);
	printf("%d", -1 *mat[b]);
}