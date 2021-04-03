#include <iostream>
#include <cstdio>
using namespace std;

int num;
int mat[11], fix[4], cal[10];
int ans1 = 1987654321, ans2 = -1987654321;

void che() {
	int sum = mat[0];
	for (int i = 0; i < num - 1; ++i) {
		if (cal[i] == 0) {
			sum += mat[i + 1];
		}
		else if (cal[i] == 1) {
			sum -= mat[i + 1];
		}
		else if (cal[i] == 2) {
			sum *= mat[i + 1];
		}
		else {
			sum /= mat[i + 1];
		}
	}
	if (sum > ans2) ans2 = sum;
	if (sum < ans1) ans1 = sum;
}

void dfs(int que) {
	if (que == num - 1) {
		che();
	}
	else {
		for (int i = 0; i < 4; ++i) {
			if (fix[i] > 0) {
				fix[i]--;
				cal[que] = i;
				dfs(que + 1);
				fix[i]++;
			}
		}
	}
}

int main(void) {
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
		scanf("%d", &mat[i]);

	for (int i = 0; i < 4; ++i)
		scanf("%d", &fix[i]);

	dfs(0);

	printf("%d\n%d", ans2, ans1);
	return 0;
}