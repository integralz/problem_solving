#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int num;
int mat[15][2];
int sum, ans = 0;
vector <int> v;

void dfs(int cou) {
	if (cou >= num) {
		sum = 0;
		for (int i = 0; i < v.size(); ++i)
			sum += mat[v[i]][1];
		if (sum > ans) ans = sum;
	}
	else {
		for (int i = cou; i < num; ++i) {
			if (i + mat[i][0] <= num) {
				v.push_back(i);
				dfs(i + mat[i][0]);
				v.pop_back();

			}
			else {
				sum = 0;
				for (int i = 0; i < v.size(); ++i) {
					sum += mat[v[i]][1];
				}
				if (sum > ans) ans = sum;
			}
		}
	}
}

int main(void) {
	scanf("%d", &num);

	for (int i = 0; i < num; ++i)
		for(int j = 0; j < 2; ++j)
			scanf("%d", &mat[i][j]);
	dfs(0);
	printf("%d", ans);

}