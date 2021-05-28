#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, l, w;
int mat[1000];
int ans = 0;
int wei = 0, no = 0, al = 0;
vector <int> v;

int go() {
	if (no >= n) return 1;
	if (mat[no] + wei <= w) {
		v.push_back(0);
		wei += mat[no];
		++no;
	}
	return 0;
}
void mov() {
	for (int i = al; i < v.size(); ++i) {
		++v[i];
	}
	if (v[al] >= l) {
		wei -= mat[al];
		++al;
	}
	++ans;
}

int main(void) {
	scanf("%d%d%d", &n, &l, &w);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &mat[i]);
	}
	while (1) {
		if (go()) {
			ans += (l - v.back() + 1);
			break;
		}
		else {
			mov();
		}
	}
	printf("%d", ans);
}