#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	long long a, b;
	scanf("%d", &n);
	for(int i =0; i < n; ++i){
		scanf("%lld%lld", &a, &b);
		long long su = a + b;
		printf("%lld\n", min(su / 12, a / 5));
	}
}