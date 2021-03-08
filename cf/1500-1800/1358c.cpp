#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 0;
    ans= (ll)(c - a)*(d - b) + 1;
    printf("%lld\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


