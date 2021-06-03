#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int edge, line;
int start;
int visit[20001];
int root[20001];
vector <pair<int, int> > v[20001];
priority_queue <pair<int, int> > que;

void dij() {
	int a, b, hap;

	while (!que.empty()) {
		a = -1 * que.top().first;
		b = que.top().second;
		que.pop();
		if (visit[b] == 0) {
			for (int i = 0; i < v[b].size(); ++i) {
				hap = a + v[b][i].second;
				if (hap < root[v[b][i].first]) {
					root[v[b][i].first] = hap;
					que.push(make_pair(-1 * hap, v[b][i].first));
				}
			}
		}
		visit[b] = 1;
	}
}


int main(void) {
	int a, b, c;
	scanf("%d%d%d", &edge, &line, &start);

	for (int i = 0; i < line; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= edge; ++i) root[i] = 987654321;
	que.push(make_pair(0,start));
	root[start] = 0;
	dij();
	for (int i = 1; i <= edge; ++i) {
		if (root[i] != 987654321)
			printf("%d\n", root[i]);
		else printf("INF\n");
	}
}