#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int n;
	vector <int> v(11, 0);
	scanf("%d", &n);
	for(int qq = 0; qq < n; ++qq){
		int a;
		scanf("%d", &a);
		++v[a];
	}
	int ans = 0;
	for(int i =0; i < 11; ++i){
		if(v[i] > 0) ++ans;
	}
	if(ans >= 3) printf("YES");
	else printf("NO");
}