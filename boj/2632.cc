#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int want, piz1, piz2;
int mat1[1001], mat2[1001];
vector <int> v1, v2;
int ans = 0;


int main(void) {
	int a, b, q1, q2;
	scanf("%d%d%d", &want, &piz1, &piz2);

	for (int i = 1; i <= piz1; ++i) {
		scanf("%d", &mat1[i]);
		mat1[i] += mat1[i - 1];
	}
	for (int i = 1; i <= piz2; ++i) {
		scanf("%d", &mat2[i]);
		mat2[i] += mat2[i - 1];
	}

	for (int i = 0; i < piz1 + 1; ++i) {
		v1.push_back(mat1[i]);
	}
	for (int i = 1; i < piz1 + 1; ++i) {
		for (int j = i + 1; j < piz1 + 1; ++j) {
			v1.push_back(mat1[j] - mat1[i]);
			if(j <piz1)
			v1.push_back(mat1[piz1] - (mat1[j] - mat1[i]));
		}
	}
	for (int i = 0; i < piz2 + 1; ++i)
		v2.push_back(mat2[i]);
	for(int i = 1; i < piz2 + 1; ++i)
		for (int j = i + 1; j < piz2 + 1; ++j) {
			v2.push_back(mat2[j] - mat2[i]);
			if(j < piz2)
			v2.push_back(mat2[piz2] - (mat2[j] - mat2[i]));
		}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	a = 0;
	b = v2.size() - 1;

	while (a < v1.size() && b >= 0) {
		if (v1[a] + v2[b] > want) {
			--b;
		}
		else if (v1[a] + v2[b] == want) {
			q1 = 0; 
			q2 = 0;
			while (v1[a] == v1[q1 + a]) {
				++q1;
				if (q1 + a == v1.size()) break;
			}
			while (v2[b] == v2[b - q2]) {
				++q2;
				if (b - q2 == -1) break;
			}
			a = q1 + a;
			b = b - q2;
			ans += q1 * q2;
		}
		else {
			++a;
		}
	}
	printf("%d\n", ans);
}