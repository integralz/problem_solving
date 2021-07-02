#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n, a;
	scanf("%d%d", &n, &a);
	vector <int> v(n);
	for(int i =0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	int ind = 0,q = v[0];
	
	for(int i =0; i < n; ++i){
		if(q > v[i]){
			q = v[i];
			ind = i;
		}
	}
	int ans =0;
	--a;
	ans += (n + a - 2) / a;
	printf("%d", ans);
}