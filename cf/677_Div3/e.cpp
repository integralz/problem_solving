#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

ll comb(int a, int b){
    ll ans = 1;
    for(int i =1; i <= a; ++i){
        ans *= i;
    }
    for(int i = 1; i <= b; ++i){
        ans /= i;
    }
    for(int i = 1; i <= a - b; ++i){
        ans/= i;
    }
    return ans / 2;
}

int main(void){
    int n;
    scanf("%d", &n);
    ll ans = 0;
    ans += comb(n, (n / 2));
    ll que = 1;
    for(int i =1; i < (n / 2); ++i){
        que *= i;
    }
    for(int i =0; i < 2; ++i){
        ans *= que;
    }
    printf("%lld", ans);
}


