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

int gcd(int a, int b){
    if(b == 0) return a;
    else{
        return gcd(b, a % b);
    }
}
ll gcd1(ll a, ll b){
    if(b == 0) return a;
    else{
        return gcd1(b, a % b);
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> a(n);
    vector <int> b(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    a[0] = v[0];
    b[n - 1] = v[n - 1];
    for(int i = 1; i < n; ++i){
        a[i] = gcd(a[i - 1], v[i]);
    }
    for(int i = n - 2; i >= 0; --i){
        b[i] = gcd(b[i + 1], v[i]);
    }
    ll ans = (ll)b[1];
    for(int i =1; i < n; ++i){
        if(i == n - 1){
            int k = a[i - 1];
            ans = ans * k / gcd1(ans, (ll)k);
        }
        else{
            int k = gcd(a[i - 1], b[i + 1]);
            ans = ans * k / gcd1(ans, (ll)k);
        }
    }
    printf("%lld", ans);
}

int main(void){
    solve();
}


