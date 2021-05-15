#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num;
int mat[10];
char ca[9];
int half;
vector <int> v1;
vector <char> v2;
bool root[9];
long long ans = -9999999;

void cal(int que) {
	if (v2[que] == '+') {
		v1[que] += v1[que + 1];
	}
	else if (v2[que] == '-') {
		v1[que] -= v1[que + 1];
	}
	else {
		v1[que] *= v1[que + 1];
	}
}

void dfs(int cou) {
	int a,c;
	char b;
	if (cou == half) {
		if (v1[0] > ans) ans = v1[0];
	}
	else {
		for (int i = 0; i < half - cou; ++i) {
			a = v1[i];
			c = v1[i + 1];
			b = v2[i];
			cal(i);
			v1.erase(v1.begin() + i + 1);
			v2.erase(v2.begin() + i);
			dfs(cou + 1);
			v1[i] = a;
			v1.insert(v1.begin() + i + 1, c);
			v2.insert(v2.begin() + i, b);
		}
	}
}

int main(void) {
	scanf("%d", &num);
	half = num / 2;
	for (int i = 0; i < half; ++i)
		scanf("%d%c", &mat[i], &ca[i]);
	scanf("%d", &mat[half]);
	for (int i = 0; i < half; ++i) {
		v1.push_back(mat[i]);
		v2.push_back(ca[i]);
	}
	v1.push_back(mat[half]);
		dfs(0);
		printf("%lld", ans);
		return 0;
}