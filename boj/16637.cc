#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num;
int mat[10];
int root[10];
char pre[9];
int ma;
vector <int> v;
vector <int> va;
vector <char> f;
int ans = -987654321;

void che() {
	int st;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (f[v[i]] == '+') {
			va[v[i]] += va[v[i] + 1];
		}
		else if (f[v[i]] == '-') {
			va[v[i]] -= va[v[i] + 1];
		}
		else{
			va[v[i]] *= va[v[i] + 1];
		}
		va.erase(va.begin() + v[i] + 1);
		f.erase(f.begin() + v[i]);
	}
	st = va[0];
	for (int i = 1; i < va.size(); ++i) {
		if (f[i - 1] == '+') {
			st += va[i];
		}
		else if (f[i - 1] == '-') {
			st -= va[i];
		}
		else {
			st *= va[i];
		}
	}
	if (st > ans) ans = st;
	while (!va.empty()) va.pop_back();
	while (!f.empty()) f.pop_back();
}

void dfs(int que,int wh, int cou) {
	if (wh == cou){
		for (int i = 0; i < ma; ++i) {
			va.push_back(mat[i]);
			f.push_back(pre[i]);
		}
		va.push_back(mat[ma]);
		che();
	}
	else {
		for (int i = que; i < ma; ++i) {
			if (root[i] == 0) {
				root[i] = 1;
				root[i + 1] = 1;
				v.push_back(i);
				dfs(i + 2, wh + 1, cou);
				v.pop_back();
				root[i] = 0;
				root[i + 1] = 0;
			}
		}
	}
}

int main(void) {
	int a;
	char b;
	scanf("%d", &num);
	for (int i = 0; i < num / 2; ++i) {
		scanf("%d%c", &a, &b);
		mat[i] = a;
		pre[i] = b;
	}
	scanf("%d", &mat[num / 2]);
	a = num / 2 + 1;
	a /= 2;
	ma = num / 2;
	for(int i = 0;i <= a; ++i)
		dfs(0,0,i);
	printf("%d", ans);
	return 0;
}