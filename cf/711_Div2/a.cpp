#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    long long n;
    scanf("%lld", &n);
    ll que = 0;
    while(1){
    ll a = 0;
        ll b = n + que;
    while(b!= 0){
        a += b % 10;
        b /= 10;
    }
    ll ans = gcd(n + que, a);
        if(ans > 1){
    printf("%lld\n", n + que);
            break;
        }
        ++que;
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



