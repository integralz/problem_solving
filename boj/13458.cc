#include <iostream>
#include <cstdio>
using namespace std;

int clas;
int head, sub;
int mat[1000000];
long long int cou = 0;

int main(void) {
	scanf("%d", &clas);
	for (int i = 0; i < clas; ++i)
		scanf("%d", &mat[i]);

	scanf("%d %d", &head, &sub);
		for (int i = 0; i < clas; ++i) {
			mat[i] -= head;
		}
		cou += clas;
	for (int i = 0; i < clas; ++i) {
		if (mat[i] > 0) {
			cou += (mat[i] / sub);
			if (mat[i] % sub > 0)
				cou++;
		}
	}
	printf("%lld", cou);
}