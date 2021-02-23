#include <stdio.h>

int main(void) {
	int a[3];
	int f, s;
	scanf("%d %d %d", a, a + 1, a + 2);

	if (a[1] > a[0]) {
		f = a[0];
		s = a[1];
	}
	else {
		f = a[1];
		s = a[0];
	}
	if (a[2] >= s)
		printf("%d", s);
	else if (a[2] >= f && a[2] <= s)
		printf("%d", a[2]);
	else printf("%d", f);


	return 0;
}